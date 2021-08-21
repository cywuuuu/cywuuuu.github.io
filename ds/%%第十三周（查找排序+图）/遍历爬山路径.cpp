#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define MAX 10000

//多联通分量
//vis 

/* run this program using the console pauser or add your own getch, system("pause") or input loop */
typedef struct edgenode
{
	int to;
	int data;
	struct edgenode *next;
}edgenode;
typedef struct adj
{
	int data;
	edgenode *firstedge;
}vnode,Adjlist[MAX];

typedef struct adjgraph
{
	int ne,nv;
	Adjlist adjlist;
}GraphAdjlist;
int vis[4*MAX];
char path[1000][1000];
char ans[1000];
int tot = 0;
void create(GraphAdjlist *G)
{
	scanf("%d%d", &G->nv, &G->ne);
/*	for(int i = 0; i < G->nv; i++)
	{
		G->adjlist[i].firstedge = NULL;
	}*/
	for(int i = 0; i < G->ne; i++)
	{
		int t;
		int v1, v2;
		scanf("%d%d%d", &t, &v1, &v2);
		//1->2
		edgenode *e = (edgenode *) malloc(sizeof(edgenode));
		e->to = v2;
		e->data = t;
		edgenode *p = G->adjlist[v1].firstedge;
		e->next = p;
		G->adjlist[v1].firstedge = e;
		//2->1
		e = (edgenode *) malloc(sizeof(edgenode));
		e->to = v1;
		e->data = t;
		p = G->adjlist[v2].firstedge;
		e->next = p;
		G->adjlist[v2].firstedge = e;
	}

}
void dfs(GraphAdjlist *G, int now ,int to, int cnt)
{
	if(now == to) 
	{
		memcpy(path[tot],ans, sizeof(ans[0])*cnt);
		tot++;
		return;
	}
	vis[now] = 1;
	for(edgenode *e = G->adjlist[now].firstedge; e ; e = e->next)
	{
		if(vis[e->to] == 0)
		{
			ans[cnt] = e->data;
			dfs(G, e->to, to, cnt+1);
		}
	}
	vis[now] = 0;
}
int cmp(const void *x, const void *y)
{
	if(strcmp((char *)x, (char *)y) == 0) return 0;
	else return strcmp((char *)x, (char *)y);
}
int main(int argc, char** argv) {
	GraphAdjlist G;
	create(&G);
	dfs(&G, 0, G.nv - 1,0);
/*	for(int i = 0; path[i][0]; i++)
	{
		for(int j = 0; path[i][j]; j++ )
		{
			printf("%d ", path[i][j]);
		}
		printf("\n");
	}*/
	qsort(path, tot, sizeof(path[0]), cmp);
	//printf("*****");
	for(int i = 0; path[i][0]; i++)
	{
		for(int j = 0; path[i][j]; j++ )
		{
			printf("%d ", path[i][j]);
		}
		printf("\n");
	}
	return 0;
}
/*
6 8
1 0 1
2 1 2
3 2 3
4 2 4
5 3 5
6 4 5
7 0 5
8 0 1
*/
