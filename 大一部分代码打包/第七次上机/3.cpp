#include <stdio.h>
#include <string.h>
/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char** argv) {
	char a[600],b[600];	char *p;
	p=b;
	gets(a);
	for(int i=0;i<strlen(a);i++)
	{
		if('a'>a[i]&&a[i]>='A') a[i]=a[i]-('A'-'a');
	}
	//getchar();
	gets(b);
	for(int i=0;i<strlen(b);i++)
	{
		if('a'>b[i]&&b[i]>='A') b[i]=b[i]-('A'-'a');
	}

	while(*p!='\0')
	{
		
		if(strstr(p,a)!=NULL)
		{
		printf("%d ",strstr(p,a)-b);
		p=strstr(p,a);
		p+=strlen(a);}
		else break;
		
	}
	return 0;
}
