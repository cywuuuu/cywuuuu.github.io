#include <iostream>
#define max(x,y) (x) < (y) ? (y) : (x) 
using namespace std;
/* run this program using the console pauser or add your own getch, system("pause") or input loop */
int mat[200][200];
int s[200][200];
int main(int argc, char** argv) {
	int n;
	scanf("%d", &n);
	for(int i = 1; i <= n; i++)
		for(int j = 1; j <= n; j++)
		scanf("%d", &mat[i][j]);
	for(int i = 1; i <= n; i++)
		for(int j = 1; j <= n; j++)
		{
			s[i][j] = s[i][j-1] + s[i-1][j] - s[i-1][j-1] + [i][j];
		}
	int sum = - 0x7fffffff;
	for(int a = 1; a <= n; a++)
		for(int b = 1; b <= n; b++)
			for(int c = a+1; c <= n; c++)
				for(int d = b+1; d <= n; d++)
					sum = max(sum, s[c][d] - s[a-1][d] - s[c][b-1] + s[a-1][b-1] );
				printf("%d", sum);
	return 0;
}
