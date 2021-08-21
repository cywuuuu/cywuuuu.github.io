#include <stdio.h>
#include <math.h>
// 用大数限估算排除特别大的数 缩小n范围至 1e8 
//在1e8范围内 1234 会超限，而 5 6不会
//找到4,5分界进行分开
//小的时候1,2,3,4,5,6都考虑
//大的时候只用考虑5,6即可 
// 取小范围 此范围大于alg1<alg2的出数范围，又可以保证alg1不过大
//接着取更大范围时 alg1由于超过了其出数范围 不予考虑
// 同理  
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
	return n*(long long)floor(sqrt((double)n))+233333;    //大数转成double会不会危险 ??
}

long long alg5(long long n)
{	
	return n*(long long) ceil(log2(n))+2333333;
}
long long alg6(long long n)
{
	return 2*n+19522020;
}


/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char** argv) {
	int t;
	scanf("%d",&t);
while(t--)
{	long long alg[7]={0};
	long long n;
	scanf("%lld",&n);
	if(n>1e8) printf("6\n");
	else if(n<=800)
	{
		long long min=1e19;
		alg[1]=alg1(n);
		alg[2]=alg2(n);
		alg[3]=alg3(n);
		alg[4]=alg4(n);
		alg[5]=alg5(n);
		alg[6]=alg6(n);
		for(int i=1;i<=6;i++)
		{
			if(min>alg[i]) 
			{
				min=alg[i];
			}	
		}
		
			for(int i=1;i<=6;i++)
		{
			if(min==alg[i]) 
			{
				printf("%d\n",i);
				break;
			}	
		}
	}

		else if(n<1000000)
	{
		long long min=1e19;
		alg[4]=alg4(n);
		alg[5]=alg5(n);
		alg[6]=alg6(n);
		for(int i=4;i<=6;i++)
		{
			if(min>alg[i]) 
			{
				min=alg[i];
			}	
		}
		
			for(int i=4;i<=6;i++)
		{
			if(min==alg[i]) 
			{
				printf("%d\n",i);
				break;
			}	
		}
	}
	
	else 
	{
		long long min=1e19;
		
		alg[5]=alg5(n);
		alg[6]=alg6(n);
		for(int i=5;i<=6;i++)
		{
			if(min>alg[i]) 
			{
				min=alg[i];
			}	
		}
		
			for(int i=5;i<=6;i++)
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
