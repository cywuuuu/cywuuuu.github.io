#include <stdio.h>
#include <stdlib.h>
#include <string.h>
/* run this program using the console pauser or add your own getch, system("pause") or input loop */
int tot = 0;int a;//a 为计算机 
typedef struct node
{
	struct node* ch[8];
	int type;//0,1,2
	int num;
	int dep;
	int rank;
}node;
int path[500][500];
int prt[500];int cntprt = 0;
int bkjiaohuan[500];
int rk[500];//记录各个节点的rank 
int dis[500];//记录个节点到cpter的长度 
void search(node *root, int num, node **p)
{
	if(root == NULL) return ;
	else if(root->num == num) 
	{
		*p = root;//修改指针值要穿指针的地址 
		return;
	}
	else
	{
		for(int i = 0; i < 8; i++)
		search(root->ch[i], num, p);
	}
}
node *create(node *r, int t, int nn, int f, int chid)
{
	if(r == NULL)
	{
		node *r = (node *)malloc(sizeof(node));
		r->dep = 1;
		r->num = nn;
		r->type = t;
		for(int i = 0; i < 8; i++)
		{
			r->ch[i] = NULL; 
		}
		return r;
	}
	else{
		node *p = NULL;
		search(r, f, &p);
		node *n = (node *)malloc(sizeof(node));
		n->dep = p->dep+1;
		n->num = nn;
		n->type = t;
		for(int i = 0; i < 8; i++)
		{
			n->ch[i] = NULL; 
		}
		p->ch[chid] = n;
		return r;
	}
}
void bianli(node *root)
{
	if(root == NULL) return;
	{
		root->rank = ++tot;
		rk[root->num] = root->rank;
	}
	for(int i = 0; i < 8; i++)
	{
		bianli(root->ch[i]);
	}
}

int getdis(int num)
{
	int sm = 0;
	int numlen = 0;
	int alen = 0;
	
	for(int j = 0;path[num][j] != -1; j ++)
	{
		numlen++;
	}
	for(int j = 0;path[a][j] != -1; j ++)
	{
		alen++;
	}
	while(path[num][sm] == path[a][sm])
	{
		sm++;
	}
	return alen + numlen - 2*sm;
}

int main(int argc, char** argv) {
	int n;
	FILE *fp = fopen("in.txt", "r");
	node *root = NULL;
	scanf("%d %d", &n ,&a);
	memset(path, -1, sizeof(path));
	for(int i = 0; i < n; i++)
	{
		int num,type,f,ch;
		fscanf(fp,"%d%d%d%d", &num, &type, &f, &ch);
			if(type == 2) 
			{
				prt[cntprt++] = num;
			}
			else if(type == 0)
			{
				bkjiaohuan[num] = 1;
			}
			int j = 0;
			if(f >= 0)
			{
				for(j = 0; path[f][j] != -1; j++)
				{
					path[num][j] = path[f][j]; 
				}
			}
			
			path[num][j] = num;
		root = create(root,type,num,f,ch);
	}//创建完毕
	bianli(root);
	memset(dis, 100000, sizeof(dis));
	int min = 100000; 
	int minw = -1;//minw记录第几个最小 
	for(int i = 0; i < cntprt; i++)
	{
		dis[prt[i]] = getdis(prt[i]);
		if(dis[prt[i]] < min)
		{
			min = dis[prt[i]];
			minw = prt[i]; 
		 } 
		else if(dis[prt[i]] == min)
		{
			if(rk[prt[i]] < rk[minw])
			{
				minw = prt[i];
			}
		} 
	}
	printf("%d ", minw);
	
	int sm = 0;
	int minwlen = 0;
	int alen = 0;
	
	for(int j = 0;path[minw][j] != -1; j ++)
	{
		minwlen++;
	}
	for(int j = 0;path[a][j] != -1; j ++)
	{
		alen++;
	}
	while(path[minw][sm] == path[a][sm])
	{
		sm++;
	}
	for(int i = alen - 2; i >= sm-1;i--)
	{
		if(bkjiaohuan[path[a][i]] == 1)
		printf("%d ", path[a][i]);
	}
	for(int i = sm; i < minwlen-1; i++ )
	{
		if(bkjiaohuan[path[minw][i]] == 1)
		printf("%d ", path[minw][i]);
	}
	fclose(fp);
	return 0;
}

