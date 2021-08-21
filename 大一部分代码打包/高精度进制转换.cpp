#include <stdio.h>
#include <string.h>
#include <ctype.h>
/* run this program using the console pauser or add your own getch, system("pause") or input loop */
 char s[2000];
 int a[2000];
 int ans[2000];
int main(int argc, char** argv) {
	int m,n;
	while(	scanf("%d%d",&m,&n)!=EOF)
	{
	
		while(gets(s)!=NULL)
		{
			int carry=0;
			int first=0;
			int wei=0;
			for(int i=0;i<strlen(s);i++)
			{
				if(isdigit(s[i]))
				{
					a[i]=s[i]-'0';
					
				}
				else
				{
					a[i]=s[i]-'A'+10;
				}
			}
			while(first<strlen(s))
			{
				carry=0;
				for(int i=first;i<strlen(s);i++)
				{	
					a[i]+=carry*m;
					carry=a[i]%n;
					a[i]=a[i]/n;
				}
				if(a[first]==0)first++;
				ans[wei++]=carry;
			}
			for(int i=wei-1;i>=0;i--)
			{
				printf("%d",ans[i]);
			}
		}
		
	}
	return 0;
}
