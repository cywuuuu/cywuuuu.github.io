//文件压缩-Huffman实现
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAXSIZE 32

struct tnode {					//Huffman树结构
	char c;		
	int weight;					//树节点权重，叶节点为字符和它的出现次数
	struct tnode *left,*right;
} ; 
int Ccount[128]={0};			//存放每个字符的出现次数，如Ccount[i]表示ASCII值为i的字符出现次数 
struct tnode *Root=NULL; 		//Huffman树的根节点
char HCode[128][MAXSIZE]={{0}}; //字符的Huffman编码，如HCode['a']为字符a的Huffman编码（字符串形式） 
int Step=0;						//实验步骤 
FILE *Src, *Obj;
	
void statCount();				//步骤1：统计文件中字符频率
void createHTree();				//步骤2：创建一个Huffman树，根节点为Root 
void makeHCode();				//步骤3：根据Huffman树生成Huffman编码
void atoHZIP(); 				//步骤4：根据Huffman编码将指定ASCII码文本文件转换成Huffman码文件

void print1();					//输出步骤1的结果
void print2(struct tnode *p);	//输出步骤2的结果 
void print3();					//输出步骤3的结果
void print4();					//输出步骤4的结果

int main()
{
	if((Src=fopen("input.txt","r"))==NULL) {
		fprintf(stderr, "%s open failed!\n", "input.txt");
		return 1;
	}
	if((Obj=fopen("output.txt","w"))==NULL) {
		fprintf(stderr, "%s open failed!\n", "output.txt");
		return 1;
	}
	scanf("%d",&Step);					//输入当前实验步骤 
	
	statCount();						//实验步骤1：统计文件中字符出现次数（频率）
	(Step==1) ? print1(): 1; 			//输出实验步骤1结果	
	createHTree();						//实验步骤2：依据字符频率生成相应的Huffman树
	(Step==2) ? print2(Root): 2; 		//输出实验步骤2结果	
	makeHCode(Root);					//实验步骤3：依据Root为树的根的Huffman树生成相应Huffman编码
	(Step==3) ? print3(): 3; 			//输出实验步骤3结果
	(Step>=4) ? atoHZIP(),print4(): 4; 	//实验步骤4：据Huffman编码生成压缩文件，并输出实验步骤4结果	

	fclose(Src);
	fclose(Obj);

    return 0;
} 

//【实验步骤1】开始 

void statCount()
{
	char line[500];
	while(fgets(line, 500, Src) != NULL)
	{
		int len = strlen(line);int i;
		for(i = 0; i < len; i++)
		{
			if(line[i] != '\0')
			Ccount[line[i]]++;
		}
	 } 

	
	Ccount[0] = 1;
	rewind(Src);
}

//【实验步骤1】结束

//【实验步骤2】开始

void createHTree()
{
	struct tnode *m[200];
	memset(m, 0, sizeof(m));
	int tot = 0;int i , j , k, ww;
	for( i = 0; i < 128; i++)
	{
		if(Ccount[i] > 0)
		{
			m[tot] = (struct tnode *) malloc( sizeof(struct tnode));
			m[tot]->c = i;
			m[tot]->weight = Ccount[i];
			m[tot]->left = m[tot]->right = NULL;
			tot++;
		}
	}
	struct tnode *tmp = NULL;
	for(i = 0; i < tot; i++)
	{
		for(j = 0; j < tot - 1; j++)
		{
			if(m[j]->weight > m[j+1]->weight ||(m[j]->weight == m[j+1]->weight && m[j]->c > m[j+1]->c))
			{
				tmp = m[j];
				m[j] = m[j+1];
				m[j+1] = tmp;
			}
			
		}
	
	}	
/*	for( ww = 0; ww < tot; ww++)
		{	if(m[ww] != NULL)
			printf("%d: %c %d\n",ww,m[ww]->c,m[ww]->weight);
		}
		printf("******************************************************\n");*/
	for(k = 0; k < tot - 1; k++)
	{
		struct tnode *tmp = (struct tnode*) malloc(sizeof(struct tnode));
		tmp->c = 127;
		tmp->weight = m[k]->weight + m[k+1]->weight;
		tmp->left = m[k];tmp->right = m[k+1];
		Root = m[k+1] = tmp;
		
		m[k] = NULL;
		int flag = 0;
		for( i = k+1; i < tot; i++)
		{
			for( j = k+1; j < tot - 1; j++)
			{
				if(m[j]->weight > m[j+1]->weight ||(m[j]->weight == m[j+1]->weight && m[j]->c > m[j+1]->c))
				{
					tmp = m[j];
					m[j] = m[j+1];
					m[j+1] = tmp;
				}
				else if((m[j]->weight == m[j+1]->weight && m[j]->c == m[j+1]->c)&& flag == 0)
				{
					tmp = m[j];
					m[j] = m[j+1];
					m[j+1] = tmp;
				}
			}	flag = 1;
		}
		
		/*for( ww = 0; ww < tot; ww++)
		{	
			if(m[ww] != NULL)
			{
				printf("%d: %c %d",ww,m[ww]->c,m[ww]->weight);	
				if(m[ww]->c == 127)
				{
					printf("////");print2(m[ww]);printf("////\n");
				}
				else printf("\n");
			}
			
			
		
		}*/
		//printf("******************************************************\n");
	}
	
	
}

