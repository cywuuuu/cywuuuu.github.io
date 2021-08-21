#include <stdio.h>
#include <math.h>
/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char** argv) {
	int n;
	int a[10];
scanf("%d",&n);
	for(int i=0;i<n;i++)
	{
		scanf("%d",&a[i]);
	}
	for(int i=0;i<n;i++)
	{	
		int cnta=0,cntb=0;
		for(int j=0;j<14;j++)
		{
		
		if(j<=6)
		{
			cnta+=(a[i]&(1<<j))/pow(2,j);
		}
		if(j>=7)
		{
			cntb+=(a[i]&(1<<j))/pow(2,j);
		}
		}
		
		
		if(cnta%2==0&&cntb%2==1)
		{
			printf("%d\n",a[i]);
		}
		
		else 
		{
			int b[14]={0};
				for(int j=0;j<14;j++)
				{
					b[13-j]+=(a[i]&(1<<j))/pow(2,j);
				}
			int sum=0;
				for(int j=0;j<14;j++)
				{
					sum+=b[j]*pow(2,j);
				}
			printf("%d\n",sum);
		} 
		
	}
	
	return 0;
}
