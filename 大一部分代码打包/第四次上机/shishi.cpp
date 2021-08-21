#include <stdio.h>
#include <math.h>
long long alg1(long long n)
{	long long u=1;
	for(long long i=n;i>=n-3;i--)
	{
		u*=i;
	}
	u=u/24;
	return u+1;
}

long long alg2(long long n)
{
	long long u=1;
	for(long long i=n;i>=n-2;i--)
	{
		u*=i;
	}
	return u+2;
}

long long alg3(long long n)
{
	return n*(n-7)/2+23333; 
}

long long alg4(long long n)
{	
	return n*(long long)floor(sqrt((double)n))+233333;    //转成double会不会危险 
}

long long alg5(long long n)
{	
	return n*(long long) ceil(log2(n))+2333333;
}
long long alg6(long long n)
{
	return 2*n+19522020;
}

int main(int argc, char** argv) {
	int t;
	scanf("%d",&t);
while(t--)
{	long long alg[7]={0};
	long long n;
	scanf("%lld",&n);
	if(n>=1&&n<=27)
	printf("1\n");
	if(n>=28&&n<=29)
	printf("2\n");
	if(n>=1061600) printf("6\n");
	else
	{
			long long min=1e8;

	
		alg[3]=alg3(n);
		alg[4]=alg4(n);
		alg[5]=alg5(n);
		alg[6]=alg6(n);
		for(int i=3;i<=6;i++)
		{
			if(min>alg[i]) 
			{
				min=alg[i];
			}	
		}
		
			for(int i=3;i<=6;i++)
		{
			if(min==alg[i]) 
			{
				printf("%d\n",i);
				break;
			}	
		}
	}
}
	return 0;
}

