#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

typedef struct 
{
	char s[400];
	int type;
}layer; 

typedef struct stack1
{
	double data[3000];
	int top;
}stk1;
typedef struct stack2
{
	int top;
	layer a[500];
}stk2;
stk1 numstk;
stk2 strstk;
void init1()
{
	numstk.top = -1;
	memset(numstk.data, 0, sizeof(numstk.data));
}
void init2()
{
	strstk.top = -1;
	memset(strstk.a, 0 , sizeof(strstk.a));
}
void enqueue1(double a)
{
	numstk.top++;
	numstk.data[numstk.top] = a;
}
double dequeue1()
{
	numstk.top--;
	return numstk.data[numstk.top+1];
}
void enqueue2(layer t)
{
	strstk.top++;
	strstk.a[strstk.top] = t;
}
layer dequeue2()
{
	strstk.top--;
	return strstk.a[strstk.top+1];
}
int isempty1()
{
	if(numstk.top == -1) return 1;
	else return 0;
}
int isempty2()
{
	if(strstk.top == -1) return 1;
	else return 0;
}

void kuohao(char s[])
{
	int len = strlen(s);
	for(int i = len+1; i >= 1; i--)
	{
		s[i] = s[i-1];
	}
	s[0] = '(';
	s[len+1] = ')';
	s[len+2] = '\0';
}

int main(int argc, char** argv) {
	char s[100];
	init1(); init2();
	while(scanf("%s", s) != EOF)
	{
		
	
			if(s[0] == '+')
			{
				double a,b;
				b = dequeue1();
				a = dequeue1();
				enqueue1(a+b);
				
				layer aa,bb;
				bb = dequeue2();aa = dequeue2();
				layer cc;
				memset(cc.s, 0, sizeof(cc.s));
				strcat(cc.s,aa.s);
				strcat(cc.s, "+");
				strcat(cc.s,bb.s);
				cc.type = 1;
				enqueue2(cc);
			}
			else if(s[0] == '-')
			{
				double a,b;
				b = dequeue1();
				a = dequeue1();
				enqueue1(a-b);
				
				layer aa,bb;
			
				bb = dequeue2();aa = dequeue2();
				layer cc;
				memset(cc.s, 0, sizeof(cc.s));
				strcat(cc.s,aa.s);
				strcat(cc.s, "-");
				strcat(cc.s,bb.s);
				cc.type = 2;
				enqueue2(cc);
			}
			else if(s[0] == '*')
			{
				double a,b;
				b = dequeue1();
				a = dequeue1();
				enqueue1(a*b);
				
				layer aa,bb;
			
				bb = dequeue2();	aa = dequeue2();
				if(aa.type == 1 || aa.type == 2) kuohao(aa.s);
				if(bb.type == 1 || bb.type == 2) kuohao(bb.s);				
				layer cc;
				memset(cc.s, 0, sizeof(cc.s));
				strcat(cc.s,aa.s);
				strcat(cc.s, "*");
				strcat(cc.s,bb.s);
				cc.type = 3;
				enqueue2(cc);
			}
			else if(s[0] == '/')
			{
				double a,b;
				
				b = dequeue1();a = dequeue1();
				enqueue1(a/b);
				layer aa,bb;
				
				bb = dequeue2();aa = dequeue2();
				if(aa.type == 1 || aa.type == 2) kuohao(aa.s);
				if(bb.type == 1 || bb.type == 2) kuohao(bb.s);				
				layer cc;
				memset(cc.s, 0, sizeof(cc.s));
				strcat(cc.s,aa.s);
				strcat(cc.s, "/");
				strcat(cc.s,bb.s);
				cc.type = 4;
				enqueue2(cc);
			}
			
			
		
		else 
		{
			int a1 = atoi(s);
			double num = (double) a1;
			enqueue1(num);
			
			layer b1;
			strcpy(b1.s,s);
			b1.type = -1;
			enqueue2(b1);
			
		}
		
		memset(s,0,sizeof(s));
	}
	if(strstk.top == 0) 
	printf("%s\n", strstk.a[0].s);
	if(numstk.top == 0)
	printf("%.2lf", numstk.data[0]); 
	
	return 0;
}
/*
5 2 3 + 4 * +
*/
