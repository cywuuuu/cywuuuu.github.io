#include <stdio.h>
#include <string.h>
/* run this program using the console pauser or add your own getch, system("pause") or input loop */
	char yu[5000];
	char a[2010],b[2008],tmp[2008];
	char zhu[2008],wei[2008],bin[2008];
int main(int argc, char** argv) {
	gets(a);
	gets(b);
	//why scanf wrong
	int n=0;
	if(strlen(a)>strlen(b))
	{
		strcpy(tmp,a);
		strcpy(a,b);
		strcpy(b,tmp);
	}
	//b bigger
	scanf("%d",&n);
	for(int i=0;i<=n;i++)
	{
		zhu[i]=b[i];
	}
	for(int i=n+1;i<=strlen(b)-1;i++)
	{
		bin[i-n-1]=b[i];
	}
	strcat(zhu,a);
	strcat(zhu,bin);
	puts(zhu);
	return 0;
}
