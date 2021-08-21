#include <stdio.h>
#include <math.h>
/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char** argv) {
	double pi=acos(-1);
	int n;
	double r;
	double a[10080]={0};
	scanf("%d%lf",&n,&r);
	for(int i=0;i<n;i++)
	{
		scanf("%lf",&a[i]);
	}
	
	double max=-1,min=10008,secmin=0;
		for(int i=0;i<n;i++)
	{
		if(a[i]>max) max=a[i];
		if(a[i]<min) min=a[i];
	}
	double ave=(max+min)/2;
		for(int i=0;i<n;i++)
	{
		if(a[i]==max) {
			a[i]=ave;break;
		}
	}
		for(int i=0;i<n;i++)
	{
		if(a[i]==min) {
			a[i]=ave;break;
		}
	}
	min=100080;//重新搜素min时一定重新初始化 
	for(int i=0;i<n;i++)
	{
		if(a[i]<min) min=a[i];
	}
	
	printf("%.4lf",min*pi*r*r);
	return 0;
}
