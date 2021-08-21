#include <stdio.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

double p(int n,double x)
{
	if(n==0) return 1;
	else if(n==1) return x;
	else
	{
		return ((2*n-1)*x-p(n-1,x)-(n-1)*p(n-2,x))/n;
	}
}

int main(int argc, char** argv) {
	int n;
	double x; 
	scanf("%d%lf",&n,&x);
	printf("%lf",p(n,x));
	
	return 0;
}
