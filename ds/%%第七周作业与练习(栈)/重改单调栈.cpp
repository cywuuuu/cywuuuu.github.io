#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#define MAX 40000000
int n, h[MAX], stk[MAX], result[MAX], top;
int main()
{
	scanf("%d", &n);
	for(int i = 1; i <= n; i ++)
	{
		scanf("%d", &h[i]);
	}
	for(int i = n; i >= 1; i--)
	{
		while(h[i] > h[stk[top]] && top > 0) top--;
		result[i] = stk[top]; 
		stk[++top] = i;
	}
	for(int i = 1; i <= n; i++)
	{
			printf("%d ", result[i]);
	}

return 0;
}
/*int h[MAX];
int result[MAX];
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
}*/ 
