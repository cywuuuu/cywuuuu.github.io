#include <iostream>
#define ll long long 
using namespace std;
/* run this program using the console pauser or add your own getch, system("pause") or input loop */
	ll prime_fac[200000];
	ll prime_time[200000];
int main(int argc, char** argv) {
	ll n;
	scanf("%lld", &n);
	ll cnt = 0;
	for(ll i = 2; i <= n; i++)
	{
		if(n % i == 0) 
		{
			prime_fac[cnt] = i;
			while(n % i == 0)
			{
				n /= i;
				prime_time[cnt]++;
			}
			cnt++;
		}
	 } 
	for(ll i = 0; i < cnt; i++)
	{
		printf(" %lld^%lld *", prime_fac[i], prime_time[i]);
	}
	return 0;
}
