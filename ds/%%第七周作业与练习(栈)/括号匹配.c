#include <stdio.h>
#include <string.h>
#include <ctype.h>
#define MAX 10000
int flag1 = 0;// "
int flag2 = 0;// '
int flag3 = 0;// /*
int totflag = 1;
int cnt = 0;
char s[5000];
char ans[5000];
int tot = 0;
typedef struct stk
{
	char data[MAX];
	int line[MAX];
	int top;
}stk;stk stack;
void init (stk *q)
{
	q->top = -1;
}
int push (stk *q, char a, int l)
{
	if(q->top == MAX - 1)
	{
		return -1;
	}
	q->top++;
	q->data[q->top] = a;
	q->line[q->top] = l;
	
	return 1;
}
int pop (stk *q, char *m, int * l)
{
	if(q->top == -1) return -1;
	*m = q->data[q->top];
	*l = q->line[q->top];
	q->top--;
	return 1;
}
int check(char *p);

int main(int argc, char** argv) {
	FILE *fp = fopen("example.c","r");
	
	init(&stack);
	char get;
	int l;
	while(fgets(s,4000,fp)!=NULL)
	{
		
		int len = strlen(s);
		cnt++;
		for(int i = 0; i < len; i++)
		{
			if(ispunct(s[i]))
			{
			
				check(&s[i]);
				if(totflag == -2) break;
				if(totflag == -1);
				if(totflag == 1)
				{
					
					if(s[i] == '{' || s[i] == '(' )
					{
						push(&stack, s[i], cnt);ans[tot++] = s[i];
					}
					if(s[i] == '}')
					{
						ans[tot++] = s[i];
						if(stack.data[stack.top] != '{')
						{
							while(stack.top > -1 && stack.data[stack.top] != '{') 
							{
								pop(&stack,&get,&l);
							}
							
							if(stack.top == -1)
							printf("without maching \'%c\' at line %d", '}', cnt);
							else 
							{
								printf("without maching \'%c\' at line %d", get, l);
							}
							return 0;
						}
						else
						{
							pop(&stack, &get, &l);
							
						}
					}
					
					else if(s[i] == ')')
					{
						ans[tot++] = s[i];
						if(stack.data[stack.top] != '(')
						{
							while(stack.top > -1 && stack.data[stack.top] != '(') 
							{
								pop(&stack,&get,&l);
							}
							
							if(stack.top == -1)
							printf("without maching \'%c\' at line %d", ')', cnt);
							else 
							{
								printf("without maching \'%c\' at line %d", get, l);
							}
							return 0;
						}
						else
						{
							pop(&stack, &get, &l);
						}
					}
				}
			}
		}memset(s,0,4000);
	}
	if(stack.top==-1) 
	{
		for(int i = 0; i < tot; i++)
		{
			printf("%c", ans[i]);
		}
	}
	else
	{
		while(stack.top > -1)
	{
		pop(&stack, &get, &l);
		
	}printf("without maching \'%c\' at line %d", get, l);
	}
	
	
	fclose(fp); 
	return 0;
}
int check(char *p)
{
	if(*p == '\"' && flag1 == 0 && totflag == 1) 
	{
		flag1 = 1;
	}
	else if(*p == '\"' && flag1 == 1 && totflag == -1)
	{
		flag1 = 0;
	}
	if(*p == '\'' && flag2 == 0 && totflag == 1) 
	{
		flag2 = 1;
	}
	else if(*p == '\'' && flag2 == 1&& totflag == -1)
	{
		flag2 = 0;
	}
	if(*p == '/' && *(p+1) == '*' && flag3 == 0&& totflag == 1) 
	{
		flag3 = 1;
	}
	else if(*p == '*' && *(p+1) == '/' && flag3 == 1&& totflag == -1)
	{
		flag3 = 0;
	}
	if(*p == '/' && *(p+1) == '/'&& totflag == 1) totflag = -2;//整行废了 
	else if(flag1 + flag2 + flag3 == 0 ) totflag = 1;// 可以入栈 
	else totflag = -1;//不行呢 
	return 0; 
}


