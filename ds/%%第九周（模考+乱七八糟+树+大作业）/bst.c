#include <stdio.h>
#include <stdlib.h>
/* run this program using the console pauser or add your own getch, system("pause") or input loop */
typedef struct bt
{
	int data;
	struct bt *lchild, *rchild;
}node, *bitree;
int search(bitree t, bitree f, bitree *p, int key);
int insert(bitree *t, int key);
void bianli(bitree t, int depth);
int main(int argc, char** argv) {
	bitree root = NULL;
	int n;
	scanf("%d", &n);
	while(n--)
	{
		int num;
		scanf("%d", &num);
		insert(&root, num);
	}
	bianli(root, 1);
	return 0;
}
//f��ʼΪNULL 
void bianli(bitree t, int depth)
{
	if( t == NULL)
	return ;
	if( t->lchild == NULL && t->rchild == NULL)
	{
		printf("%d %d\n", t->data, depth);
	}
	bianli(t->lchild, depth + 1);
	bianli(t->rchild, depth + 1);
}
int search(bitree t, bitree f, bitree *p, int key)//p Ϊ*p�ĵ�ַ ��*p��Ϊ���޸�(*p)ָ��ָ��ĵ�ַ 
{
	if(t == NULL)
	{
		*p = f;
		return -1;
	}
	else if( key == t->data)
	{
		*p = t;
		return 1;
	}
	else if( key < t->data)
	{
		search( t->lchild,  t, p , key);
	}
	else if( key > t->data)
	{
		search( t->rchild,  t, p , key);
	}
	return -1;
}
int insert(bitree *t, int key)//Ϊ���ڿ���ʱ���� *t ��ָ 
{
	bitree p,s;
	if( search(*t, NULL, &p, key) == -1)//�Ҳ��� 
	{
		s = (bitree) malloc (sizeof(node));
		s->data = key;
		s->lchild = s->rchild = NULL;
		if(p==NULL)//���� 
		{
			*t = s; 
		}
		else if(key < p->data)
		{
			p->lchild = s;
		}
		else if(key > p->data)
		{
			p->rchild = s;
		}
		return 1;
	}
	else return -1;
}
