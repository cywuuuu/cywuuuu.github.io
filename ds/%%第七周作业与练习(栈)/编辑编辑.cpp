#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <stdlib.h>
#define MAX 2000
/* run this program using the console pauser or add your own getch, system("pause") or input loop */
typedef struct caozuo
{
	int type;
	int pos;
	int n;
	char s[MAX];
}cz;

typedef struct stack
{
	cz data[MAX/2];
	int top;
}stk;
char dest[MAX];
int m;

void init (stk *q);
int push(stk *q, cz *a);
int pop(stk *q, cz *a);
void insert (char *str, char *dest, int n);//从零数 
void del(char *dest, int pos, int n);

int main(int argc, char** argv) {
	stk *a = (stk*)malloc(sizeof(stk));
	init(a);
	gets(dest);
	scanf("%d", &m);
	int type, pos, n;
	char s[1000]; //操作小字符串 
	while(m--)
	{
		cz *tmp = (cz*)malloc(sizeof(cz));
		scanf("%d%d%s", &tmp->type, &tmp->pos, tmp->s);
		tmp->type = 3 - tmp->type;
		tmp->n = strlen(tmp->s);
		push(a, tmp);
	}
	while(scanf("%d", &type) != NULL)
	{
		if(type == 1)
		{	
			cz *tmp = (cz*)malloc(sizeof(cz));
			scanf("%d%s", &pos, tmp->s);
			n = strlen(tmp->s);
			insert(tmp->s,dest, pos);// op1
			tmp->n = n; tmp->type = 2; tmp->pos = pos;
			push(a, tmp);
		}
		if(type == 2)
		{
			cz *tmp = (cz*)malloc(sizeof(cz));
			scanf("%d%d", &pos, &n);
			strncpy(tmp->s, dest+pos, n);
			del(dest,pos, n);// op1
			tmp->n = strlen(tmp->s); tmp->type = 1; tmp->pos = pos;
			push(a, tmp);
		}
		if(type == 3)
		{
			cz *tmp = (cz*)malloc(sizeof(cz));
			pop(a, tmp);
			if(tmp->type == 1)
			{
				insert(tmp->s, dest, tmp->pos);
			}
			if(tmp->type == 2)
			{
				del(dest, tmp->pos, tmp->n);
			}
		}
		if(type == -1) break;
	}
	puts(dest);
	return 0;
}
void init (stk *q)
{
	memset(q->data,0,MAX/2*sizeof(cz));
	q->top = -1;
}

int push(stk *q, cz *a)
{
	if(q->top == MAX -1) return -1;
	q->data[++q->top] = *a;
	return 1;
}
int pop(stk *q, cz *a)
{
	if (q->top == -1 ) return -1;
	*a = q->data[q->top--];
	return 1;
}
void insert (char *str, char *dest, int pos)//从零数 
{
	int lens = strlen(str);
	int lend = strlen(dest);
	for(int i = lens + lend - 1; i >= pos + lens; i--)
	{
		dest[i] = dest[i-lens]; 
	}
	for(int i = pos; i < pos + lens; i++ )
	{
		dest[i] = str[i-pos];
	}
}
void del(char *dest, int pos, int n)
{
	int len = strlen(dest);
	for(int i = pos; i < len; i++)
	{
		dest[i] = dest[i+n];
	}
}