//【实验步骤2】结束

//【实验步骤3】开始
void visitHtree(struct tnode *root, char path[], int wh)
{
	if(root->left == NULL && root->right == NULL)
	{
		strcpy(HCode[root->c], path);
		path[wh] = '\0';
		return;
	}
	path[wh] = '0';
	visitHtree(root->left, path, wh+1);
	path[wh] = '\0';
	path[wh] = '1';
	visitHtree(root->right, path, wh+1);
	path[wh] = '\0';
}

void makeHCode()
{
	char path[2000];
	memset(path,0,sizeof(path));
	visitHtree(Root, path, 0);
	
} 

//【实验步骤3】结束

//【实验步骤4】开始

void atoHZIP()
{
	//rewind(Src);
	char s[50000];
	memset(s, 0, sizeof(s));
	char line[3000];
	while(fgets(line,3000,Src) != NULL)
	{
		int len = strlen(line);int i;
		for( i = 0; i <= len; i++)
		{
			strcat(s,HCode[line[i]]);
		}
	}
	int hc = 0;int i;
	int lens = strlen(s);
	for(i = 0; i < lens; i++)
	{
		hc = (hc << 1) + (s[i]-'0');
		
		if((i+1)%8 == 0)
		{
		
			fputc(hc, Obj);
			printf("%x", hc);	
			//printf("%8s\n",&s[i-7]);
			hc = 0;
		}
	}
	return;
	
}

//【实验步骤4】结束

void print1()
{
	int i;
	printf("NUL:1\n");
	for(i=1; i<128; i++)
		if(Ccount[i] > 0)
			printf("%c:%d\n", i, Ccount[i]);
}

void print2(struct tnode *p)
{
	if(p != NULL){
		if((p->left==NULL)&&(p->right==NULL)) 
			switch(p->c){
				case 0: printf("NUL ");break;
				case ' ':  printf("SP ");break;
				case '\t': printf("TAB ");break;
				case '\n':  printf("CR ");break;
				default: printf("%c ",p->c); break;
			}
		print2(p->left);
		print2(p->right);
	}
}

void print3()
{
	int i;
	
	for(i=0; i<128; i++){
		if(HCode[i][0] != 0){
			switch(i){
				case 0: printf("NUL:");break;
				case ' ':  printf("SP:");break;
				case '\t': printf("TAB:");break;
				case '\n':  printf("CR:");break;
				default: printf("%c:",i); break;
			}
			printf("%s\n",HCode[i]);
		}
	}
} 

void print4()
{
	long int in_size, out_size;
	
	fseek(Src,0,SEEK_END);
	fseek(Obj,0,SEEK_END);
	in_size = ftell(Src);
	out_size = ftell(Obj);
	
	printf("\n原文件大小：%ldB\n",in_size);
	printf("压缩后文件大小：%ldB\n",out_size);
	printf("压缩率：%.2f%%\n",(float)(in_size-out_size)*100/in_size);
}
