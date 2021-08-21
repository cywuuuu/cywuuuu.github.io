#include <stdio.h>
#include <math.h>
/* run this program using the console pauser or add your own getch, system("pause") or input loop */
int a[20]={0};
int bk[20]={0};
int cnt=0;

int can(int k,int j)
{

	for(int i=1 ; i <= k-1;i++ )
	{
		if(j==a[i]||(a[i]+k-i==j)||(a[i]-(k-i)==j)) return 0;
		
	}
	return 1;
}

int Nqueen(int k,int n)//dfs()为位置信息 
{
	
	for(int i = 1; i <= n ; i++)
	{
		if(can(k,i)&&bk[i]==0)
		{
			a[k]=i;
			bk[i]=1;
			Nqueen(k+1,n);
			bk[i]=0;
		}
	}
	
	if(k==n+1)cnt++;
	if(k==n+1&&cnt<4)
	{
		for(int i=1;i<=n;i++)
		{
			printf("%d ",a[i]);
		}
		printf("\n");
		
	}

	return 0;
}


int main(int argc, char** argv) {
	int n;
	a[0]=-500;
	scanf("%d",&n);
	Nqueen(1,n);
	printf("%d",cnt);
	return 0;
}
