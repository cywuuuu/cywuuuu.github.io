#include <stdio.h>
#include <string.h>
#include <ctype.h>
/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char** argv) {
	int n;
	scanf("%d\n",&n);
    int flag=0;
	int a[128];
	char s[108];
	while(n--)
	{//为啥在这里getchar会吸掉回车+第一个数啊 
	flag=0;
		for(int i=0;i<128;i++)
		{
			a[i]=0;
		}
		gets(s);
		for(int i=0;i<strlen(s);i++)
		{
			s[i]=tolower(s[i]);
		}
		for(int i=0;i<strlen(s);i++)
		{
			a[s[i]]=1;
		}
		
		for(int i='0';i<='9';i++)
		{
			if(a[i]==0) 
			{printf("%c ",i);flag=1;
			}
		}
	
		for(int i='a';i<='z';i++)
		{
			if(a[i]==0) {printf("%c ",i);flag=1;
			}
		}
	
		if(flag==0) printf("Zzz LOVES this keyboard!");
		printf("\n");
	}
	return 0;
}
