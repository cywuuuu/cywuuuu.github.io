#include <iostream>
#include <vector>
#include <math.h>
#define MAX 800010
#define LEN 22
using namespace std;
//¶à²æÊ÷ 
/* run this program using the console pauser or add your own getch, system("pause") or input loop */
	int n, m, s;
	vector <int> tree[MAX];
	int father[MAX];
	int dep[MAX];
	int vis[MAX];
	int fa[MAX][LEN];
	int lg2[MAX];
void dfs(int x)
{
	vis[x] = 1;
	for(unsigned int i = 0; i < tree[x].size(); i++)
	{
		int son = tree[x][i];
		if(vis[son] == 0)
		{	
			dep[son] = dep[x] + 1;
			father[son] = x; 
			dfs(son);
		}
	}
}



int main(int argc, char** argv) {
	scanf("%d%d%d", &n, &m, &s);
	for(int i = 1; i <= n; ++i)
		lg2[i] = lg2[i-1] + (1 << lg2[i-1] == i);
	for(int i = 0; i < n-1; i++)
	{
		int x, y;
		scanf("%d%d", &x, &y);
		tree[x].push_back(y);
		tree[y].push_back(x);
	}
	
	dfs(s);
	for(int i = 0; i < MAX; i++)
	{
		fa[i][0] = father[i];
	}
	for(int k = 1; k < LEN; k++)
	{
		for(int i = 1; i < MAX; i++)
		{
			fa[i][k] = fa[fa[i][k-1]][k-1];
		}
	}
	
	for(int kk = 0; kk < m; kk++)
	{
		int x, y;
		scanf("%d%d", &x, &y);
		if(dep[x] > dep[y]) swap(x,y);
		while(dep[y] > dep[x])
		{
			y = fa[y][lg2[dep[y]-dep[x]] - 1];
		}
		if(x == y) printf("%d\n", x);
		else
		{
			for(int i = lg2[dep[x]]  ; i >= 0; i--)
			{
				if(fa[y][i] != fa[x][i])
				{
					y = fa[y][i]; x = fa[x][i];
				}
				else continue;
			}
			if(x != y) printf("%d\n", fa[x][0]);
			else if (x == y) printf("%d\n", x);
		}
		
	}
	
	return 0;
}
