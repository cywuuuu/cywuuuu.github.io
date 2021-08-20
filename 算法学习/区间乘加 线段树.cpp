#include <iostream>
#include <string.h>
#include <cmath>
#define lson(x) ((x)<<1)
#define rson(x) ((x)<<1 | 1)
#define ll long long
#define MAX 100086
/* run this program using the console pauser or add your own getch, system("pause") or input loop */

ll a[MAX];
ll n, m, p;

typedef struct aa
{
	ll val;
	ll mult;
	ll add;
	
}node;

node tree[MAX<<2];

void build_tree(ll x, ll L, ll R)
{	
	tree[x].mult = 1;
	tree[x].add = 0;
	if(L == R) 
	{
		tree[x].val = a[L] % p;
		return;
	 } 
	else 
	{
		ll mid = (L + R) >> 1;
		build_tree(lson(x), L, mid);
		build_tree(rson(x), mid+1, R);
		tree[x].val = (tree[lson(x)].val + tree[rson(x)].val) % p;
		return;
	}
	
}
void pushdown(ll x, ll l, ll r)//�·ű�� 
{
	ll mid = (l + r) >> 1;
	tree[rson(x)].val = ((tree[rson(x)].val * tree[x].mult)%p + tree[x].add * (r-mid))%p;//�������� 
	tree[lson(x)].val = ((tree[lson(x)].val * tree[x].mult)%p + tree[x].add * (mid-l+1))%p;
	
	tree[lson(x)].mult = (tree[x].mult * tree[lson(x)].mult)%p;
	tree[rson(x)].mult = (tree[x].mult * tree[rson(x)].mult)%p;
	
	tree[lson(x)].add = (tree[x].mult * tree[lson(x)].add + tree[x].add)%p;
	tree[rson(x)].add = (tree[x].mult * tree[rson(x)].add + tree[x].add)%p;//�·�ԭ����add 
/*	
	tree[lson(x)].add = (tree[x].mult * tree[lson(x)].mult + tree[x].add + tree[lson(x)].add)%p;
	tree[rson(x)].add = (tree[x].mult * tree[rson(x)].mult + tree[x].add + tree[rson(x)].add)%p;
*/	
	tree[x].add = 0;
	tree[x].mult = 1;
	return;
}

void mult(ll x, ll l, ll r, ll L, ll R, ll k)
{
	if( l > R || r < L ) return;
	else if(l >= L && r <= R)
	{//�ݹ鵽�� 
		tree[x].val = (tree[x].val * k) % p;//����l-r�µĺͣ��÷����������update 
		tree[x].mult = (tree[x].mult * k) %p;
		tree[x].add = (tree[x].add * k) % p;
		return;
	}//����ʱ����һ�� tag�ͺ��ˣ� Ҳ��ݹ鵽���� 
	else//����һ�� 
	{
		pushdown(x, l, r);//�·�tag�������¸���tag����ֵ��ֱ���ݹ鵽���������� 
		ll mid = (l + r) >> 1;
		mult(lson(x), l, mid, L, R, k);
		mult(rson(x), mid+1, r, L, R, k);
		// �������� tag ֮��ÿ�ζ�Ҫ���� update ÿ��ֵ 
		tree[x].val = (tree[lson(x)].val + tree[rson(x)].val) % p;
		return;
	}
}

void add(ll x, ll l, ll r, ll L, ll R, ll k)
{
	if( l > R || r < L ) return;
	else if(l >= L && r <= R)
	{
		tree[x].val = (tree[x].val + k*(r-l+1)) % p;
		tree[x].add = (tree[x].add + k) % p;
		return;
	}
	else 
	{
		pushdown(x, l, r);
		ll mid = (l + r) >> 1;
		add(lson(x), l, mid, L, R, k);
		add(rson(x), mid+1, r, L, R, k);
		tree[x].val = (tree[lson(x)].val + tree[rson(x)].val) % p;
		return;
	}
 } 
 
 ll query(ll x, ll l, ll r, ll L, ll R)
{
	if( l > R || r < L ) return 0;
	else if(l >= L && r <= R) 
	{
		return tree[x].val;
	}
	else 
	{
		pushdown(x, l, r);
		ll mid = (l + r) >> 1;//һ��Ҫ����pushdown ��Ϊ���������δ����tag 
		return (query(lson(x), l, mid, L, R)+query(rson(x), mid+1, r, L, R))%p;
	}
 } 
int main(int argc, char** argv) {
	scanf("%lld%lld%lld", &n, &m, &p);
	for(int i = 1; i <= n; i++)
	{
		scanf("%lld", &a[i]);
	}
	build_tree(1, 1, n);
	for(int i = 0; i < m; i++)
	{
		int type = -1;
		scanf("%d", &type);
		ll x, y, k;
		if(type == 1)
		{
			scanf("%lld%lld%lld", &x, &y, &k);
			mult(1, 1, n, x, y, k);
		 } 
		else if(type == 2)
		{
			scanf("%lld%lld%lld", &x, &y, &k);
			add(1, 1, n, x, y, k);			
		}
		else 
		{
			scanf("%lld%lld", &x, &y);
			printf("%lld\n", query(1, 1, n, x, y));
		}
	}
	return 0;
}
