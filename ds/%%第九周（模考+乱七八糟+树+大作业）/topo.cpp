#include <bits/stdc++.h>
#define MAX 1000088
#define max(x,y) (y)<(x)?(x):(y)
using namespace std;
/* run this program using the console pauser or add your own getch, system("pause") or input loop */
struct edge
{
	int to,next,w;
}edge[MAX];
int head[MAX];
int ind[MAX];
int f[MAX];//当前时间
int t[MAX]; 
int cnt;	int n;
void init()
{
	for(int i = 0 ; i < MAX; i++)
	{
		head[i] = -1;
		edge[i].next = -1;
	}
}
void addedge(int a, int b, int w)
{
	ind[b]++;
	edge[cnt].next = head[a];
	edge[cnt].to = b;
	edge[cnt].w = w;
	head[a] = cnt;
	cnt++;
}
void toposort()
{
	queue<int> q;
	for(int i = 1; i <= n; i++)
	{
		if(ind[i] == 0)
		{
			q.push(i);
		}
	}
	while(!q.empty())
	{
		int u = q.front();
		q.pop();
		for(int i = head[u]; i != -1; i = edge[i].next)
		{
			ind[edge[i].to]--;
			if(ind[edge[i].to] == 0)
			{
				q.push(edge[i].to);
			}
			f[edge[i].to] = max(f[edge[i].to], f[u]+t[edge[i].to]);
		}
	}
}
int main(int argc, char** argv) {
	init();

	scanf("%d", &n);
	for(int i = 0; i < n; i++)
	{
		int a,b,len;
		scanf("%d%d", &a,&len);
		t[a] = len;
		f[a] = len;
		while(scanf("%d", &b) != EOF)
		{
			if(b == 0) break;
			addedge(b,a,1);
		}
	}
	toposort();
	int mm = -1;
	for(int i = 1; i <= n; i++)
	{
	
		if(mm < f[i]) mm = f[i];
	}
	printf("%d ", mm);
	return 0;
}
