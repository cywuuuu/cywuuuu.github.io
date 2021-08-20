#include <iostream>
#include <math.h>
#define max(x,y) (x)>(y) ? (x):(y)
using namespace std;
int a[300086][30];//a[i][j]维护的是 从i往后 的 2^j位的最大值 
/* run this program using the console pauser or add your own getch, system("pause") or input loop */
inline int read()
{
	int x=0,f=1;char ch=getchar();
	while (ch<'0'||ch>'9'){if (ch=='-') f=-1;ch=getchar();}
	while (ch>='0'&&ch<='9'){x=x*10+ch-48;ch=getchar();}
	return x*f;
}
int main(int argc, char** argv) {
	int n = read();
	int m = read();
	for(int i = 1; i <= n; i++)//从1开始！！ 
	a[i][0] = read();
	
	int kk = (int)log2(n);
	for(int j = 1; j <= kk;j++)
	for(int i = 1; i <= n; i++)
	 a[i][j] = max(a[i][j-1], a[i+(1<<(j-1))][j-1]);
	for(int i = 0; i < m; i++)
	{
		int l = read();
		int r = read();
		int b =  (int)(log(r-l+1)/log(2));
		printf("%d\n", max(a[l][b],a[r-(1<<b)+1][b]));
	}
	return 0;
}
