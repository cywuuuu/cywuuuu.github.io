#include <stdio.h>
#include <stdlib.h>
/* run this program using the console pauser or add your own getch, system("pause") or input loop */
typedef struct node
{
	int data;
	int depth;
	struct node *lchild, *rchild;
}node;
node* create(node *p,int depth,int val)
{
	if((p)==NULL)
	{
		p = (node *)malloc(sizeof(node));
		p->data = val;
		(p)->depth = depth;
		p->lchild = NULL;
		p->rchild = NULL;
	}
	else if( val < (p)->data)
	{
		p->lchild =create ((p)->lchild, depth+1, val);
	}
	else if( val >= (p)->data)
	{
		p->rchild = create((p)->rchild, depth+1, val);
	}
	return p;
}
void bianli(node *p)
{
	if(p == NULL) return;
	else{
		
		if(p->lchild == NULL && p->rchild == NULL)
	{
		printf("%d %d\n", p->data, p->depth);
	}
	bianli(p->lchild);
	bianli(p->rchild);
	}
	
}
int main(int argc, char** argv) {
	node* root = NULL;
	int n;
	scanf("%d", &n);
	while(n--)
	{
		int num;
		scanf("%d", &num);
		root = create(root,1, num);//要更新root的指针值！！！否则只是空传值 
	}
	bianli(root);
	return 0;
}
/*13
50 38 30 64 58 40 10 73 70 50 60 100 35*/


