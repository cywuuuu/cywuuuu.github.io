#include <stdio.h>
#include <string.h>
int n, m;
int g[100][100]; 
int vis[20];
int origin = 1;
int end;
int flag;
void dfs(int x) 
{
	vis[x] = 1;	
	int aa = 1;
	for(int i = 1; i <= n; i++)
	{
		aa = vis[i] & aa;
	}
	if(aa && (g[origin][x]))
	{
		flag = 1;
		return;
	}
	for(int i = 1; i <= n; i++)
		if((!vis[i]) && (g[x][i]))
			dfs(i);
	vis[x] = 0;
	return; 
}

int main()
{
	scanf("%d%d", &n, &m);
	for(int i = 0; i < m; i++)
	{
		int a, b;
		scanf("%d%d", &a, &b);
		g[a][b] = 1;
		g[b][a] = 1;
	}
	memset(vis, 0, sizeof(vis));
	dfs(origin);
	printf("%d", flag);	
	return 0;
}
