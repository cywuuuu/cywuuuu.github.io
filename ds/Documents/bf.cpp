#include <stdio.h>
//好处 储存内存小 简单 但是时间花销大//代码量少 //负闭环 
/* run this program using the console pauser or add your own getch, system("pause") or input loop */
long long inf = 2147483647;
	long long dis[101000];
	int u[500008],v[500008],w[500008]; 

int main(int argc, char** argv) {
	int n,m,s,check;
//记录第i顺位输入的边的节点 长度信息 
	scanf("%d%d%d",&n,&m,&s);//点数 边数 初始点data
	for(int i = 1; i <= m;i++)
	{
		scanf("%d%d%d",&u[i],&v[i],&w[i]);
	}
	for(int i = 1; i<=n ; i++)
	{
		dis[i] = inf;
	}
	dis[s] = 0;
	
	for(int i = 0;i<n-1; i++)
	{
		check = 0;
		for(int j = 1; j <= m; j++)
		{
			if(dis[v[j]]>dis[u[j]]+w[j])
			
			{
				dis[v[j]]=dis[u[j]]+w[j]; 
				check = 1; 
				//与dij 不同 dij通过贪心找最小值 扩张 
				//而bellman 用遍历 所以此处不把它看作已经完成 
			}
		 } 
		 if(check == 0) break; 
	}
	for(int i = 1; i<=n; i++)
	{
		printf("%d ",dis[i]);
	}
	return 0;
}
