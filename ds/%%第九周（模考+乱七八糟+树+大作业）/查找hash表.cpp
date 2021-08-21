#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#define NHASH  3001
#define MULT  37

unsigned int hash(char *str)

{
       unsigned int h=0;
       char *p;
       for(p=str; *p!='\0'; p++)
              h = MULT*h + *p;
       return h % NHASH;
}

typedef struct node
{
	char s[500];
	struct node *next;
}node;
/* run this program using the console pauser or add your own getch, system("pause") or input loop */
char s[4000][50];
int ind[28];
int main(int argc, char** argv) {
	FILE *dict = fopen("dictionary3000.txt", "r");
	
	node* hashtable[3002];//3001
	memset(hashtable,0,sizeof(hashtable));
	
	char ap = 'a';
	int cnt;int i;
	int tot = 0;
	for( i = 0; fscanf(dict, "%s", s[i]) != NULL; i++)
	{
		int u = hash(s[i]);
		node *p = hashtable[u];
		while(p != NULL)
		{
			p = p->next;
		}
		p = (node *)malloc(sizeof(node *));
		strcpy(p->s, s[i]);
		
		
		
		if(s[i][0] == ap);
		else 
		{
			ind[s[i][0] - 'a'] = i;
			ap = s[i][0];
		}
	}
	cnt = i;
	ind[26] = ind[27] = cnt;
	int type = 0;char wd[80];
	while(scanf("%s%d", wd, &type) != EOF)
	{
		tot = 0;
		if(type == 1)
		{
			for(i = 0; i < cnt; i++)
			{
				if(wd[0] > s[i][0]) 
				{
					printf("0 %d\n",i);
					break;
				}
				else if(strcmp(wd,s[i]) == 0)
				{
					printf("1 %d\n",i);
					break;
				} 
			}
		}
		else if(type == 2)
		{
			int high = cnt, low = 0;
			int mid = high+mid/2;
			while(low <= high)
			{
				tot++;
				if(strcmp(s[mid], wd) < 0 ) //s<wd
				{
					low = mid + 1;
				}
				else if(strcmp(s[mid], wd) > 0)
				{
					high = mid - 1;
				}
				else
				{
					printf("1 %d", tot);
					break;	
				}
			}
			if(low > high) printf("0 %d", tot);
		}
		else if(type == 3)
		{
			int high = ind[wd[0]- 'a' + 1], low = ind[wd[0] - 'a'];
			int mid = high+mid/2;
			while(low <= high)
			{
				tot++;
				if(strcmp(s[mid], wd) < 0 ) //s<wd
				{
					low = mid + 1;
				}
				else if(strcmp(s[mid], wd) > 0)
				{
					high = mid - 1;
				}
				else
				{
					printf("1 %d", tot);
					break;	
				}
			}
			if(low > high) printf("0 %d", tot);
		}
		else if(type == 4)
		{
			int u = hash(wd);
			node *p = hashtable[u];
			while(p != NULL)
			{
				tot++;
				if(strcmp(p->s, wd) == 0) 
				{
					
					printf("1 %d", tot);	
					break;
				}
				p = p->next;
			}
			if(p == NULL) printf("0 %d", tot); 
			
		}
	}
	return 0;
}
