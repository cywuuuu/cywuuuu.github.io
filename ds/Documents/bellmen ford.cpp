#include<iostream>
using namespace std;
long long dis[10100];
int u[500100],v[500100],w[500100],n,m,s,check;//我们定义一个check，优化用 
const int inf=2147483647;
int main()
{
	cin>>n>>m>>s;//输入 
	for(int i=1;i<=m;i++)
		cin>>u[i]>>v[i]>>w[i];//读入边 
	for(int i=1;i<=n;i++)
		dis[i]=inf;//dis数组初始化 
	dis[s]=0;
	for(int k=1;k<=n-1;k++)
	{
		check=0;//check归零 
		for(int i=1;i<=m;i++)
		{
			if(dis[v[i]]>dis[u[i]]+w[i])
			{
				dis[v[i]]=dis[u[i]]+w[i];
				check=1;//如果dis数值改变，check赋值为1 
			}	
		}
		if(check==0)
			break;//如果没变，直接跳出循环，不要浪费时间 
	}
	for(int i=1;i<=n;i++)
		cout<<dis[i]<<" ";//输出 
	return 0;//好习惯
}
