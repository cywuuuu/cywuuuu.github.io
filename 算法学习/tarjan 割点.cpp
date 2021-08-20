#include <iostream>
#define MAXV 80080
#define MAXE 200090
#define min(x,y) ((x) < (y)) ? (x) : (y)
using namespace std;
typedef struct edge
{
	int to, next, w;
}edge;
edge e[MAXE];
int head[MAXV];
int dfn;
int low[MAXV];
int num[MAXV];
int iscut[MAXV];
int cnt = 0;
int first;
/* run this program using the console pauser or add your own getch, system("pause") or input loop */
int addedge(int u, int v)//u -> v
{
	cnt++;
	e[cnt].to = v;
	e[cnt].w = 1;
	e[cnt].next = head[u];
	head[u] = cnt;
	return 1;
}
int  tarjan(int u, int fa)
{
	int child = 0;
	low[u] = num[u] = ++dfn;
	for(int i = head[u]; i != 0; i = e[i].next)
	{
		int v = e[i].to;
		if(num[v] == 0)// v从未被访问过 
		{
			child++;
			tarjan(v,u);
			
			low[u] = min(low[u], low[v]);
			if(low[v] >= num[u] && u != fa)//bug在此，已修复 
			{
				iscut[u] = 1;
			}
		}
		else if(num[v] < num[u] && v != fa)//如果 v 被曾经访问过且时间戳较小 则为 v-u 是一条dfs生成树的回退边 
		{//eg 10.15 在最后进入d时，发现num[b] = 2 更小一点， 可以判断bd为回退边，那么要更新low[d] 
			low[u] = min(low[u], num[v]); 
		 } 
	}
	if(u == fa && child >= 2)
	{
		iscut[first] = 1;
	 } 
 	 return 1;
}
int main(int argc, char** argv) {
	int n, m;
	freopen("P3388_11.in", "r+",stdin); 
	scanf("%d%d", &n, &m);
	for(int k = 0; k < m; k++)
	{
	
		int u, v;
		scanf("%d%d", &u, &v);	
		if(k == 0) first = u;
		addedge(u,v);
		addedge(v,u);
	}
	for(first = 1; first <= n; first++)
	{
		if(num[first] == 0)
		tarjan(first,first);
		//fa用-1表示meiyou
/*		int ct = 0;
		for(int j = 1; j <= n; j++)
		{
			if(num[j] != 0) ct++;
		}
		printf("ct :: %d", ct);*/
	}
	
	int num = 0;
	for(int i = 1; i <= n; i++)
	{
		if(iscut[i] != 0)
		num++;
	}
	printf("%d\n", num);
	
	for(int i = 1; i <= n; i++)
	{
		if(iscut[i] != 0) 
		printf("%d ", i);
	 } 
	 fclose(stdin);
	return 0;
}
