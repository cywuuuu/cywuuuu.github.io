#include <stdio.h>
#include <math.h>
long long get_phi(long long n) {
	long long phi = n, i;
	for (i = 2; i * i <= n; i++) {
		if (n % i == 0) {
			while (n % i == 0)
				n /= i;
			phi -= phi / i;
		}
	}
	if (n > 1) phi -= phi / n;
	return phi;
}
long long gcd(long long a, long long b) {
	return b ? gcd(b, a % b) : a;
}
long long pow_mod(long long a, long long t, long long p) {
	long long ans = 1;
	while (t--)
		ans = 1LL * ans * a % p;
	return ans;
}

/* run this program using the console pauser or add your own getch, system("pause") or input loop */
//慢慢来，错了不着急 
// 注意回车 

int main(int argc, char** argv) {
	long long n,a,t,p;
	scanf("%lld",&n);
	while(n--)
	{
		scanf("%lld%lld%lld",&a,&t,&p);
	
		if(gcd(a,p)==1) printf("Case #1: %lld\n",pow_mod(a,t%get_phi(p),p));
		else{
			
			if(t<get_phi(p)) printf("Case #2: %lld\n",pow_mod(a,t,p));
			
			else printf("Case #3: %lld\n",(long long)pow_mod(a,t%get_phi(p)+get_phi(p),p));
		}
		
	}
	return 0;
}
