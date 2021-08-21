#include <iostream>
using namespace std; 
/* run this program using the console pauser or add your own getch, system("pause") or input loop */
	long long dp[30000000];	long long w[300000];
	long long v[300000];
#define max(x,y) (x) > (y) ? (x) : (y)
int main(int argc, char** argv) {
	long long all,m;


	scanf("%lld%lld", &all, &m);
	for(long long i = 1; i <= m; i++)
	{
		scanf("%d%d", &w[i], &v[i]);
	}
	for(long long i = 1; i <= m; i++)
	{
		for(long long j = all; j >= w[i]; j--)
		{
			dp[j] = max(dp[j], dp[j-w[i]] + v[i]);
		}
	}
	printf("%lld",dp[all]);
	return 0;
}
