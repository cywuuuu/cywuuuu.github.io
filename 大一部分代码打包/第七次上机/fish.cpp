#include <stdio.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */
	
int main(int argc, char** argv) {
	int n;
	
long long a[100]={1,1,2,4,7,13,23};
	while(scanf("%lld",&n)!=EOF)
	{		
		if(n<=6)
		printf("%lld\n",a[n]);
		else
		{
			for(int i=7;i<=n;i++)
			{
				a[i]=a[i-3]+a[i-2]+a[i-1]-a[i-6];
			}
			printf("%lld\n",a[n]);
		}
	}
	return 0;
}
