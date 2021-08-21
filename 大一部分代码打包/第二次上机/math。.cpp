#include <stdio.h>
#include <math.h>
/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char** argv) {
	double x,y,z,s;
	scanf("%lf%lf%lf",&x,&y,&z);
	s=pow(acos(sin(x)),log(1+fabs(sinh(y))))/(2+cos(z));//exp 是e的n次啦；log才是取对数不要被文子迷惑 
	printf("%.2lf",s);
	
	return 0;
}
