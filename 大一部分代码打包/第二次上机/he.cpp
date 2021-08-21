#include <stdio.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char** argv) {
	int n,sum=0,he=0;
	int a[11],b[11];
	scanf("%d",&n);
	for(int i=0;i<n;i++)
	{
		scanf("%d%d",&a[i],&b[i]);
	}
	for(int i=0;i<n;i++)
	{
		sum+=a[i]*b[i];
		he+=a[i];
	}
	printf("%.2lf",(double)sum/he);
	
	return 0;
}
