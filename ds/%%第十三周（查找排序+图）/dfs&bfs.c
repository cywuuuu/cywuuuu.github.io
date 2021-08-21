#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX 3000
/* run this program using the console pauser or add your own getch, system("pause") or input loop */
//邻接表法 
int vis[MAX];
int nv,ne;
int del;
int cun[MAX][3];
typedef struct edgenode
{
	int to;
	struct edgenode* next;
}edgenode;

typedef struct vnode
{
	int data;
	struct edgenode* firstedge;
}vnode,Adjlist[MAX];

typedef struct 
{
	Adjlist adjlist;
	int nv,ne;
}GraphAdjlist;
typedef struct 
{
	int front;
	int rear;
	int data[20000];
}queue;
queue q;
void init()
{
	q.rear = -1;
	q.front = 0;
	memset(q.data,0,sizeof(q.data));
}
void dequeue(int *a)
{
	*a = q.data[q.front];
	q.front++;	
}
void enqueue(int a)
{
	q.rear++;
	q.data[q.rear] = a;
}
int isempty()
{
	if(q.rear <= q.front - 1) return 1;
	else return 0;	
}
void create1(GraphAdjlist *G)
{
	G->nv = nv - 1; G->ne = ne;
	int tot = 0;
	memset(G->adjlist,0,sizeof(G->adjlist));
	for(int i = 0; i < G->ne; i++)
	{
		if(del != cun[i][0] && del != cun[i][1])
		{
			edgenode *e = (edgenode *)malloc(sizeof(edgenode));
			e->to = cun[i][1];
			edgenode *p = G->adjlist[cun[i][0]].firstedge;
			if(p == NULL)
			{
				G->adjlist[cun[i][0]].firstedge = e;
				e->next = NULL;
			}
			else if(p->next == NULL|| e->to < p->to)
			{
				if(e->to < p->to)
				{
					e->next = G->adjlist[cun[i][0]].firstedge;
					G->adjlist[cun[i][0]].firstedge = e;
				}
				else 
				{
					e->next = p->next;p->next = e;
				}
			}
			else
			{
				edgenode *r = p;
				p = p->next;
				while(p)
				{  
				if(e->to < p->to) break;
					p = p->next;
					r = r->next;
				}
				e->next = p;
				r->next = e;
			}
			//******
			e = (edgenode *)malloc(sizeof(edgenode));
			e->to = cun[i][0];
			p = G->adjlist[cun[i][1]].firstedge;
			if(p == NULL)
			{
				G->adjlist[cun[i][1]].firstedge = e;
					e->next = NULL;
			}
			else if(p->next == NULL|| e->to < p->to)
			{
				if(e->to < p->to)
				{
					e->next = G->adjlist[cun[i][1]].firstedge;
					G->adjlist[cun[i][1]].firstedge = e;
				}
				else 
				{
					e->next = p->next;p->next = e;
				}
			}
			else
			{
				edgenode *r = p;
				p = p->next;
				while(p)
				{
					if(e->to < p->to) break;
					p = p->next;
					r = r->next;
				}
				e->next = p;
				r->next = e;
			}
		}
		else tot++;
	}
	G->ne -= (tot/2);
}
void create2(GraphAdjlist *G)
{
	G->nv = nv; G->ne = ne;
	for(int i = 0; i < G->ne; i++)
	{
		G->adjlist[i].firstedge = NULL;
	}
	for(int i = 0; i < G->ne; i++)
	{
		if(cun[i][0] == 0 && cun[i][1] == 1)
		{
			printf("  ");
		}
			edgenode *e = (edgenode *)malloc(sizeof(edgenode));
			e->to = cun[i][1];
			edgenode *p = G->adjlist[cun[i][0]].firstedge;
			if(p == NULL)
			{
				G->adjlist[cun[i][0]].firstedge = e;
					e->next = NULL;
			}
			else if(p->next == NULL || e->to < p->to)
			{
				if(e->to < p->to)
				{
					e->next = G->adjlist[cun[i][0]].firstedge;
					G->adjlist[cun[i][0]].firstedge = e;
				}
				else 
				{
					e->next = p->next;p->next = e;
				}
			}
			else
			{
				edgenode *r = p;
				p = p->next;
				while(p)
				{
					if(e->to < p->to) break;
					p = p->next;
					r = r->next;
				}
				e->next = p;
				r->next = e;
			}
			//******
			e = (edgenode *)malloc(sizeof(edgenode));
			e->to = cun[i][0];
			p = G->adjlist[cun[i][1]].firstedge;
			if(p == NULL)
			{
				G->adjlist[cun[i][1]].firstedge = e;
					e->next = NULL;
			}
			else if(p->next == NULL|| e->to < p->to)//****!!!!插入链表要小心！！插入在第一个前怎么办！！ 
			{
				if(e->to < p->to)
				{
					e->next = G->adjlist[cun[i][1]].firstedge;
					G->adjlist[cun[i][1]].firstedge = e;
				}
				else 
				{
					e->next = p->next;p->next = e;
				}
			}
			else
			{
				edgenode *r = p;
				p = p->next;
				while(p)
				{
					if(e->to < p->to) break;
					p = p->next;
					r = r->next;
				}
				e->next = p;
				r->next = e;
			}
			
	}
}
void dfs(GraphAdjlist* G,int k)
{
	
	vis[k] = 1;printf("%d ", k);
	//
	for(edgenode *p = G->adjlist[k].firstedge; p; p = p->next)
	{
		if(vis[p->to]==0)
		{
			dfs(G, p->to);
		}
	}
	
}
void bfs(GraphAdjlist* G, int k)
{
	init();
	memset(vis,0,sizeof(vis));
	enqueue(k);
	vis[k] = 1; printf("%d ", k);
	while(isempty() == 0)
	{
		int u;
		dequeue(&u);
		for(edgenode *p = G->adjlist[u].firstedge; p; p = p->next)
		{
			if(vis[p->to]==0)
			{
				printf("%d ", p->to);
				enqueue(p->to);
				vis[p->to] = 1;
			}
		}
	}
}
void prt(GraphAdjlist* G)
{
	for(int i = 0; i < G->nv; i++)
	{
		printf("%d ", i);
		for(edgenode *p = G->adjlist[i].firstedge; p ; p = p->next)
		{
			printf("->%d", p->to);
		}
		printf("\n");
	}
}

