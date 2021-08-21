#include <stdio.h>
/* run this program using the console pauser or add your own getch, system("pause") or input loop */
#define M 1e7
int main(int argc, char** argv) {
	long long t,n,i;
	scanf("%lld",&t);
	while(t--)
	{
		scanf("%lld",&n);
		i=n-2;
		while(i>0)
		{
			
			n*=(i%M);
			i-=2;
			n=n%M;
		}
		printf("%lld\n",n);
	}
	return 0;
}
