#include <stdio.h>
#include <math.h> 
#define pi 3.1415926
/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char** argv) {
	int x,y,d;
	double a,b;
	scanf("%d,%d,%d",&x,&y,&d);
	a=x*cos((double)d*pi/180)-y*sin((double)d*pi/180);
	b=x*sin((double)d*pi/180)+y*cos((double)d*pi/180);
	printf("(%.2f,%.2f)",a,b);
	return 0;
}
