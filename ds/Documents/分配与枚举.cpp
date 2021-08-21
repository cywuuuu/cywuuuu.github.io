#include <stdio.h> 
int a[20000][16]={0};
int sum=0;
int n,cnt=0;
int dfs(int k)
{
	if(k==11&&sum==n) 
	{
		for(int j=1;j<=n;j++)
		{
			a[cnt+1][j]=a[cnt][j];
		}
		cnt++;
	}
	if(k>11||sum>n) return 0;
	else{
	
	for(int i=1;i<=3;i++)
	{
		if(sum+i<=n)
		{
			a[cnt][k]=i;
			sum+=i;
			dfs(k+1);
			sum-=i;
		}	
	}}
}

int main(int argc, char** argv) {
	
	scanf("%d",&n);
	if(n>30) printf("0\n");
	else
	{
		
		dfs(1);printf("%d\n",cnt);
		for(int i=0;i<cnt;i++)
		{
			for(int j=1;j<=10;j++)
			{
				printf("%d ",a[i][j]);
			}printf("\n");
		}
	}
	return 0;
}
