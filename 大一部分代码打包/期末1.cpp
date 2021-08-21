#include <stdio.h>
#include <string.h>
#include <stdlib.h>
/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char** argv) {
	int t,a,b,c,sum=0;
	char op1,op2;
	char s[2000];
	gets(s); 
	sscanf(s,"%d",&t);
	while(t--)
	{
		sum=0;
		gets(s);
		sscanf(s,"%d%c%d%c%d",&a,&op1,&b,&op2,&c);
		if(op1=='+'&&op2=='+') sum=a+b+c;
		if(op1=='*'&&op2=='+') sum=a*b+c;
		if(op1=='+'&&op2=='*') sum=a+b*c;
		if(op1=='*'&&op2=='*') sum=a*b*c; 
		printf("%d\n",sum);
	}
	return 0;
}
