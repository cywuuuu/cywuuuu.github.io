#include <stdio.h>
#define N 500
#define max(a, b) ((a) > (b) ? (a) : (b))
#define min(a, b) ((a) < (b) ? (a) : (b))
//通过遍历，每次重新计算可以走到的最长距离 
int T, n;
int a[N + 5];
int main()
{
	scanf("%d", &T);
	int i, j, maxi;
	while (T--)
	{
		scanf("%d", &n);
		maxi = 0; // maxi 表示最远能到达哪里
		
		for (i = 1; i <= n; ++i) 
		scanf("%d", &a[i]);
		
		if (!a[1])
		{ // 第一次汪吉吃不到饭
			printf("You lose!\n");
			continue;
		}
		
		for (i = maxi = 1; i <= maxi && maxi != n; ++i) 
		maxi = min(max(i+a[i], maxi), n);
		
		printf(maxi == n ? "Completed!\n" : "You lose!\n");
	}
	return 0;
}
