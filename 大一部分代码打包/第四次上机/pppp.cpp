#include <stdio.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char** argv) {
	int n,k;
	scanf("%d%d",&n,&k);
	int xn[1008],yn[1008],xk[80],yk[80];
	for(int i=0;i<n;i++)
	{
		scanf("%d%d",&xn[i],&yn[i]);
	}
	for(int i=0;i<k;i++)
	{
		scanf("%d%d",&xk[i],&yk[i]);
	}
	int min=20000000,sum=0;
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<k;j++)
		{
			if((xn[i]-xk[j])*(xn[i]-xk[j])+(yn[i]-yk[j])*(yn[i]-yk[j])<min)
			{
			  min=(xn[i]-xk[j])*(xn[i]-xk[j])+(yn[i]-yk[j])*(yn[i]-yk[j]);
			}
		}
		sum+=min;
	}
	printf("%d",sum);
	return 0;
}
