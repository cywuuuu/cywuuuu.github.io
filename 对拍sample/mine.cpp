#include <iostream>
#define lowbit(x) ((x) & (-x))
#define ll long long
#define MAX 800000
using namespace std;
/* run this program using the console pauser or add your own getch, system("pause") or input loop */
ll dx[MAX];
void update(ll pos,ll val)
{
	while(pos < MAX)
	{
		dx[pos] += val;
		pos += lowbit(pos);
	}
}

ll query(ll pos)
{
	ll ret = 0;
	while(pos > 0)
	{
		ret += dx[pos];
		pos -= lowbit(pos);
	}
	return ret;
}
int main(int argc, char** argv) {
	ll n,m;
	scanf("%lld%lld", &n, &m);
	ll qian, hou;
	qian = 0;
	for(int i = 1; i <= n; i++)
	{
		scanf("%lld", &hou);
		update(i, hou - qian);
		qian = hou;
	}
	int type = -1;
	for(int i = 1; i <= m; i++)
	{
		scanf("%d", &type);
		if(type == 1)
		{
			ll l,r,k;
			scanf("%lld%lld%lld",&l, &r, &k);
			update(l, k);
			update(r+1, -k);
		}
		else 
		{
			ll pos;
			scanf("%lld", &pos);
			printf("%lld\n", query(pos));
		}
	}
	return 0;
}
