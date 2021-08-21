#include <stdio.h>
#include <string.h>
#include <stdlib.h>
//#include <time.h>
#define MAX 102400//1024
#define isinstc(s) ((((s) == '.') || ((s) == '?')||((s) == '!'))? (0) : (1))
#define to_lower(x) (((x) >= 'A' && (x) <= 'Z') ? ((x) - 'A' + 'a') : (x))
#define is_alpha(x) (( ((x) >= 'A' && (x) <= 'Z') || ((x) >= 'a' && (x) <= 'z') ) ? (1) : (0))
int trie1[2500][26];//25
int num1[2500];
int trie2[58310][26]; //583
int num2[58310];
int pos1 = 1; int pos2 = 1;
struct juzi
{
	char *s;//1170
	int len;
	int cnt;
}stc[MAX];
char s1[20000], s2[6500000];
char s3[250000];
/*int isinstc(char s)
{
	if(s == '.' || s == '?'||s == '!') return 0;
	else return 1;
}*/
int cmp(const void* x,const void *y){
	struct juzi *b = (struct juzi*)y;
	struct juzi *a = (struct juzi*)x;
	register int i =  b->cnt - a->cnt;
	if(i)
	return i;
else return -1;
}
void insert1(char word[])
{
	int p = 0; 
	for(register int i = 0; word[i]; i++)
	{
		register int u = word[i] - 'a';
		if(trie1[p][u] == 0)
		{
			trie1[p][u] = pos1++;
		}
		p = trie1[p][u];
	}
	num1[p] ++;
}
void insert2(char word[])
{
	register int p = 0; 
	for(register int i = 0; word[i]; i++)
	{
		register int u = word[i] - 'a';
		if(trie2[p][u] == 0)
		{
			trie2[p][u] = pos2++;
		}
		p = trie2[p][u];
	}
	num2[p] ++;
}

int search1 (char word[])//返回出现的频次 
{
	register int p = 0;
	for(register int i = 0; word[i]; i++)
	{
		register int u = word[i] - 'a';
		if(trie1[p][u] == 0) return 0;
		p = trie1[p][u];
	}
	return num1[p]; 
}

