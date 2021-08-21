#include <stdio.h>
#include <string.h>
#include <math.h>
#define limit 1e-8
//勤能补拙
// 边界条件单独判断 不要以为会自动变成那样
//二分法有条件，谨防条件不符 
/* run this program using the console pauser or add your own getch, system("pause") or input loop */
double f(double x,double a,double lamda)
{
	return (-a*2/(log(2)*(2*x-1))+2*lamda*x);
}
double ff(double x,double a,double lamda)
{
	return (-a*log2(2*x-1)+lamda*x*x);
}
int main(int argc, char** argv) {

	double a,lamda;
 	while(scanf("%lf%lf",&a,&lamda)!=EOF)
 	{
	 double x=.5,y=1; 
	 if(f(x,a,lamda)*f(y,a,lamda)>=0)
      {
      	if(f(x,a,lamda)>=0&&f(y,a,lamda)>=0)
      	{
      		printf("%.10lf %.10lf\n",ff(x,a,lamda),x);
		}
		else if(f(x,a,lamda)<0&&f(y,a,lamda)<0)
      	{
      		printf("%.10lf %.10lf\n",ff(y,a,lamda),y);
		}
	  } 
	  x=.5;y=1; 
	  
	  if(f(x,a,lamda)*f(y,a,lamda)<0)
	  	{
		    while(fabs(x-y)>limit) 
			{	 
			  if(f((x+y)/2,a,lamda)*f(y,a,lamda)<0) 
		        x=(x+y)/2;
		      else //同号
		        y=(x+y)/2;
			} printf("%.10lf %.10lf\n",ff(x,a,lamda),x);
     }   
   

}
	return 0;
}
