#include <iostream>
using namespace std;

/* run this program using the console pauser or add your own getch, system("pause") or input loop */
int a[200][200];
int cnt;
int main(int argc, char** argv) {
	int n, m;
	scanf("%d%d", &n, &m);
	for(int i = 0; i < m; i++)
	{
		int c,d;
		scanf("%d%d", &c, &d);
		a[c][d] = 1;
	}
	for(int k = 1; k <= n; k++)
		for(int i = 1; i <= n; i++)
			for(int j = 1; j <= n; j++)
			{
				a[i][j] |= a[i][k] & a[k][j];//注意！还要按位取或 因为多条路通一条就行 
			}
	for(int i = 1; i <= n; i++)
	{
		int flag = 0;
		for(int j = 1; j <= n; j++)
		{
			if(i!=j && a[i][j] == 0 && a[j][i] == 0)
			{
				flag = 1;
			}
		}
		if(flag == 0) cnt++;
	}
	printf("%d", cnt);
	return 0;
}
