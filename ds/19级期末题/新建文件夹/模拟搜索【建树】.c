#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
/* run this program using the console pauser or add your own getch, system("pause") or input loop */
typedef struct node
{
	int date;
	char name[100];
	int type;
	int chnum;
	int depth;
	struct node* ch[120];
}node;
int date,type;
char name[100];	char pre[100];
//建议开全局 保存新节点数据,在建树中搞他 
//建议采用返回值建树法 
	char ss[100];
typedef struct result
{
	char path[100];
	int date;
	int depth;
}result;
result path[100];
char ans[300];
int tot = 0;
int cmp(const void *x, const void *y)
{
	result *a = (result *)x;
	result *b = (result *)y;
	int i = b->date - a->date;
	if(i)
	return i;
	else 
	return a->depth - b->depth;
}
int depth = 0;
node* insert(char s[], node* root)
{
	
	if(strcmp(s,"-")==0)//对于根节点特判 
	{
		root = (node *)malloc(sizeof(node));
		root->chnum = 0;
		root->date = date;
		strcpy(root->name, name);
		root->type = type;
		root->depth = 0;
		memset(root->ch,0,sizeof(root->ch));
		return root;
	}
	else if(strcmp(s,root->name)==0)
	{
		node *a = (node *)malloc(sizeof(node));
		a->chnum = 0;
		a->date = date;
		strcpy(a->name, name);
		a->type = type;
		a->depth = depth+1;
		memset(a->ch,0,sizeof(a->ch));
		root->ch[root->chnum++] = a;
		return root;
	}
	else 
	{
		for(int i = 0; i < root->chnum; i++)
		{
			if(root->ch[i]!=NULL && root->ch[i]->type == 1)
			{
				depth = root->depth;
				insert(s, root->ch[i]);
				depth = root->depth;
			}
		}
		return root;
	}
 } 
 int flag = 0;
void search(node *root)
{

		int len2 = strlen(ans);
		
		if (flag == 1)
		{
			strcat(ans,"\\");
		}
		strcat(ans, root->name);
		if(flag == 0)
		{
			strcat(ans,":");
			flag++;
		}
		
		for(int i = 0; i < root->chnum; i++)
		{
			if(root->ch[i]!=NULL)
			{
				if(root->ch[i]->type == 0&&strcmp(root->ch[i]->name, ss)==0)
				{
					strcat(ans,"\\");
					strcat(ans,root->ch[i]->name);
					path[tot].date = root->ch[i]->date;
					path[tot].depth = root->ch[i]->depth;
					strcpy(path[tot++].path, ans);
				}
				if(root->ch[i]->type == 1)
				{
					search(root->ch[i]);
				}
			}
			
		}
		ans[len2] = '\0';
	
}
int main(int argc, char** argv) {

//	FILE *fp = fopen("file.txt","r");
//	fclose(fp);
	node* root;
	
	int n;
	scanf("%d%s", &n,ss);
	for(int i = 0; i < n; i++)
	{
		scanf("%s%s%d%d",name,pre,&type,&date);
		root = insert(pre,root);

	}
	search(root);
	qsort(path, tot, sizeof(path[0]), cmp);
	for(int i = 0 ; i < tot; i++)
	{
		printf("%s\n", path[i].path);
	}
	
	return 0;
}
/*
49 test.c
D - 1 20190101
MyDoc D 1 20190101
win D 1 20190101
test.c D 0 20190901
work MyDoc 1 20190101
2018 work 1 20190102
plan.doc 2018 0 20190202
date.doc 2018 0 20190305
2019 work 1 20190103
test.c work 0 20190901
test.obj work 0 20190902
sun.jpg 2019 0 20190405
report.ppt 2018 0 20190306
test MyDoc 1 20190103
music MyDoc 1 20190103
temp MyDoc 1 20190103
moon.mp3 music 0 20190607
thesky.mp3 music 0 20190701
moon.jpg 2019 0 20190506
test.c 2019 0 20190901
apologize.mp3 music 0 20190702
test.c 2018 0 20190901
natural.mp3 music 0 20190702
world.exe win 0 20190101
dev.exe win 0 20190102
course temp 1 20190505
mon.exl temp 0 20190505
wel.ppt temp 0 20190605
math course 1 20190506
lang course 1 20190607
one math 1 20190507
test.c lang 0 20190925
graph.c lang 0 20190926
two math 1 20190508
three math 1 20190508
test.c math 0 20190926
prog one 1 20190609
data one 1 20190610
sum three 1 20190509
test.c three 0 20190901
in.dat three 0 20190902
input.txt prog 0 20190809
output.txt prog 0 20190827
test.c prog 0 20190901
test.exe prog 0 20190901
save data 1 20190611
test.exe data 0 20190612
in.txt data 0 20190612
out.dat three 0 20190902
*/
