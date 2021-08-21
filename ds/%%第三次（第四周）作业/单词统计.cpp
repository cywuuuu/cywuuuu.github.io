#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
/* run this program using the console pauser or add your own getch, system("pause") or input loop */
typedef struct word
{
	char s[1000];
	char ss[1000];
	int cnt ; 
} word;
word list[10000];
char line [20000][5000];
int tot;
int num;
int cmp(const void* x,const void *y){
    word *a = (word*)x;
	word *b = (word*)y;
	return strcmp (a->ss,b->ss);
}
int main(int argc, char** argv) {
	for(int i = 0; i < 10000; i++)
	{
		list[i].cnt = 1;
	}
	FILE *in = fopen("article.txt", "r");
	while(fgets(line[tot], 20000,in) != NULL)
	{
		char *p = line[tot];
		int lent = strlen(line[tot]);
		line[tot][lent-1] = '\0'; 
		int flag = 0;
		while(*p != '\0')
		{
			//flag = 1 时前面为单词区 
			if(flag == 1 && isalpha(*p))
			{
				int len = strlen(list[num].s);
				list[num].s[len] = *p;
				list[num].ss[len] = tolower(*p);
			}
			//flag = 1 单词区 却 不是字母 就要结束单词区 
			else if(flag == 1 && !isalpha(*p))
			{
				flag = 0;
				int sig = 1;
				for(int i = 0; i < num; i++)
				{
					if(strcmp(list[i].s, list[num].s) == 0) 
					{
						sig = 0;
						list[i].cnt++;
						memset(list[num].s,'\0',900); 
						memset(list[num].ss,'\0',900);
						break;
					}
				}
				if(sig == 1)
				{
					num++;
				}
			}
			//进入单词区 
			if(flag == 0&& isalpha(*(p+1)))
			{
				flag = 1;
			}
			p++;
		}
		tot++;
	}
	qsort(list,num,sizeof(list[0]),cmp); 
		for(int i = 0; i < num; i++)
		{
			printf("%s %d\n",list[i].s,list[i].cnt );
		}//
	
	return 0;
}
