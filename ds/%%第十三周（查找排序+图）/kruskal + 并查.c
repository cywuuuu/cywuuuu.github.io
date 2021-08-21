#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define MAX 100
typedef struct edgenode 
{
	int w;
	int u,v;
	int data;
}edgenode;
edgenode edge[MAX*MAX];
int ans[MAX * MAX];
int sum = 0;
/* run this program using the console pauser or add your own getch, system("pause") or input loop */
int s[MAX*MAX];
int ne, nv;
int tot = 0;
int find(int u)
{
	return s[u] == u ? u : find(s[u]);//往上溯源 
}
int cmp(const void *x, const void *y)
{
	edgenode *a = (edgenode *) x;
	edgenode *b = (edgenode *) y;
	return a->w - b->w;
}
int cmp2(const void *x, const void *y)
{
	int *a = (int *) x;
	int *b = (int *) y;
	return *a - *b;
}
void kruskal()
{
	for(int i = 1; i <= nv; i++)
	{
		s[i] = i;
	}
	qsort(edge+1, ne, sizeof(edge[0]), cmp);//这里加一很重要！！！从一开始的并查！！ 
	for(int i = 1; i <= ne; i++)
	{
		int a = find(edge[i].u);
		int b = find(edge[i].v);
		if(a == b) continue;
		s[b] = a;
		sum += edge[i].w;
		ans[tot] = edge[i].data;tot++; 
	}
	
}

int main(int argc, char** argv) {
	scanf("%d%d", &nv, &ne);
	for(int i = 1; i <= ne; i++)
	{
		scanf("%d%d%d%d",&edge[i].data, &edge[i].u, &edge[i].v, &edge[i].w );
	}
	kruskal();
	qsort(ans,tot, sizeof(ans[0]), cmp2  );
	printf("%d\n",sum);
	for(int i = 0; ans[i]; i++)
	{
		printf("%d ", ans[i]);
	}
	return 0;
}
/*
6 10
1 0 1 600
2 0 2 100
3 0 3 500
4 1 2 500
5 2 3 500
6 1 4 300
7 2 4 600
8 2 5 400
9 3 5 200
10 4 5 600

3 3
1 0 1 600
2 0 2 600
3 1 2 700

7 11
1 0 1 500
2 0 2 700
3 1 2 900
4 2 4 800
5 2 3 700
6 3 4 500
7 1 3 1500
8 1 5 600
9 3 5 800
10 5 6 1100
11 3 6 900

*/
