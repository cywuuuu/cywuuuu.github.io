#include <stdio.h>
#include <string.h>
/* run this program using the console pauser or add your own getch, system("pause") or input loop */
char s[300];

int main(int argc, char** argv) {
	gets(s);
	char *p =strchr(s,'.');
	int len = strlen(s);
	if(p-s>=2)
	{
		for(int i = 0; i < len; i++)
		{
			if(i==1) printf(".");
			if(s[i]=='.') continue;
			printf("%c",s[i]);
		}
		printf("e%d",p-s-1);
	}
	else if(p-s==1 && s[0]=='0')
	{
		char *pp = p+1;
		while(*pp=='0') pp++;
		int cnt =0,diff = pp-p;
		while(*pp!='\0')
		{
			printf("%c",*pp);
			if(cnt==0 &&*(pp+1)!='\0') printf(".");
			pp++;cnt++;
		}
		printf("e-%d",diff);
		
	}
	else
	{
		for(int i = 0; i < len; i++)
		{
			printf("%c",s[i]);
		}
		printf("e0");
	}
	return 0;
}
