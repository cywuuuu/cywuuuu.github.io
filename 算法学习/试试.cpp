#include <iostream>
#include <math.h>
#include <string.h>
#define MAX 4
#define ll long long 
using namespace std;
ll multer [4][4][20];
ll lmult
/* run this program using the console pauser or add your own getch, system("pause") or input loop */
ll n, m;
void gen_multer()
{
	multer [1][1][1] = 1; 
	for(int i = 1; i <= 18; i++)
	{
		multer[1][1][i] = (multer[1][1][i] * 10)%m;
		for(int j = 1; j <= 3; j++)
			for(int k = 1; k <= 3; k++)
			{
				if(i == 1 && j == 1) continue;
				if(i <= j)multer[j][k][i] = 1;
			}
	}
}

ll len;
ll ans[MAX][MAX];
ll x[MAX][MAX];//ÇóxµÄy´ÎÃÝ mod 
ll tmp[MAX][MAX];
void ans_ans_mult_x(ll y)
{
	memset(tmp,0,sizeof(tmp));
	for(int i = 0; i < len; i++)	
		for(int j = 0; j < len; j++)
			for(int k = 0; k < len; k++)
			tmp[i][j] =(tmp[i][j] + (ans[i][k]*x[k][j])%m)%m;
	for(int i = 0; i < len; i++)
		for(int j = 0; j < len; j++)
			ans[i][j] = tmp[i][j];
}

void self_mult_x(ll y)
{
	memset(tmp,0,sizeof(tmp));
	for(int i = 0; i < len; i++)
		for(int j = 0; j < len; j++)
			for(int k = 0; k < len; k++)
			tmp[i][j] = (tmp[i][j] + (x[i][k]*x[k][j])%m)%m;
	for(int i = 0; i < len; i++)
		for(int j = 0; j < len; j++)
			x[i][j] = tmp[i][j];
}

void matrix_quick_pow(ll y, ll slide)
{
	for(int i = 0; i < len; i++)
		ans[i][i] = 1;
	memcpy(x, multer[][][slide], sizeof(x));
	while(y)
	{
		if(y&0x1) ans_ans_mult_x(y);
		self_mult_x(y); 
		y >>= 1;
	}
}

void get_lmult(ll n)
{
	int typecnt = log(n) + 1;
	for(int i = 1, i < typecnt; i++)
	{
		if(i == 1) matrix_quick_pow(9, 1);
		else matrix_quick_pow(10, i);
	}
}

int main(int argc, char** argv) {
	scanf("%d%d", &n, &m);
	 
	return 0;
}
