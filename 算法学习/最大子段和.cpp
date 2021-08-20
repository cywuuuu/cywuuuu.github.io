#include <iostream>
#define max(x,y) (x) < (y) ? (y) : (x)
using namespace std;
/* run this program using the console pauser or add your own getch, system("pause") or input loop */
long long dp[300008];
long long a[300008];
int main(int argc, char** argv) {
//	freopen("P1115_1.in", "r+", stdin);
	int n;
	long long sum = (-2147483647L - 1) ;
	scanf("%d", &n);
	for(int i = 1; i <= n; i++)
	{
		scanf("%lld",&a[i]);
	}
	for(int i = 1; i <= n; i++)
	{
		dp[i] = max(dp[i-1]+a[i], a[i]);
	}
	for(int i = 1; i <= n; i++)
	{
		if(sum < dp[i]) sum = dp[i];
	}
	printf("%lld", sum);
//	fclose(stdin);
	return 0;
}
