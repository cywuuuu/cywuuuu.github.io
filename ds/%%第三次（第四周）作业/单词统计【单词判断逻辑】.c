#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
/* run this program using the console pauser or add your own getch, system("pause") or input loop */
typedef struct word
{
	char s[2000];
	char ss[2000];
	int cnt ; 
} word;
word list[100000];
char line [20000][50000];
int tot;
int num;

int cmp(const void* x,const void *y){
    word *a = (word*)x;
	word *b = (word*)y;
	return strcmp (a->s,b->s);
}

int main(int argc, char** argv) {int i; 
	for( i = 0; i < 10000; i++)
	{
		list[i].cnt = 1;
	}
	
	FILE *in = fopen("article.txt", "r");
	
	while(fgets(line[tot], 20000,in) != NULL)
	{
		char *p = line[tot];
		int lent = strlen(line[tot]);int i;	
		for( i = 0; i < lent; i++) 
		{
			line[tot][i] = tolower(line[tot][i]);
		}
		int flag = 0;
		for( i = 0; i < lent; i++)
		{
			if(flag == 0 && isalpha(line[tot][i]))
			{
				int len = strlen(list[num].s);
				list[num].s[len] = line[tot][i];
				flag = 1;
			}
			else if(flag == 0 && !isalpha(line[tot][i]));
			else if(flag == 1 && isalpha(line[tot][i]))
			{
				int len = strlen(list[num].s);
				list[num].s[len] = line[tot][i];
				flag = 1;
			}
			else
			{
				flag = 0; int j,sg = 0;
				for(j = 0; j < num; j++)
				{
					if(strcmp(list[num].s,list[j].s)==0) 
					{
						sg = 1;//代表可以找到相同的 
						list[j].cnt++;
						memset(list[num].s,0,sizeof(list[num].s));
					}
				}
				if(sg == 0) 
				{
					num++;
				}
			}
			
			
			}	
	
		tot++;
	}
	qsort(list,num,sizeof(list[0]),cmp); 
	int h = 0;
		for(i = 0; i < num; i++)
		{
			printf("%s %d\n",list[i].s,list[i].cnt);
			h += list[i].cnt;
		}//
		//printf("%d", h); 
		fclose(in); 
	return 0;
}
