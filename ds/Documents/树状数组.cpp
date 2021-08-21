#include <stdio.h>
#define lowbit(x) ((x) &-(x))
/* run this program using the console pauser or add your own getch, system("pause") or input loop */
int tree[1000008];int n, m;
int add(int i ,int a)
{
	while(i <= n)//从一开始 那么就要有= 
	{
		tree[i] += a;
		i = i + lowbit(i) ;
	}
}
int sum(int i)
{
	int sum = 0;
	while(i)
	{
		sum += tree[i];
		i = i -lowbit(i);
	}
	return sum;
}

int main(int argc, char** argv) {
	
	scanf("%d%d", &n , &m);
	int a;
	for(int i = 1; i <= n; i++)//请从1开始 
	{
		scanf("%d", &a);
		add(i,a);
	}
	int type; 
	while(m--)
	{
		scanf("%d", & type);
		if(type == 1)
		{
			int x;int k;
			scanf("%d%d", &x, &k); 
			add(x,k); 
		}
		else 
		{
			int x,y;
			scanf("%d%d", &x, &y); 
			printf("%d\n",sum(y) - sum (x-1));
		}
	}
	return 0;
}
