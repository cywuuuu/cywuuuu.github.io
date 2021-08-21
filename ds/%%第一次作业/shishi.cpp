#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
/* run this program using the console pauser or add your own getch, system("pause") or input loop */
typedef struct stack
{
 int a[1000];
 int top;
}stack;

void push(stack *stk,int b)
{
 stk->a[++stk->top] = b;
 return;
}
int pop(stack *stk)
{
 int num = stk->a[stk->top];
 stk->top--;
 return num;
} 
squeez(char s[],char c)
{
	int i,j;
	j=0;//j是前指针 i是全遍历指针 
	for(i=0;s[i]!='\0';i++)
	{
		if(s[i]!=c){
		s[j]=s[i];
		j++;
		};
	}
	s[j]='\0';
}
int main(int argc, char** argv) {

 stack *stack1 = (stack *)malloc(sizeof(stack));
 stack *stack2 = (stack *)malloc(sizeof(stack));
 char s[1000]={0};int s1[1000]={0};
gets(s); 
 squeez(s,' ');
 squeez(s,'=');
 int len = strlen(s);

  int cnt = 0;
  int num = 0;
  char *p = s;
  int *pp = s1;
  stack1->top = -1,stack2->top = -1;
  memset(stack1->a,0,1000); memset(stack2->a,0,1000);
  // 中缀转后缀
 
  while(*p!='\0')
  {
   if(isdigit(*p))
   {
    num = num*10 + *p-'0';
    if(!isdigit(*(p+1)))
    {
     s1[cnt++] = num;
     num = 0;
    }
   }
   //(*p=='+'||*p=='-') (*p=='*'||*p=='/') (a[stack1->top]=='+'||a[stack1->top]=='-') (a[stack1->top]=='*'||a[stack1->top]=='/')
   else
   {
    if(*p!='('&&*p!=')')
    {
     while(((*p=='+'||*p=='-')&&(stack1->a[stack1->top]=='+'||stack1->a[stack1->top]=='-'))||((*p=='+'||*p=='-')&&(stack1->a[stack1->top]=='*'||stack1->a[stack1->top]=='/'))||((*p=='*'||*p=='/')&&(stack1->a[stack1->top]=='*'||stack1->a[stack1->top]=='/')))
     {
      s1[cnt++] = pop(stack1);
     }
     push(stack1,*p);
    }
    
    else if(*p=='(') push(stack1,*p);
    
    else if(*p==')')
    {
     while(stack1->a[stack1->top]!='(')
     {
      s1[cnt++] = pop(stack1);
     }
     pop(stack1);
    }
   }
   p++;
  }
  
  while(stack1->top!=-1)
  {
   s1[cnt++] = pop(stack1);
  }
  
  while(pp-s1<cnt)   
  {
   if(*pp=='+')
   {
    int a,b;
    b=pop(stack2);
    a=pop(stack2);
    push(stack2, a+b);
    
   }
   else if(*pp=='-')
   {
    int a,b;
    b=pop(stack2);
    a=pop(stack2);
    push(stack2, a-b);
   }
   
   else if(*pp=='*')
   {
    int a,b;
    b=pop(stack2);
    a=pop(stack2);
    push(stack2, a*b);
   }
   
   else if(*pp=='/')
   {
    int a,b;
    b=pop(stack2);
    a=pop(stack2);
    push(stack2, a/b);
   }
   
   else{
    push(stack2,*pp);
   }
   pp++;
  }
  printf("%d\n",pop(stack2));
 return 0;
}
