#include <stdio.h>
#define MAX 2000
/* run this program using the console pauser or add your own getch, system("pause") or input loop */
typedef struct 
{
	int x1,y1;
	int x2,y2;
}Edge;
Edge edge[MAX];
int vis[MAX];int n;
int len[MAX][4];
int cnt = 0 ;
int check(int i ,int j )
{
	if(edge[i].x1 == edge[j].x2 && edge[i].y1 == edge[j].y2)
	{
		return 1;//代表 i 是 j的后继 
	}
	if(edge[j].x1 == edge[i].x2 && edge[j].y1 == edge[i].y2)
	{
		return -1;//代表 j 是 i的后继 
	}
	else return 0; //哦豁完蛋 
};

void search(int i)
{
	vis[i] = 1;	len[cnt][3]++;
	for(int j = 0; j < n; j++)
	{
		if(vis[j] == 0)
		{
			if(check(i,j) == 1)
			{
			len[cnt][1] = edge[j].x1;
			len[cnt][2] = edge[j].y1;
			search(j);
			}
		}
	}
	for(int j = 0; j < n; j++)
	{
		if(vis[j] == 0)
		{
			if(check(i,j) == -1)
			{
				search(j);
			}
		}
	}
}
int main(int argc, char** argv) {
	
	scanf("%d", &n);
	for(int i = 0; i < n; i++)
	{
		scanf("%d%d%d%d",&edge[i].x1,&edge[i].y1,&edge[i].x2,&edge[i].y2);
	}
	for(int i = 0; i < n; i++)
	{
		if(vis[i] == 0)
		{
			search(i);
		cnt++;
		}
	}
	int maxi = 0;
	for(int i = 0; i < cnt; i++)
	{
		if(len[i][3] > len[maxi][3]) maxi = i;
	}
	printf("%d %d %d", len[maxi][3], len[maxi][1], len[maxi][2]); 
	return 0;
}
