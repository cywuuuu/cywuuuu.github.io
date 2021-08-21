#include <stdio.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char** argv) {
	int n;
	int k;
	int max=0;
	scanf("%d",&n);
	double p[200]={0};
	for(int i=0;i<n;i++)
	{
		scanf("%d",&k);
		if(max<k) max=k;
		p[k]++;
	}
	for(int i=1;i<=max;i++)
	{
		p[i]=p[i]/n;
		printf("%.2lf ",p[i]);
	}
	return 0;
}
