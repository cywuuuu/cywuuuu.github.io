#include <stdio.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */
long long dp[60][5];
	
int main(int argc, char** argv) {
	long long n;dp[1][0]=1;
	dp[1][1]=0;
	dp[1][2]=0;
	dp[2][0]=1;
	dp[2][1]=1;
	dp[2][2]=0;
	dp[3][0]=2;
	dp[3][1]=1;
	dp[3][2]=1;
	while(scanf("%lld",&n)!=EOF)
	{
		for(int i=4;i<=n;i++)
		{
			dp[i][0]=dp[i-1][0]+dp[i-1][1]+dp[i-1][2];
			dp[i][1]=dp[i-2][0]+dp[i-2][1]+dp[i-2][2];
			dp[i][2]=dp[i-3][0]+dp[i-3][1];
		}
		printf("%lld\n",dp[n][0]+dp[n][1]+dp[n][2]);
	}
	return 0;
}