int search2 (char word[])//返回出现的频次 
{
	register int p = 0;
	for(register int i = 0; word[i]; i++)
	{
		register int u = word[i] - 'a';
		if(trie2[p][u] == 0) return 0;
		p = trie2[p][u];
	}
	return num2[p]; 
}	
int main(int argc, char** argv) {

//
//clock_t startt,end;
//	startt = clock();
//…calculating…

	FILE *stp = fopen("stopwords.txt", "rb+");//rb
	FILE *art = fopen("article.txt", "rb+");
	FILE *rr = fopen("results.txt","w");
	
//	memset(stc,0,sizeof(stc));
	
	fseek(art,0,SEEK_END);fseek(stp, 0, SEEK_END);
	long long size1 = ftell(stp);long long size2 = ftell(art);
	rewind(stp);rewind(art);

	fread(s1,1,size1,stp);fread(s2,1,size2,art);
	
		register int flag = 0;//非单词区 
		register int cnt = 0;
		char word[400];
		memset(word,'\0', sizeof(word));
		for(register int i = 0; i < size1; i++)
		{
			
				if(is_alpha(s1[i])  && flag == 0)
				{
					flag = 1; word[cnt++] = s1[i]; 
				}
				else if(is_alpha(s1[i])  && flag == 1)//isalpha 返回非0值 为true 
				{
					//flag = 1; 
					word[cnt++] = s1[i];
				}
				else if(is_alpha(s1[i]) == 0 && flag == 1)
				{
					flag = 0;
					word[cnt] = 0;
					insert1(word);//root = ..!!!
					//printf("%s  %d\n", word, search1(word));
				//	memset(word,'\0', sizeof(word));
					cnt = 0;
				}
				//else if(isalpha(s1[i]) == 0 && flag == 0);
		}
		//统计 art里的词频 
		flag = 0;//非单词区 
		cnt = 0;
	//	memset(word,'\0', sizeof(word));
		for(register int i = 0; i < size2; i++)
		{
			
				if(is_alpha(s2[i])  && flag == 0)
				{
					flag = 1; word[cnt++] = to_lower(s2[i]); 
				}
				else if(is_alpha(s2[i])  && flag == 1)//isalpha 返回非0值 为true 
				{
					//flag = 1; 
					word[cnt++] = to_lower(s2[i]);
				}
				else if(is_alpha(s2[i]) == 0 && flag == 1)
				{
					flag = 0;word[cnt] = 0;
					if(search1(word) == 0)
					{
						
						insert2(word);//root = ..!!!
						//printf("%s  %d\n", word, search2(word));
					//	memset(word,'\0', sizeof(word));
						cnt = 0;
					}
					else 
					{
						//memset(word,'\0', sizeof(word));
						cnt = 0;
					}
				}
				//else if(isalpha(s2[i]) == 0 && flag == 0);
		}
		
		//统计句子先 
		flag = 0;
		cnt = 0; 
	//	register int tot = 0;
		register int start = 0;//
		for(register int i = 0; i < size2; i++)
		{
				if(isinstc(s2[i])  && flag == 0)
				{
					flag = 1;start = i;
				}
				/*else if(isinstc(s2[i])  && flag == 1)//isalpha 返回非0值 为true 
				{
					//flag = 1;
				}*/
				else if(isinstc(s2[i]) == 0 && flag == 1)
				{
					flag = 0;
					stc[cnt].s = &s2[start];
					stc[cnt].len = i - start + 1;
				//	strncpy(stc[cnt].s, &s2[start], i - start + 1);
				//	stc[cnt].num = cnt++;
				cnt++;	
				}
				//else if(isinstc(s2[i]) == 0 && flag == 0);
		}
	
		//按句子统计出现频率 
		int totstc = cnt;
		flag = 0;
		cnt = 0; 
	//	memset(word,'\0', sizeof(word));
		for(int j = 0; j < totstc; j++)
		{
			stc[j].cnt = 0;
			for(register int i = 0; i < stc[j].len; i++)
			{
				if(is_alpha(stc[j].s[i])  && flag == 0)
				{
					flag = 1; word[cnt++] = to_lower(stc[j].s[i]); 
				}
				else if(is_alpha(stc[j].s[i])  && flag == 1)//isalpha 返回非0值 为true 
				{
					//flag = 1;
					 word[cnt++] = to_lower(stc[j].s[i]);
				}
				else if(is_alpha(stc[j].s[i]) == 0 && flag == 1)
				{
					flag = 0;
					/*if(strstr(stc[j].s, "Harry could not see why: the hall was quite empty but for themselves") != NULL )
					{
						if(search1(word) == 1)printf("**%s**\n", word);
						}	*/word[cnt] = 0;
					if(search1(word) == 0)
					{	
					
					
						/*if(strstr(stc[j].s, "Harry could not see why: the hall was quite empty but for themselves") != NULL )
						{
							
							printf("%s %d\n", word, search2(word));
						}*/
						
						stc[j].cnt += search2(word);
					//	memset(word,'\0', sizeof(word));
						cnt = 0;
						
					}
					else 
					{
						//memset(word,'\0', sizeof(word));
						cnt = 0;
					}
				}
				else if(is_alpha(stc[j].s[i]) == 0 && flag == 0);
			}
			
		}
//	end = clock();
//	printf("time=%f\n",(double)end-startt/CLK_TCK);
	qsort(stc,	totstc, sizeof(stc[0]), cmp);
	
	int n;	
	for(int i = 0; i < 5; i++)
	{
		int k = 0;
		while(*(stc[i].s+k) == ' ')
		{
			k++;
		}
		k--;
		printf("%d ", stc[i].cnt);
		while(k< stc[i].len)
		{
			k++;
			printf("%c", *(stc[i].s+k));
		}
		
		printf("\n");
	}
	


	scanf("%d", &n);
	int pp = 0;
	for(register int i = 0; i < n; i++)
	{
		/*
		int k = 0;
		while(*(stc[i].s+k) == ' ')
		{
			k++;
		}
		k--;
		printf("%d ", stc[i].cnt);
		while(k< stc[i].len)
		{
			k++;
			printf("%c", *(stc[i].s+k));
		}
		
		printf("\n");
		*/
		int k = 0;
		while(*(stc[i].s+k) == ' ')
		{
			k++;
		}
		k--;
//		fprintf(rr,"%d %s\n", stc[i].cnt, &stc[i].s[k]);
		int cntt = stc[i].cnt;
		int  r = 0;
		char temp[100];
		while (cntt)
		{
			temp[r] = cntt % 10 + '0';
			r++;
			cntt = cntt / 10;
		}
		r--;
		while (r >= 0)
		{
			s3[pp] = temp[r] ;
			r--;pp++;
			
		}

		s3[pp++] = ' ';
		//fprintf(rr,"%d ", stc[i].cnt);
		while(k < stc[i].len)
		{
			k++;
			s3[pp++] = *(stc[i].s+k);
			//fprintf(rr,"%c", *(stc[i].s+k));
			
		}
		s3[pp++] = '\n';	
	//	fprintf(rr,"\n");
	}
	fwrite(s3,sizeof(s3),1,rr);
	fclose(rr);
	fclose(art);
	fclose(stp);
	return 0;
}
