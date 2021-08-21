#include <stdio.h>
#include <string.h>
/* run this program using the console pauser or add your own getch, system("pause") or input loop */
	int minus(int* a,int* b)
	{
		int lena=0,lenb=0,len=0;
		for(int i=2000-1;i>=0;i--)//»áÍË»¯ 
		{
			if(a[i]!=0) {
				lena=i;break;
			}
		}
		for(int i=2000-1;i>=0;i--)
		{
			if(b[i]!=0) {
				lenb=i;break;
			}
		}
		for(int i=0;i<=lena;i++)
		{
			if(a[i]-b[i]<0) 
			{
				a[i+1]-=1;
				a[i]+=10;
			}
			a[i]-=b[i];
		}
		
		for(int i=2000-1;i>=0;i--)
		{
			if(a[i]!=0) {
				len=i;break;
			}
		}
		return len;
	}
	
int main(int argc, char** argv) {
	char s1[2000],s2[2000],tmp[2000];
	int a[2000]={0},b[2000]={0};
	int len=0;
	gets(s1);
	gets(s2);
	if(strlen(s1)<strlen(s2)||((strlen(s1)==strlen(s2))&&(s1[0]<s2[0])))
	{
		printf("-");
		strcpy(tmp,s1);
		strcpy(s1,s2);
		strcpy(s2,tmp);
	}
	for(int i=0;i<strlen(s1);i++)
	{
		a[i]=s1[strlen(s1)-1-i]-'0';
	}
	for(int i=0;i<strlen(s2);i++)
	{
		b[i]=s2[strlen(s2)-1-i]-'0';
	}

	len=minus(a,b);
	for(int i=len;i>=0;i--)
	{
		printf("%d",a[i]);
	}
	return 0;
}
