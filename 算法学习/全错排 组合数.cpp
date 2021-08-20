#include <iostream>
using namespace std;
long long mod = 1e9 + 7;
/* run this program using the console pauser or add your own getch, system("pause") or input loop */
// lucas 推 c(n,m)
long long fact[2000089];
long long f[2000999];

//一下为计算c(n,m) ***********
long long quick_pow(long long a, long long b)
{
	long long res = 1;
	while(b)
	{
		if(b&1) res = a*res%mod;
		a = a%mod*a%mod;
		b >>= 1;
	}
	return res;
}

long long inv(long long a)
{
	return quick_pow(a, mod-2);
}

long long c(long long m, long long n)//小数的c（），用 快速幂+费马-》逆元 
{
	return fact[n]%mod * inv(fact[m]%mod*fact[n-m]%mod) %mod;
}
long long cc(long long m, long long n)//大数的c（n,m） 用Lucas定理 nchoosem
{
	if(m == 0) return 1;
	return cc(m/mod, n/mod)%mod * c(m%mod, n%mod);
}

int main(int argc, char** argv) {
	fact[1] = 1; fact[2] = 2;
	f[1] = 0; f[2] = 1;//错排公式 
	for(int i = 2; i <= 2e6; i++)
	{
		fact[i+1] = fact[i]%mod * (i+1) %mod;//初始化阶乘 
		f[i+1] = (i) * (f[i]%mod + f[i-1]%mod)%mod;//全错排 
	}
	int t ;
/*		long long m,n;
		scanf("%lld%lld", &m, &n);// n 大  m 小 
	printf("%lld",cc(m,n)%mod);*/
	scanf("%d", &t);
	while(t--)
	{
		long long m,n;
		scanf("%lld%lld", &n, &m);//n choose m
		if(n == m) printf("1\n");
//		else if (n = m + 1) printf("0\n");
		else
		printf("%lld\n",(f[n-m]%mod*cc(m,n)%mod)%mod);
	}
	
	return 0;
}
