#include <stdio.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char** argv) {
	int m1,n1,m2,n2;
	scanf("%d%d%d%d",&m1,&n1,&m2,&n2);
	long long f[30][30]={0};
	long long h[30][30]={0};
	long long g[30][30]={0};
	for(int i=1;i<=m1;i++)
	{
		for(int j=1;j<=n1;j++)
		{
			scanf("%lld",&f[i][j]);
		}
	}
	for(int i=1;i<=m2;i++)
	{
		for(int j=1;j<=n2;j++)
		{
			scanf("%lld",&h[i][j]);
		}
	}
	for(int i=1;i<=m1-m2+1;i++)
	{
		for(int j=1;j<=n1-n2+1;j++)
		{	
			long long sum=0;
			for(int k=1;k<=m2;k++)
			{
				for(int l=1;l<=n2;l++)
				{
					sum+=f[i+k-1][j+l-1]*h[k][l];
				}
			}
			g[i][j]=sum;
		}
	}
	
		for(int i=1;i<=m1-m2+1;i++)
	{
		for(int j=1;j<=n1-n2+1;j++)
		{	
			
			printf("%lld ",g[i][j]);
		}
		printf("\n");
	}
	return 0;
}
