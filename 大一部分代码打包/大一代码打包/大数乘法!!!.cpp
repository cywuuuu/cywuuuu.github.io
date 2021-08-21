#include <stdio.h>
#include <string.h>
/* run this program using the console pauser or add your own getch, system("pause") or input loop */
int c[4000000];
int main(int argc, char** argv) {
	char s1[2000],s2[2000];
	int a[2000]={0},b[2000]={0};
	int len;
	gets(s1);
	gets(s2); 
	for(int i=0;i<strlen(s1);i++)
	{
		a[i]=s1[strlen(s1)-i-1]-'0';
	}
	
	for(int i=0;i<strlen(s2);i++)
	{
		b[i]=s2[strlen(s2)-i-1]-'0';
	}
	len=strlen(s1)+strlen(s2);
	for(int i=0;i<strlen(s1);i++)
	{
		for(int j=0;j<strlen(s2);j++)
		{
			c[i+j]+=a[i]*b[j];
			
		}//ÏîÊý¡¢ 
	}
	for(int i=0;i<len;i++)
	{
		c[i+1]+=c[i]/10;
		c[i]=c[i]%10;
	}
	if(len>0&&c[len]==0) len--;
	
	for(int i=len-1;i>=0;i--)
	{
		printf("%d",c[i]);
	}
	return 0;
}
