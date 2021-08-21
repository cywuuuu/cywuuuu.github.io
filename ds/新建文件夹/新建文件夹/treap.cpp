#include <iostream>
#include <bits/stdc++.h>
const int MAX = 1e6+8;
const int INF = 1e9;
/* run this program using the console pauser or add your own getch, system("pause") or input loop */
int ch[MAX][2];
int val[MAX];
int prio[MAX];//priority
int cnt[MAX];
int size[MAX];
int idx, root;//gen

int create(int v)
{
	idx++;
	val[idx] = v;
	prio[idx] = rand();
	cnt[idx] = 1;
	size[idx] = 1;
	return idx;//tell them where i am
}

void update(int id)
{
	size[id] = cnt[id] + size[ch[id][0]] + size[ch[id][1]];
}

void init()//建立最初的根和两个端点 
{
	root = create(-1*INF);
	ch[root][1] = create(INF);
	update(root);
}

void rotate(int &o, int d)//要变啊 
{
	int tmp = ch[o][d^1];
	ch[o][d^1] = ch[tmp][d];
	ch[tmp][d] = o;
	o = tmp;
	update (o);
	update (ch[o][d]);
}//d==0,左旋 d==1右旋 

void insert(int &id, int x)
{
	if(id==0) {id = create(x); return;} 

		if(x > val[id]) 
		{
			insert(ch[id][1],x);
			if(prio[id] < prio[ch[id][1]]) rotate(id,0);
		}
		else if(x == val[id]) cnt[id]++;
		else {
			insert(ch[id][0],x);
			if(prio[id] < prio[ch[id][0]]) rotate(id,1);
		}
	
	update(id);
}

void del(int &id, int x)//待改 
{
	if(id==0) return;
	if (val[id] == x)
	{
		if(cnt[id]>1) {cnt[id]--;update(id);return ;}
		
			if(ch[id][0]==0 && ch[id][1]==0) 
			{
				id=0;
			}
			else
			{
				/*int d = prio[ch[id][0]] >= prio[ch[id][0]] ? 0 : 1;
				rotate(id,d^1);//把待删除的放下去 
				del(ch[id][d^1],x);*///要删除的目标在原来prio更大的反方向的 所以 d^1 
				if(!ch[id][1] || prio[ch[id][0]] > prio[ch[id][0]])
				{
					rotate(id,1);
					del(ch[id][1],x);
				}
				else{
					rotate(id,0);
					del(ch[id][0],x);
				}/**/
			
			update(id);
			}
		update(id);//???
		return ;
	}
	else
	{
		x < val[id] ? del (ch[id][0],x) : del (ch[id][1],x);
	}
	update(id);
}

int rank(int id, int x)
{
	if(id==0) return -2;
	if(val[id] == x) return size[ch[id][0]] + 1;
	else if(val[id] < x)
	{
		return size[ch[id][0]] + cnt[id] + rank(ch[id][1],x);
	}
	else 
	{
		return rank(ch[id][0],x);
	}
	
}

int find(int id, int rk)
{
	if(id==0) return INF;
	if(rk <= size[ch[id][0]]) return find(ch[id][0],rk);
	else if( rk <= size[ch[id][0]] + cnt[id]) return val[id];
	else return find(ch[id][1],rk - size[ch[id][0]] - cnt[id]);
}

int getpre(int x)
{
	int id = root;
	int pre;
	while(id)
	{
		if(val[id] < x) 
		{pre = val[id]; id = ch[id][1];
		}
		else
		{
			id = ch[id][0];
		}
	}
	return pre;
}
int getnext(int x)
{
	int id = root;
	int pre;
	while(id)
	{
		if(val[id] > x) 
		{pre = val[id]; id = ch[id][0];
		}
		else
		{
			id = ch[id][1];
		}
	}
	return pre;
}
int main(int argc, char** argv) {
	int n,type,x;
	scanf("%d",&n);
	init();
	while(n--)
	{
		scanf("%d%d",&type,&x);
		if(type == 1) insert(root,x);
		else if(type == 2) del(root,x);
		else if(type == 3) printf("%d\n",rank(root,x)-1);
		else if(type == 4) printf("%d\n",find(root,x+1));
		else if(type == 5) printf("%d\n",getpre(x));
		else if(type == 6) printf("%d\n",getnext(x));
	}
	return 0;
}
