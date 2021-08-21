#include <iostream>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */
typedef struct BiTNode
{
	int data;
	struct BiTNode *lchild, *rchild;
} BiTNode, *BiTree;

int SearchBST(BiTree T, int key, BiTree f, BiTree *p)
//p 为待修改的指针的地址（二次指针） f为father指针记录上个节点的地址
// T就是正常的根节点的地址 
{
	if(T == NULL ) 
	{
		*p = f;//失败时T应当是待插入节点应当在的位置， 获取*p=f可以Insert时使用 
		return -1;
	}
	else if( T->data == key) 
	{
		*p = T;
		return 1; 
	}
	else if( T->data < key) searchBST(T->lchild, key, T, p);//直接传p即可 
	else  searchBST(T->rchild, key, T, p);
}
//调用 SearchBST(root, key, NULL, &p); 


int InsertBST(BiTree *T, int key)//在空树情况下，可能要修改根节点！！ 
//所以传树根的地址 
{
	BiTree p,s;
	if(SearchBST(*T, key, NULL, &p))//search 中要求Bitree就行了 
	{
		s = (BiTree) malloc(sizeof(BiTNode));
		s->data = key;
		s->lchild = s->rchild = NULL;
		if(p == NULL) *T = s;
		else if(p->data < key) p->rchild = s;
		else p->lchild = s;
		return 1;
	}
	else return -1; 
}
//调用  InsertBST（&root, key）; 

int DeleteBST(BiTree *T, int key)//找到位置, 因为要修改结构体中child指针的值，
// 所以传入指针的地址 
{
	if(*T == NULL) return -1;//空树
	else 
	{
		if((*T)->data == key)
		return Delete(T);
		else if(key < (*T)->data) return DeleteBST(&((*T)->lchild), key);
		else return DeleteBST(&((*T)->rchild), key);
	 } 
}
int Delete(BiTree *T)
{
	BiTree q,s;
	if((*T)->rchild == NULL)//此时 T实际上时上一个节点结构体内某个child指针的地址
	{//同时 （*T）指向的节点应当被删除 
		q = *T;//记录待删除节点地址 
		*T = (*T)->lchild;
		// 修改上一个节点结构体中的指针，使其指向待删除节点的右孩子 
		free(q); 
	}
	else if((*T)->lchild == NULL)
	{
		q = *T;
		*T = (*T)->rchild;
		free(q); 
	}
	else //左右均不空 
	{
		q = *T;
		s = (*T)->lchild;//找待删节点的左树中的最大值来接替 
		while(s->rchild)//s指向那个最大值 
		{
			q = s;//q 比s慢一拍 
			s = s->rchild;
		}
		(*T)->data = s->data;//替代咯
		//但是 s 可能还有左子树！怎么办呢 ,把s较小的左子树接到 q的右边来代替q 
		
		if(q != *T) q->rchild = s->lchild;//此时s仅有左子树 
		else if(q == *T)//如果 q 刚好是 *T ,那就是说*T的左孩子S没有右子树，仅有左子树 
		{
			//如果不考虑此情况，那么就会把*T的无辜的右子树（全程酱油）给闪了 换s的右子树
			//此时应当 *T左孩子 接上 s的左子树
			(*T)->lchild = s->lchild; 
		 } 
		 
		free(s);
	}
	return 1;
 } 
int main(int argc, char** argv) {
	BiTree root;
	BiTree p;
	return 0;
}
