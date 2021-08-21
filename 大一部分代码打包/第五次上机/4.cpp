#include <stdio.h>
#include <math.h> 
/* run this program using the console pauser or add your own getch, system("pause") or input loop */
#define pi acos(-1)
int main(int argc, char** argv) {
	int x,y;
	double theta;
	while(scanf("%d%d",&x,&y)!=EOF)
	{	
		if(x>0&&y==0) theta=0;
		else if(x<0&&y==0) theta=pi;
		else if(x==0&&y>0) theta=pi/2;
		else if(x==0&&y<0) theta=-pi/2;
		else theta=atan2(y,x);
		
	
	
		if(fabs(theta)<1e-6)
		{
			printf("x=%.2lfcos(ct)\n",sqrt(x*x+y*y));
		}
		else if((theta)<1e-5)
		{
			printf("x=%.2lfcos(ct%.2lf)\n",sqrt(x*x+y*y),theta);
		}
		else if(theta>1e-5)
		{
			printf("x=%.2lfcos(ct+%.2lf)\n",sqrt(x*x+y*y),theta);	
		}
	}
	return 0;
}
