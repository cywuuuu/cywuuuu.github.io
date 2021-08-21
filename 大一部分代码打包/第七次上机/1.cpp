#include <stdio.h>
#include <math.h>
#define max(a,b) ((a)>(b)?(a):(b))
/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char** argv) {
	int t;
	long long n,l;
	scanf("%d",&t);
	while(t--)
	{
		scanf("%lld",&n);
		l=max(n+5,(long long)((1+1e-4)*n));
		
		//不要用ceil了！！！！ 
		printf("%lld\n",l);
		if(l>=(67108864/8*15)/16)
		{
			printf("Want some MLE?\n");
		}
		else 
		{
			printf("Pass the Problem!!!\n");
		}
	}
	return 0;
}
