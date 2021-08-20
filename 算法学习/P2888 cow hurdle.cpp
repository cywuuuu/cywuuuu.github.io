#include <iostream>
#include <string.h>
#define inf 0x7fffffff
using namespace std;
/* run this program using the console pauser or add your own getch, system("pause") or input loop */


int e[500][500];

int main(int argc, char** argv) {
	int n,m,t;
	for(int i = 0; i < 500; i++)
		for(int j = 0; j < 500; j ++)
			e[i][j] = inf;
	scanf("%d%d%d", &n, &m, &t);
	for(int i = 0; i < m; i++)
	{
		int a,b,h;
		scanf("%d%d%d", &a, &b, &h);
		e[a][b] = min(e[a][b], h);
	}
	for(int k = 1; k <= n; k ++)
	{
		for(int i = 1; i <= n; i++)
			for(int j = 1; j <= n; j++)
			{
				e[i][j] = min(e[i][j], max(e[i][k], e[k][j]));
			}
	}
	for(int i = 1; i <= t; i++)
	{
		int a,b;
		scanf("%d%d", &a, &b);
		if(e[a][b] != inf)
		printf("%d\n", e[a][b]);
		else printf("-1\n");
	}
	return 0;
}
