#include <stdio.h>
#include <string.h>
#include <stdlib.h>
/* run this program using the console pauser or add your own getch, system("pause") or input loop */
typedef struct node
{
	int depth;
	int l;
	int r;
	int cnt;
	struct node *lchild, *rchild;
}node;
node a[1000];

int dep = 0;int channel = -1;int depth = -1;
node * create(node *rt, int num, int cnt ,int l, int r)
{
	if(rt == NULL && channel == num)
	{
		rt = (node *)malloc(sizeof(node));
		rt->cnt = cnt;
		rt->depth = depth+1;
		rt->lchild = rt->rchild = NULL;
		rt->l = l;
		rt->r = r;
		return rt;
	}
	else if(rt == NULL && channel != num)
	{
		return rt;
	}
	channel = rt->l;
	rt->lchild = create(rt->lchild, num, cnt,l, r);
	channel = rt->r;
	rt->rchild = create(rt->rchild, num, cnt,l, r);
	channel = -1;
	return rt;
}
void bianli(node *root)
{
	if(root == NULL) return;
	printf("%d ", root->cnt);
	bianli(root->lchild);
	bianli(root->rchild);
}
node* queue[1000];
int front,rear;
void levelbianli(node *root)
{
	front = 0;
	rear = -1;rear++;
	queue[rear] = root; 
	while(front <= rear)
	{
		node *u = queue[front]; front++;
		printf("%d ", u->cnt);if(front == rear + 1) printf("\n"); 
		if(u->lchild != NULL) 
		{
			rear++;queue[rear] = u->lchild; 
		}
		if(u->rchild != NULL) 
		{
			rear++;queue[rear] = u->rchild; 
		}
		
	}
	
	
}
int main(int argc, char** argv) {
	int n;int l, r;int cnt;
	scanf("%d", &n); node *root;
	root = (node *)malloc(sizeof(node));
	scanf("%d%d%d", &root->cnt, &l, &r);
	root->depth = 0;
	root->lchild = root->rchild = NULL;
	root->l = l;
	root->r = r;
	for(int i = 2; i <= n; i++)
	{
		scanf("%d%d%d", &cnt, &l, &r);
		root = create(root, i ,cnt, l, r);
	}
	bianli(root);
	printf("\n");
	levelbianli(root);
	return 0;
}
