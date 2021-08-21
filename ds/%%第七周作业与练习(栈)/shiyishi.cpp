#include <stdio.h>
#include <stdlib.h>
#define MAX 4000000
int h[MAX];
int result[MAX];
/* run this program using the console pauser or add your own getch, system("pause") or input loop */
typedef struct 
{
	int ind[MAX];
	int top;
}stk;
void init(stk *q)
{
	q->top = -1;
}
int push(stk *q, int a)
{
	if(q->top == MAX-1) return -1;
	q->ind[++q->top] = a;
	return 1;
}
int pop(stk *q)
{
	int tmp = q->ind[q->top--];
	return tmp;
}
int isempty(stk *q)
{
	if(q->top == -1) return 1;
	else return 0;
}
int main(int argc, char** argv) {
	stk *a = (stk*) malloc (sizeof(stk));
	init(a);
	int n;
	scanf("%d", &n);
	for(int i = 0; i < n; i ++)
	{
		scanf("%d", &h[i]);
	}
	for(int i = n-1; i>=0; i--)
	{
		while(!isempty(a) && h[i] > h[a->ind[a->top]] ) 
		{
			pop(a);
		}
		if(isempty(a)) result[i] = 0;
		else result[i] = a->ind[a->top]+1;
		push(a, i);
	}
	for(int i = 0; i < n; i++)
	{
		printf("%d ", result[i]);
	}
	return 0;
}