int main(int argc, char** argv) {
	
	GraphAdjlist G1, G2;
	scanf("%d%d",&nv,&ne);
	for(int i = 0; i < ne; i++)
	{
		scanf("%d%d", &cun[i][0], &cun[i][1]);
	}
	scanf("%d", &del);
	create1(&G1);
//	prt(&G1);
	create2(&G2);	
//	prt(&G2); 
	memset(vis,0,sizeof(vis));
	dfs(&G2,0);printf("\n");
	bfs(&G2,0);printf("\n");
	memset(vis,0,sizeof(vis));
	dfs(&G1,0);printf("\n");
	bfs(&G1,0);printf("\n");
	return 0;
}
/*
9 10
0 1
0 2
1 4
1 3
1 8
8 6
3 6
7 2
7 5
5 2
3

6 7
0 1
0 2
1 3
1 5
1 2
2 5
3 5
2
0 1 2 5 3
0 1 2 3 5
0 1 3 5
0 1 3 5

9 11
5 6
1 8
7 4
2 1
6 8
2 3
1 7
6 0
4 5
0 1
3 4

3 3
0 1
2 1
0 2
2

4 6
0 3
0 2
3 2
2 1
0 1
3 1
2

13 17
6 11
5 6
7 5
10 11
7 1
7 9
3 7
10 1
9 1
12 1
3 4
4 2
9 0
9 8
2 8
12 0
8 0
8

*/
