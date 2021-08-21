#include <stdio.h>
#include <math.h>
/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char** argv) {
	int n;
	int a[1000]={0};
	int sum=0,max=-1,min=10088;
	double var=0;
	scanf("%d",&n);
	for(int i=0;i<n;i++)
	{
		scanf("%d",&a[i]);
		if(a[i]>max)max=a[i];
		if(a[i]<min)min=a[i];
		sum+=a[i];
	}
	double avg=(double)sum/n;
	for(int i=0;i<n;i++)
	{
		var+=(a[i]-avg)*(a[i]-avg);
		
	}
	var=var/n;
	printf("%-5d%-5d",max,min);
	printf("%-8.2lf%-10.2lf",avg,var);
	
	return 0;
}
