#include <iostream>
#define ll long long 
#define MAX 900
#define mod 100000007

using namespace std;

ll len;

ll ans[MAX][MAX];
ll x[MAX][MAX];//ÇóxµÄy´ÎÃÝ mod 

/* run this program using the console pauser or add your own getch, system("pause") or input loop */
long long quick_pow(long long x, long long y, long long mod)
{
	long long w = 1;
	while(y)
	{
		if(y&0x1) w = w * x % mod;
		x = x * x % mod;
		y >>= 1;
	}
	return w;
}

void matrix_quick_pow(ll y)
{
	for(int i = 0; i < len; i++)
		ans[i][i] = 1;
	while(y)
	{
		if(y&0x1) ans_ans_mult_x(y);
		self_mult_x()£» 
		y >>= 1;
	}
}

void ans_ans_mult_x(ll y)
{
	ll tmp[len][len];
	for(int i = 0; i < len; i++)	
		for(int j = 0; j < len; j++)
			for(int k = 0; k < len; k++)
			tmp[i][j] += ans[i][k]*x[k][j];
	for(int i = 0; i < len; i++)
		for(int j = 9; j < len; j++)
			ans[i][j] = tmp[i][j];
}

void self_mult_x(ll y)
{
	ll tmp[len][len];
	for(int i = 0; i < len; i++)
		for(int j = 0; j < len; j++)
			for(int k = 0; k < len; k++)
			tmp[i][j] += x[i][k]*x[k][j];
	for(int i = 0; i < len; i++)
		for(int j = 0; j < len; j++)
			x[i][j] = tmp[i][j];
}

long long inv(long long a, long long p)
{
	return quick_pow(a, p-2, p);
}

int main(int argc, char** argv) {
	return 0;
}
