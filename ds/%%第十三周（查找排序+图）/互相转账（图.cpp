#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <bits/stdc++.h>
#define MAX 2300
#define INF 0x7ffffff
#define MAXSIZE 200000
/* run this program using the console pauser or add your own getch, system("pause") or input loop */
typedef struct edgenode
{
	int to;
	double w;
	struct edgenode *next;
}edgenode;

typedef struct vnode
{
	int num;
	edgenode *firstedge;
	double dis;
}vnode,Adjlist[MAX];

typedef struct 
{
	int m,n;
	Adjlist adjlist;
}GraphAdjlist;

void create (GraphAdjlist *G)
{
	int from, to;
	double w;
	scanf("%d%d", &G->n, &G->m);
	for(int i = 0; i < G->m; i++)
	{
		scanf("%d%d%lf", &from, &to, &w);
		edgenode *p = G->adjlist[from].firstedge;
		edgenode *e = (edgenode *)malloc(sizeof(edgenode));
		e->to = to;
		e->w = 1.0 - w/100;
		G->adjlist[from].firstedge = e;
		e->next = p;
		
		p = G->adjlist[to].firstedge;
		e = (edgenode *)malloc(sizeof(edgenode));
		e->to = from;
		e->w = 1.0 - w/100;
		G->adjlist[to].firstedge = e;
		e->next = p;
	}
	
}
typedef struct prior_que
{
	vnode data[100000];
	int rear;
	int front;
}prior_que;

prior_que q;

void init();
void push(vnode u);
void pop();
int isempty();
vnode top();
void dij(GraphAdjlist *G)
{
	int a, b;
	scanf("%d%d", &a, &b);
	double dis[MAX];
	int vis[MAX];
	for(int i = 0; i <= G->n; i++)
	{
		dis[i] = 0;
		vis[i] = 0;
	}
	dis[a] = 1;
	vnode k = G->adjlist[a];
	k.dis = dis[a];
	k.num = a;
	push(k);
	while(isempty() == 0)
	{
		vnode u = top();
		pop();
		if(vis[u.num] == 0)
		{
			vis[u.num] = 1;
			for(edgenode *e = G->adjlist[u.num].firstedge; e; e = e->next)
			{
				if(vis[e->to] == 0)
				{
					if(dis[e->to] < dis[u.num] * e->w)
					{
						dis[e->to] = dis[u.num] * e->w;
						vnode v = G->adjlist[e->to];
						v.dis = dis[e->to];
						v.num = e->to;
						push(v);
					}
				}
			}
		 } 
	}
	printf("%.8lf",100/dis[b]);
	
	
}
int main(int argc, char** argv) {
	GraphAdjlist G;
	init();
	create(&G);
	dij(&G);
	return 0;
}

void init()
{
	memset(q.data,0,sizeof(q.data));
	q.front = 0;
	q.rear = -1;
}
void push(vnode u)
{
	q.rear++;
	q.data[q.rear] = u;
	for(int i = q.rear; q.data[i].dis > q.data[i-1].dis && i > 0; i--)
	{
		vnode tmp;
		tmp = q.data[i];
		q.data[i] = q.data[i-1];
		q.data[i-1] = tmp;
	}
}
void pop()
{
	q.front++;
}
int isempty()
{
	if(q.rear <= q.front - 1) return 1;
	else return 0; 
}
vnode top()
{
	return q.data[q.front];
}
