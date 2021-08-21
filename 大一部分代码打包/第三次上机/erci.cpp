#include <stdio.h>
#include<math.h>
/* run this program using the console pauser or add your own getch, system("pause") or input loop */
#define eps 1e-6 
int main(int argc, char** argv) {
	double a,b,c;
	scanf("%lf%lf%lf",&a,&b,&c);
	if(fabs(a)<eps){
		printf("No");
		return 0;
	}
	else
	{
		if(fabs(b*b-4*a*c)<eps) printf("1");
		else if(b*b-4*a*c<eps)printf("0");
		else if(b*b-4*a*c>eps)printf("2");
	}
	return 0;
}
