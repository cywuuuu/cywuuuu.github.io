#include <iostream>
#include <bits/stdc++.h>
#define MAX 10000
using namespace std;
/* run this program using the console pauser or add your own getch, system("pause") or input loop */
struct Edge
{
	int to,next,w;
}edge[MAX<<2];priority_queue<int> q;
int head[MAX<<2];
int in[MAX<<2];
int m, n;//m个有向边 n个点  
int cnt = 0;
int num = 0;
int ans[MAX<<2];
int flag = 0;
void init()
{
	for(int i = 0; i < MAX<<2; i++)
	{
		edge[i].next = -1;
		head[i] = -1;
		in[i] = 0;
	}
	cnt = 0;
	num = 0;
	
}
void adde(int i, int j)
{
	edge[cnt].next = head[i];
	edge[cnt].to = j;
	edge[cnt].w = 1;
	head[i] = cnt;//存储起点i的第一条边的编号 
	in[j]++;
	cnt++;
}
void topo()
{
	
	for(int i = 1; i <= n; i++)
	{
		if(in[i] == 0) q.push(i);
	}
	int fr;
	while(q.empty()!=1)
	{
		fr = q.top();q.pop();
		ans[num] = fr;
		num++;
		for(int i = head[fr]; i != -1; i = edge[i].next)//next 下个边//to 是 所到之处 
		{
			in[edge[i].to] --;
			if(in[edge[i].to] == 0 ) q.push(edge[i].to); 
		}
		
	}
	if(num == n) 
	{
		for(int i = num-1; i >= 0; i--)
		{
			printf("%d ",ans[i]);
		}
	}
	else 
	{
		printf("Impossible!");
	}
}
int main(int argc, char** argv) {
	int i,j;
	int suibian; 
	scanf("%d", &suibian); 
	while(scanf("%d%d", &n , &m)!= EOF)
	{
		init ();
		flag = 0;
		for(int k = 0; k < m ; k++)
		{
			scanf("%d%d", &i ,&j);
			adde(j,i);
			if(i==j)
			{
				flag = 1;
			}
		}
		
		if(flag == 1) 
		{
			printf("Impossible!\n");
		}
		else{
			topo();
		printf("\n");
		}
		
	}
	
	return 0;
}
