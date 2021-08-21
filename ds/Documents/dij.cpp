
#include <bits/stdc++.h> 
#define inf 2*10^9
#define MAXN  100008
#define MAXM  500008
int  head[MAXN]={0};//邻接表的表头 
long long diss[MAXN]={0};//dis of dij
int cnt = 0 ;
int bk[MAXN]={0}; 
/* run this program using the console pauser or add your own getch, system("pause") or input loop */
typedef struct edge
{
	int to;//固定u 不变时 ，to指向 v
	int dise;//dis of edge
	int next;//同一个u的另一条临边的编号 
}edg;

edg edge[MAXM];
struct node
{
	int diss;
	int pos;
 bool operator <(const node &B)const
    {
        return B.diss<diss;
    }
};


inline void crtmap(int u, int v, int w)
{
	cnt++;
	edge[cnt].dise = w; edge[cnt].to = v;
	edge[cnt].next = head[u]; //接上链子 
	head[u] = cnt;//更新表头 
}



std::priority_queue<node> q;

inline void dij( int s ,int n) 
{
	for(int i=1; i<=n; i++)
	{
		diss[i] = 2147483647;
	 } 
	diss[s] = 0;
	q.push((node){0,s});
	while(!q.empty())
	{
		node tmp = q.top();
		q.pop();
if(bk[tmp.pos]) continue;
bk[tmp.pos]=1;
		/*if(bk[tmp.pos]==0)
        {
            bk[tmp.pos]=1;
         } 
        else {break;}区分区别 一个continue直接下次循环，而break会跳出去*/ 
		
		for(int i = head[tmp.pos];i;i = edge[i].next)//i 是当前所在pos的一个边的编号  表示连得第i号边 
		{
			if(diss[tmp.pos] + edge[i].dise < diss[edge[i].to])
			{
				diss[edge[i].to] = diss[tmp.pos] + edge[i].dise;
				if(bk[edge[i].to]==0)
				{
					q.push((node){diss[edge[i].to],edge[i].to}); //堆排更快 
				}
			}
			
		 } 
		//同一个pos时遍历 各个v 疏松一下 
		
	}
 } 

int main(int argc, char** argv) {
	int m,n,s;
	scanf("%d%d%d",&n,&m,&s);
	for (int i = 0; i < m ; i++)
	{
		int u,v,w;
		scanf("%d%d%d",&u,&v,&w);
		crtmap(u,v,w);
	 } 
	dij(s,n);
	for(int i = 1; i <= n; i++)
	{
		printf("%d ",diss[i]);
	}
	return 0;
}
