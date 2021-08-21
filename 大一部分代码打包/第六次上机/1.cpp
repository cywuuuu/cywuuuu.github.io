#include <stdio.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char** argv) {
	int n;
	int a[10000]={0},b[10000]={0};
	long long sum=0;
	printf("input\n");
	scanf("%d",&n);
	for(int i=0;i<n;i++)
	{
		scanf("%d",&a[i]);
	}
	 
	for(int i=0;i<n;i++)
	{
		scanf("%d",&b[i]);
	}
	for(int i=0;i<n;i++)
	{
		sum+=a[i]*b[i];
	}
	printf("%lld",sum);
	return 0;
}
