#include <stdio.h>
#include <math.h>
#define PI cos(-1)
#define w 100
#define h 20
/* run this program using the console pauser or add your own getch, system("pause") or input loop */
int main(int argc, char** argv) {
	printf("弧度制\n"); //屏幕上提前放 

	char a[h][w];
	double dx;
	double l,r;
	for(int i=0;i<h;i++)
	{
		a[i][0]='|';a[i][w-2]='|';
		for(int j=1;j<w;j++)
		{
		
			
			a[i][j]=' ';
			if(i==h/2) a[i][j]='-';
		
		}
	}
	
	scanf("%lf%lf",&l,&r);
	
	
		for(int j=1;j<w;j++)
		{
			double x=(double)(l+j*(r-l)/(w-1));
			a[(int)(-sin(x)*h/2+h/2)][j]='*';
		}
	
	for(int i=0;i<h;i++)
	{
		for(int j=0;j<w;j++)
		{
			printf("%c",a[i][j]);
		}
		printf("\n");
	}

	
	return 0;
}
