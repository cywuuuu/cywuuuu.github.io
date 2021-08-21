#include <stdio.h>
#include <string.h>
#include <ctype.h>
int getlen(int x[])
{
	int t=0;
	while(x[t]!=300)
	{
		t++;
	}
	return t;
}
int ishuiwen(int x[])
{
	int l=getlen(x);
	for(int i=0;i<l/2;i++)
	{
		if(x[i]!=x[l-i-1]) return 0;
	}
	return 1;
}

void revatob(int x[],int b[])
{
	int l=getlen(x);
	for(int i=0;i<l;i++)
	{
		b[l-i-1]=x[i];
	}
	return;
}
void bigadd(int a[],int b[],int n)
{
	int l=getlen(a);
	int carry=0;
	for(int i=0;i<l;i++)
	{
		int tmp=a[i]+b[i]+carry;
		a[i]=tmp%n;
		carry=tmp/n;
	}
	while(carry)
	{
		a[l++]=carry%n;
		carry/=n;
	}
}
int a[1000]={0};
int b[1000]={0};
char s[1000];
int main()
{
	
	
	
	for(int i=0;i<1000;i++)
	{
		a[i]=300;
		b[i]=300;
	}
    int len,n;
    scanf("%s",s);
    sscanf(s,"%d",&n);
    scanf("%s",s);
    len=strlen(s);
	
    for(int i=len-1;i>=0;i--)
    {
    	if(isdigit(s[i]))
    	a[i]=s[i]-'0';
    	else 
    	a[i]=s[i]-'A'+10;
	}
	

	for(int i=0;i<=30;i++)
	{	
		if(ishuiwen(a)) 
		{
			printf("STEP=%d\n",i);
			return 0;
		}
		revatob(a,b);
		bigadd(a,b,n);
	
	}
	printf("Impossible!\n");
	
    return 0;
}


