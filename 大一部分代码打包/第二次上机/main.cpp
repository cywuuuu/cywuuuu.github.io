
#include<stdio.h>
int main ()
{
	int n,jinwei,weishu=1,temp;
	int a[10000];
	scanf("%d",&n);
	a[1]=1;
	for(int i=2;i<=n;i++)
	{
		jinwei=0;
		for(int j=1;j<=weishu;j++)
		{
			temp=a[j]*i+jinwei;
			a[j]=temp%10;///////
			jinwei=temp/10;
		}
		
		
		while(jinwei>0)
		{
			weishu++;
			a[weishu]=jinwei%10;
			jinwei=jinwei/10;

		}
		
	} 
	for(int i=0;i<weishu;i++)
	{
		printf("%d",a[weishu-i]);
	}
	return 0;
}


