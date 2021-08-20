#include <iostream>
using namespace std;
int n, m;
/* run this program using the console pauser or add your own getch, system("pause") or input loop */
int a[6000000];
int b[6000000];
int main(int argc, char** argv) {
	scanf("%d%d", &n, &m);
	for(int i = 1; i <= n; i++)
	scanf("%d", &a[i]);
	for(int i = 1; i <= n; i++)
	{
		b[i] = a[i] - a[i-1];
	}
	int x, y, z;
	for(int i = 1; i <= m; i++)
	{
		scanf("%d%d%d", &x, &y, &z);
		b[x] += z;
		b[y+1] -= z;
	}
	for(int i = 1; i <= n; i++)
	{
		a[i] = a[i-1] + b[i]; 
	}
	int min = 0xfffffff;
	for(int i = 1; i <= n; i++)
	if(min > a[i]) min = a[i];
	
	printf("%d", min);
	return 0;
}
