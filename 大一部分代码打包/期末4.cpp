#include <stdio.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char** argv) {
	int n,tmp0=0,tmp1=0;
	int a[1008][2];
	scanf("%d",&n);
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<2;j++)
		{
			scanf("%d",&a[i][j]);
		}
	}
	
	for(int i=0;i<n-1;i++)
	{
		for(int j=0;j<n-1;j++)
		{
			if(a[j][0]<a[j+1][0])
			{
				tmp1=a[j][0];
				a[j][0]=a[j+1][0];
				a[j+1][0]=tmp1;
				tmp1=a[j][1];
				a[j][1]=a[j+1][1];
				a[j+1][1]=tmp1;
			}
		}
	}
	
		for(int i=0;i<n-1;i++)
	{
		for(int j=0;j<n-1;j++)
		{
			if(a[j][1]>a[j+1][1]&&a[j][0]==a[j+1][0])
			{
				tmp1=a[j][0];
				a[j][0]=a[j+1][0];
				a[j+1][0]=tmp1;
				tmp1=a[j][1];
				a[j][1]=a[j+1][1];
				a[j+1][1]=tmp1;
			}
		}
	}
		for(int i=0;i<n;i++)
	{
		for(int j=0;j<2;j++)
		{
			printf("%d ",a[i][j]);
		}
		printf("\n");
	}
	return 0;
}
