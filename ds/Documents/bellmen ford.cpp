#include<iostream>
using namespace std;
long long dis[10100];
int u[500100],v[500100],w[500100],n,m,s,check;//���Ƕ���һ��check���Ż��� 
const int inf=2147483647;
int main()
{
	cin>>n>>m>>s;//���� 
	for(int i=1;i<=m;i++)
		cin>>u[i]>>v[i]>>w[i];//����� 
	for(int i=1;i<=n;i++)
		dis[i]=inf;//dis�����ʼ�� 
	dis[s]=0;
	for(int k=1;k<=n-1;k++)
	{
		check=0;//check���� 
		for(int i=1;i<=m;i++)
		{
			if(dis[v[i]]>dis[u[i]]+w[i])
			{
				dis[v[i]]=dis[u[i]]+w[i];
				check=1;//���dis��ֵ�ı䣬check��ֵΪ1 
			}	
		}
		if(check==0)
			break;//���û�䣬ֱ������ѭ������Ҫ�˷�ʱ�� 
	}
	for(int i=1;i<=n;i++)
		cout<<dis[i]<<" ";//��� 
	return 0;//��ϰ��
}
