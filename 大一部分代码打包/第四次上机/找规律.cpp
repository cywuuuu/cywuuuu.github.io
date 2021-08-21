#include <stdio.h>
#include <math.h>
/* run this program using the console pauser or add your own getch, system("pause") or input loop */
int gcd(int a,int b)
{	if(a>b) 
	{
		int tmp=a;
		a=b;
		b=tmp;
	}
	while(a)
	{
		int temp=a;
		a=b%a;
		b=temp;
	}
	return b;
}

int main(int argc, char** argv) {
	int n,i;
	while(scanf("%d",&n)!=EOF)
	{
		for(i=1;;i++)
		{
			if(n>=((i*(i-1))/2+1)&&n<=(i*(i+1))/2) 
			{
				break;
			}
		}

		if(i%2!=0)
		{
	
			int a=(i*i+i)/2-n+1;
			int b=i+1-((i*i+i)/2-n+1);
			if(a%b==0) printf("%d\n",a/b);
			else 
			{
				printf("%d / %d\n",a/gcd(a,b),b/gcd(a,b));
			}
		}
		
		
		if(i%2==0)
		{
			int b=(i*i+i)/2-n+1;
			int a=i+1-((i*i+i)/2-n+1);
			if(a%b==0) printf("%d \n",a/b);
			else 
			{
				printf("%d / %d\n",a/gcd(a,b),b/gcd(a,b));
			}
		
		}
		
	}
	
	return 0;
}
