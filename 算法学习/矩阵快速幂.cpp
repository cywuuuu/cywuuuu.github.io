#include <iostream>
#include <string.h>
#define ll long long 
#define MAX 900
const ll mod = 1e9+7;
using namespace std;
/* run this program using the console pauser or add your own getch, system("pause") or input loop */
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
			tmp[i][j] =(tmp[i][j] + (ans[i][k]*x[k][j])%mod)%mod;
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
			tmp[i][j] = (tmp[i][j] + (x[i][k]*x[k][j])%mod)%mod;
	for(int i = 0; i < len; i++)
		for(int j = 0; j < len; j++)
			x[i][j] = tmp[i][j];
}

void matrix_quick_pow(ll y)
{
	for(int i = 0; i < len; i++)
		ans[i][i] = 1;
	while(y)
	{
		if(y&0x1) ans_ans_mult_x(y);
		self_mult_x(y); 
		y >>= 1;
	}
}

int main(int argc, char** argv) {
	ll k;
	scanf("%lld%lld", &len, &k);
	for(int i = 0; i < len; i++)
		for(int j = 0; j < len; j++)
		{
			ll tt;
			scanf("%lld", &tt);
			x[i][j] = tt%mod;
		}
			
	matrix_quick_pow(k);
	for(int i = 0; i < len; i++)
	{
		for(int j = 0; j < len; j++)
			printf("%lld ", ans[i][j]);
		printf("\n");
	}
		

	return 0;
}
