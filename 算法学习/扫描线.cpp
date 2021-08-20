#include <iostream>
#include <string.h>
#include <stdlib.h>
#include <algorithm>
#define ll long long
#define MAX 2000080
#define rson(x) ((x)<<1|1)
#define lson(x) ((x)<<1)
using namespace std;
/* run this program using the console pauser or add your own getch, system("pause") or input loop */

typedef struct haha
{
	ll lx,rx,h,dcnt;
}line;

line lines[MAX << 1];

typedef struct node
{
	ll len, lnum, rnum, cnt;//cnt ���Ǵ��� lnum,rnum�����ڽ���ʱΨһȷ�����ı��
	// lenȡֵ��ȡ�����²��cntȡ��ȡ�� ͨ��update����� 
}node;
ll x[MAX];
node nodes[MAX << 2];

int cmp1(const void *x, const void *y)
{
	line* a = (line *)x;
	line* b = (line *)y;
	if(a->h > b->h) return 1;
	else return -1;
} 
int cmp2(const void *x, const void *y)
{
	ll* a = (ll *)x;
	ll* b = (ll *)y;
	if(*a > *b) return 1;
	else return -1;
} 
void build(ll o, ll lnum, ll rnum)
{
	nodes[o].lnum = lnum; 
	nodes[o].rnum = rnum;
	nodes[o].len = 0;
	nodes[o].cnt = 0;
	if(lnum == rnum) return;
	ll mid = (lnum + rnum) >> 1;
	build(rson(o), lnum, mid);
	build(lson(o), mid+1, rnum);
}

void update(ll o){
	if(nodes[o].cnt) nodes[o].len = x[nodes[o].rnum+1] - x[nodes[o].lnum];
	else 
	{
		nodes[o].len = nodes[rson(o)].len + nodes[lson(o)].len;
	 } 
}

void modify(ll o, ll L, ll R, ll dcnt)//�Ӹ���ʼ 
{
	ll rnum = nodes[o].rnum;
	ll lnum = nodes[o].lnum;
	 if (x[rnum+1] <= L || x[lnum] >= R)
	{
		//�˴�δ�����ǣ� �����κβ����� ����Ҫ���� 
		return;
	}	
	if(x[rnum+1] <= R && x[lnum] >= L)
	{
		nodes[o].cnt += dcnt;
		update(o);//�������һ�´˴���len, �˴����ϲ������ķ�Χ�Ľڵ��Ҷ�ڵ� 
		return;
	}

	modify(lson(o), L, R, dcnt);	
	modify(rson(o), L, R, dcnt);

	//ֱ��Ҷ�ӽڵ㣬�ǵ�update���ڵ�ĳ���
	update(o); 
}

int main(int argc, char** argv) {
	ll n;
	scanf("%lld", &n);
	for(ll i = 1; i <= n; i++)
	{
		ll x_1,x_2, y_1, y_2;
		scanf("%lld%lld%lld%lld", &x_1, &y_1, &x_2, &y_2);
		x[2*i-1] = x_1;
		x[2*i] = x_2;
		lines[2*i-1].h = y_1;
		lines[2*i-1].lx = x_1;
		lines[2*i-1].rx = x_2;
		lines[2*i-1].dcnt = 1;
		lines[2*i].h = y_2;
		lines[2*i].lx = x_1;
		lines[2*i].rx = x_2;
		lines[2*i].dcnt = -1;
	}
	qsort(x+1, 2*n, sizeof(x[0]), cmp2);
	qsort(lines+1, 2*n, sizeof(lines[0]), cmp1);
	int tot = unique(x + 1, x + 2*n + 1) - (x + 1);
	
	build(1,1,tot-1);
	ll ans = 0;
	for(int i = 1; i < 2*n; i++)
	{
		modify(1, lines[i].lx, lines[i].rx, lines[i].dcnt);
		ans += (nodes[1].len)* (lines[i+1].h - lines[i].h);
	}
	printf("%lld\n", ans);
	return 0;
}
