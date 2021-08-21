#include <stdio.h>
#include <stdlib.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char *argv[]) {
	int n,cnt=0,sum=0;
	scanf("%d",&n);
	int a[205]={0};
	while(scanf("%d",&a[cnt])!=eof)//循环一旦判断不成就会以后都不成了，最好进去之后在continue
	{
		cnt++;
	 } 
	for(int i=0;i<cnt;i++)
	{
		sum+=a[i];
	}
	double aveall= (double)sum/cnt;
	sum=0;
	
	for(int k=0;n*k<=cnt;k++)
	{
		sum=0;
		for(int j=0;j<n;j++)
		{
			sum+=a[n*k+j];
		}
		if((double)sum/cnt >= aveall) 
		{
			printf("Group:%d\n",k);
			for(int j=0;j<n;j++)
			{
				printf("%d\n",a[n*(k+1)-1-j]);
			}
		}
		
	}
	
	if(cnt%n==0)return 0;
	else 
	{
		printf("out of range\n");
		for(int j=0;j<(cnt-cnt%n);j++)
		printf("%d\n",a[(cnt-cnt%n)-j-1]);
	}
	return 0;
}
