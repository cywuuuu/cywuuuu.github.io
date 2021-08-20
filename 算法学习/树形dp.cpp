#include <iostream>
#include <cmath>
#include <vector>
#define MAX 80000
using namespace std;
/* run this program using the console pauser or add your own getch, system("pause") or input loop */
int val[MAX];
vector <int> tree[MAX];
int father[MAX]; 
long long dp[MAX][2]; //[0]为选， [1]为不选 

void dfs(int x)
{
	dp[x][0] = 0;
	dp[x][1] = val[x];
	for(unsigned int i = 0; i < tree[x].size(); i++)
	{
		int son = tree[x][i];
		dfs(son);
		dp[x][1] += dp[son][0];
		dp[x][0] += max(dp[son][0], dp[son][1]);
	}
} 

int main(int argc, char** argv) {
	int n;
	scanf("%d", &n);
	for(int i = 0; i < MAX; i++)
	{
		father[i] = -1;
	}
	for(int i = 1; i <= n; i++)
	{
		scanf("%d", &val[i]);
	}
	for(int i = 1; i <= n-1; i++)
	{
		int son,fa; 
		scanf("%d%d", &son, &fa);
		tree[fa].push_back(son);
		father[son] = fa;
	}
	int x = 1;
	while(father[x] != -1)
	{
		x = father[x];
	}
	dfs(x);
	printf("%lld", max(dp[x][0], dp[x][1]));
	return 0;
}
