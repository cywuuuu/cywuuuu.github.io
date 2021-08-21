#include <stdio.h>
#include <string.h>
#define MAX 100000
/* run this program using the console pauser or add your own getch, system("pause") or input loop */
typedef struct stk
{
	int data[MAX];
	int top;
	
}stk;
void init (stk *q)
{
	memset(q->data,0,MAX);
	q->top = -1;
}

int push( stk *q, int a)
{
	if(q->top == MAX-1) return -1;
	q->data[++q->top] = a;
	return 1;
}
int pop(stk *q, int *a)
{
	if(q->top == -1) return -1;
	*a = q->data[q->top--];
	return 1;
}

int main(int argc, char** argv) {
	int type, m;
	int get;
	stk stack;
	init(&stack);
	while(scanf("%d", &type) != EOF)
	{
		if(type == -1) return 0;
		if(type == 1)
		{
			scanf("%d", &m);
			if(push(&stack, m) == -1) printf("error ");
		}
		else if (type == 0)
		{
			get = 0;
			if(pop(&stack, &get)== -1) printf("error ");
			else printf("%d ", get);
		}
	}
	return 0;
}
