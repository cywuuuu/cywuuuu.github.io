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
       for(p=str; *p; p++)
              h = MULT*h + *p;
       return h % NHASH;
}

typedef struct node
{
	char s[500];
	struct node *next;
}node;	
node* hashtable[3001];//3001
/* run this program using the console pauser or add your own getch, system("pause") or input loop */
char s[4000][80];
int ind[28];
int main(int argc, char** argv) {
	FILE *dict = fopen("dictionary3000.txt", "r");
	
	char ap = 'a';
	int cnt;int i;
	int tot = 0;
	for(i = 0; i <= 3000; i++)
	{
		hashtable[i] = (node *)malloc(sizeof(node));
		hashtable[i]->next = NULL;
	}
	
	for( i = 0; fscanf(dict, "%s", s[i]) != EOF; i++)
	{
		
		int u = hash(s[i]);
		node *p = hashtable[u];
		while(p->next != NULL)
		{
			p = p->next;
		}
		node* create = (node *)malloc(sizeof(node));
		strcpy(create->s, s[i]);create->next = NULL;
		p->next = create;
		
		//>>>>>>>>>
		if(s[i][0] == ap);
		else if(s[i][0] != ap)
		{
			ind[s[i][0] - 'a'] = i;
			ap = s[i][0];
		}
	}	
	cnt = i;
	for(i = 2; i < 26 ;i++)
	{
		if(ind[i] != 0)
		{
			int j = 1;
			while(ind[i-j] == 0)
			{
				ind[i-j] = ind[i];
				j++;
			}
		}
	}
	

	ind[26] = ind[27] = cnt;
	int type = 0;char wd[80];
	while(scanf("%s%d", wd, &type) != EOF)
	{
		tot = 0;
		if(type == 1)
		{
			for(i = 0; i < cnt; i++)
			{
				if(strcmp(wd,s[i]) < 0) 
				{
					tot++;
					printf("0 %d\n",tot);
					break;
				}
				else if(strcmp(wd,s[i]) == 0)
				{
					tot++;
					printf("1 %d\n",tot);
					break;
				} 
				else
				{
					tot++;
				}
			}
		}
		else if(type == 2)
		{
			int high = cnt, low = 0;
			int mid;
			while(low <= high)
			{
				mid = (high+low)/2;
				
				if(strcmp(s[mid], wd) < 0 ) //s<wd
				{
					low = mid + 1;tot++;
				}
				else if(strcmp(s[mid], wd) > 0)
				{
					high = mid - 1;tot++;
				}
				else
				{
					tot++;
					printf("1 %d\n", tot);
					break;	
				}
			}
			if(low > high) printf("0 %d\n",tot);
		}
		else if(type == 3)
		{
			int high = ind[wd[0]- 'a' + 1] - 1, low = ind[wd[0] - 'a'];
			int mid;
			while(low <= high)
			{
				tot++;
				mid = (high+low)/2;
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
					printf("1 %d\n", tot);
					break;	
				}
			}
			if(low > high) printf("0 %d\n", tot);
		}
		else if(type == 4)
		{
			int u = hash(wd);
			node *p = hashtable[u];
			while(p->next != NULL)
			{
				tot++;
				if(strcmp(p->next->s, wd) == 0) 
				{
					printf("1 %d\n", tot);	
					break;
				}
				p = p->next;
			}
			if(p->next == NULL) printf("0 %d\n", tot); 
			//		
		}
	}
	fclose(dict); 
	return 0;
}
/*
accident 1
accident 2
accident 3
accident 4
accident 2
accident 2
accident 2
wins 1
wins 2
wins 3
wins 4
yes 1
yes 2
yes 3
yes 4

*/

