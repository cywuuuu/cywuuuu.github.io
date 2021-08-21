#include <stdio.h>
#include <string.h>
#include <stdlib.h>
/* run this program using the console pauser or add your own getch, system("pause") or input loop */
#define MAX 10000
typedef struct 
{
	char num[10];
	int dis;
	char s[300];
}train;
typedef struct
{
	train data[500];
	int top;
}stk;
struct aaa 
{
	int dis;
	char s[300];
}distable[500];
int cnt = 0;
void init (stk *q);
int pop(stk *q, train *a);
int push(stk *q, train *a);
int main(int argc, char** argv) {
	stk *a = (stk*)malloc(sizeof(stk));
	stk *b = (stk*)malloc(sizeof(stk));
	stk *c = (stk*)malloc(sizeof(stk));
	init(a);init(b);init(c);
	int m,n;train *tmp = (train *)malloc(sizeof(train));
	scanf("%d", &m);
	for(int i = 0; i < m; i++)
	{
		scanf("%s%d", distable[i].s, &distable[i].dis);
	}
	scanf("%d", &n);
	for(int i = 0; i < n; i++)
	{
		scanf("%s%s", &tmp->num, tmp->s);
		for(int j = 0; j < m; j++)
		{
			if(strcmp(distable[j].s,tmp->s) == 0)
			{
				tmp->dis = distable[j].dis;
				break;
			}
		}
		push(a,tmp);
	}
	//step 1
	for(int i = 0; i < n; i++)
	{
		pop(a,tmp);
		push(b,tmp);	
	}
	//step 2-3
	while(b->top != -1)
	{
		int where;
		for(int i = 0; i <= b->top; i++)
		{
			int dismax = -1;
			if(dismax < b->data[i].dis)
			{
				where = i;
			}
		}
		for(int i = where; i <= b->top; i++)
		{
			pop(b,tmp);
			push(a,tmp); cnt++;
		}
		int flag = 0;int last = 0;
		for(int i = a->top-1; i >= 0; i--)
		{
			if(a->data[a->top].dis > a->data[i].dis)
			{
				flag = 1;
				last = i;
			}
		}
		if(flag == 1)//未完全编好组 
		{
			pop(a,tmp);
			push(c,tmp);
			int zanshitot = a->top;
			for(int i = zanshitot; i >= last; i--)
			{
				pop(a,tmp);
				push(b,tmp);
			}
			pop(c,tmp);
			push(a,tmp);cnt++; 
		}
		
		
	}
	for(int i = 0; i <= a->top; i++)
	{
		printf("%s ", a->data[i].num);
	}
	printf("\n%d",cnt);
	
	
	return 0;
}
void init (stk *q)
{
	q->top = -1;
}
int pop(stk *q, train *a)
{
	if(q->top == -1) return -1;
	*a = q->data[q->top--];
	return 1;
}
int push(stk *q, train *a)
{
	if(q->top == MAX-1) return -1;
	q->data[++q->top] = *a;
	return 1;
}

