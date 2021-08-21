#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX 300
#define INF 2000008
/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int graph[MAX][MAX];
int n, m;
void floyd()
{
	for(int k = 1; k <= n; k++)
	{
		for(int i = 1; i <= n; i++)
		{
			if(graph[i][k] != INF)
			{
				for(int j = 1; j <= n; j++)
				{
					if(graph[i][j] > graph[i][k] + graph[k][j] )
					{
						graph[i][j] = graph[i][k] + graph[k][j];
					}
				}
			}
		}
	}
	printf("%d\n", graph[1][n]);
}
int main(int argc, char** argv) {
	scanf("%d", &n);
	for(int i = 1; i <= n; i++)
	{
		for(int j = 1; j <= n; j++)
		{
			if(i == j) graph[i][j] = 0;
			else
			graph[i][j] = INF;
		}
	}
	for(int i = 1; i <= n; i++)
	{
		for(int j = i+1; j <= n; j++)
		{
			scanf("%d", &graph[i][j]); 
		}
	}
	floyd();
	return 0;
}
