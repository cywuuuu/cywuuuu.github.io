#include <stdio.h>
//�ô� �����ڴ�С �� ����ʱ�仨����//�������� //���ջ� 
/* run this program using the console pauser or add your own getch, system("pause") or input loop */
long long inf = 2147483647;
	long long dis[101000];
	int u[500008],v[500008],w[500008]; 

int main(int argc, char** argv) {
	int n,m,s,check;
//��¼��i˳λ����ıߵĽڵ� ������Ϣ 
	scanf("%d%d%d",&n,&m,&s);//���� ���� ��ʼ��data
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
				//��dij ��ͬ dijͨ��̰������Сֵ ���� 
				//��bellman �ñ��� ���Դ˴������������Ѿ���� 
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
