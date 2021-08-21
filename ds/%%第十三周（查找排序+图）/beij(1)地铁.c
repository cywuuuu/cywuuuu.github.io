#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define MAX 50
#define INF 99999
/* run this program using the console pauser or add your own getch, system("pause") or input loop */
//O(mn)的垃圾队列版 
typedef struct edgenode 
{
	int line;
	int tonum;
	int w;
	char to[50];
	struct edgenode *next; 
	
}edgenode;

typedef struct 
{
	int dis;
	int num;
	int exch;
	char ch[50];
	int line;	
	edgenode *firstedge;
} vnode,Adjlist[MAX*MAX];

typedef struct adj
{
	int ne,nv;
	Adjlist adjlist;
}GraphAdjlist;
typedef struct prior_que
{
	vnode data[10000];
	int rear;
	int front;
}prior_que;

prior_que q;
int vis[MAX*MAX];//用建图后的编号记录站名 
int pre[MAX*MAX];//试试看先 
int dis[MAX*MAX];
int len = 0;
char s1[50];char s2[50];
int tot = 0;
GraphAdjlist *G;
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
vnode top()
{
	return q.data[q.front];
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


void print(GraphAdjlist *G)
{
	for(int i = 0; i < tot; i++)
	{
		printf("V:%s(%d)", G->adjlist[i].ch,G->adjlist[i].num);
		for(edgenode *e = G->adjlist[i].firstedge; e; e = e->next)
		{
			printf("->%d%s(%d)",e->line,e->to,e->tonum);
		}
		printf("\n");
	}
 } 
void create (GraphAdjlist *G)
{
	int line;
	FILE *fp = fopen("bgstations.txt","r");
	fscanf(fp,"%d", &line);
	for(int i = 0; i < line; i++)
	{
		int l;int n;
		fscanf(fp,"%d %d", &l, &n);
		char v1[300],v2[300];
		char *old = v1, *in = v2;
		int exch1,exch2;
		n--;
		fscanf(fp,"%s%d",old, &exch1);
		
		while(n--)
		{
			fscanf(fp,"%s%d", in, &exch2);
//			printf("%s%s",old,in);
			int flag1 = -1,flag2 = -1;
			for(int j = 0; j < tot; j ++)
			{
				if(strcmp(old, G->adjlist[j].ch) == 0)
				{
					flag1 = j;
				}
			}
			
			if(flag1 == -1)
			{
				strcpy(G->adjlist[tot].ch, old);
				G->adjlist[tot].exch = exch1;
				G->adjlist[tot].num = tot;
				G->adjlist[tot].line = l;
				flag1 = tot; tot++;
			}
			
			edgenode *e1 = (edgenode *)malloc(sizeof(edgenode));
			e1->line = l;
			strcpy(e1->to, in); 
			e1->next = G->adjlist[flag1].firstedge;
			G->adjlist[flag1].firstedge = e1;
			
			//***************
		
			for(int j = 0; j < tot; j ++)
			{
				if(strcmp(in, G->adjlist[j].ch) == 0)
				{
					flag2 = j;
				}
			}
			if(flag2 == -1)
			{
				strcpy(G->adjlist[tot].ch, in);
				G->adjlist[tot].exch = exch2;
				G->adjlist[tot].num = tot;
				G->adjlist[tot].line = l;
				flag2 = tot; tot++;
			}
			edgenode *e2 = (edgenode *)malloc(sizeof(edgenode));
			e2->line = l;
			strcpy(e2->to, old);
			e2->next = G->adjlist[flag2].firstedge;
			G->adjlist[flag2].firstedge = e2;
			
			e1->tonum = flag2;
			e2->tonum = flag1;
			e1->w = e2->w = 1;
			char *tmp = old;
			old = in;
			in = tmp;
		//	print(G);
		}
		
	}	
	fclose(fp);
}
int oldline = -1, newline = -1;
int next[MAX*MAX] = {0};
void print_path(int j, int dest)
{
	if(j == dest) 
	{
		printf("%s", s1); 
		newline = G->adjlist[j].line;return;
	}
	next[pre[dest]] = dest;
	print_path(j, pre[dest]);
	oldline = newline;
	for(edgenode *e = G->adjlist[dest].firstedge; e; e = e->next)
	{
		if(next[dest] == e->tonum) 
		{
			newline = e->line; break;
		}
		
	}
	if(oldline != newline && j != dest)
	{
			printf("-%d(%d)-%s",oldline, len+1 ,G->adjlist[dest].ch);
			len = 0;
	}
	else 
	{
		len++;
	}
}
void dijkstra(GraphAdjlist *G)
{
	memset(pre,-1,sizeof(pre));
	
	gets(s1);gets(s2);
	int s = -1;int dest = -1;
	for(int i = 0; i < tot; i++)
	{
		if(strcmp(s1, G->adjlist[i].ch) == 0)
		{
			s = i;
			break;
		}
	}
	for(int i = 0; i < tot; i++)
	{
		if(strcmp(s2, G->adjlist[i].ch) == 0)
		{
			dest = i;
			break;
		}
	}
	for(int i = 0; i < tot; i++)
	{
	  dis[i] = INF;
	 } 
	dis[s] = 0;
	vnode a = G->adjlist[s];
	a.dis = dis[s];
	push(a);
	while(isempty() == 0)
	{
		vnode u = top();
		pop();
		if(vis[u.num] == 0)
		{
			vis[u.num] = 1;
			for(edgenode *e = G->adjlist[u.num].firstedge; e; e = e->next)
			{
				if(vis[e->tonum] == 1) continue;
				else 
				{
					if(dis[e->tonum] > dis[u.num] + e->w)
					{
						dis[e->tonum] = dis[u.num] + e->w;
						vnode tmp = G->adjlist[e->tonum];
						push(tmp);
						pre[e->tonum] = u.num;//注意下如何记录路径的 
					}
					
				}
			}
		}
	}
//	printf("%d", dis[dest]);
	int j = s;
	len = 0;
	print_path(j,dest);//寻路要从尾到前  
	printf("-%d(%d)-%s",oldline, len ,G->adjlist[dest].ch);
}

int main() {

	init();
	GraphAdjlist g;
	create(&g);
//	print(&g);
	G = &g;
//	printf("%d\n",tot);
	dijkstra(&g);
	
	return 0;
}

/*
西土城
北京西站
*/
