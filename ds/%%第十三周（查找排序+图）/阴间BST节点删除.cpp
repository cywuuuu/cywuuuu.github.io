#include <iostream>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */
typedef struct BiTNode
{
	int data;
	struct BiTNode *lchild, *rchild;
} BiTNode, *BiTree;

int SearchBST(BiTree T, int key, BiTree f, BiTree *p)
//p Ϊ���޸ĵ�ָ��ĵ�ַ������ָ�룩 fΪfatherָ���¼�ϸ��ڵ�ĵ�ַ
// T���������ĸ��ڵ�ĵ�ַ 
{
	if(T == NULL ) 
	{
		*p = f;//ʧ��ʱTӦ���Ǵ�����ڵ�Ӧ���ڵ�λ�ã� ��ȡ*p=f����Insertʱʹ�� 
		return -1;
	}
	else if( T->data == key) 
	{
		*p = T;
		return 1; 
	}
	else if( T->data < key) searchBST(T->lchild, key, T, p);//ֱ�Ӵ�p���� 
	else  searchBST(T->rchild, key, T, p);
}
//���� SearchBST(root, key, NULL, &p); 


int InsertBST(BiTree *T, int key)//�ڿ�������£�����Ҫ�޸ĸ��ڵ㣡�� 
//���Դ������ĵ�ַ 
{
	BiTree p,s;
	if(SearchBST(*T, key, NULL, &p))//search ��Ҫ��Bitree������ 
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
//����  InsertBST��&root, key��; 

int DeleteBST(BiTree *T, int key)//�ҵ�λ��, ��ΪҪ�޸Ľṹ����childָ���ֵ��
// ���Դ���ָ��ĵ�ַ 
{
	if(*T == NULL) return -1;//����
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
	if((*T)->rchild == NULL)//��ʱ Tʵ����ʱ��һ���ڵ�ṹ����ĳ��childָ��ĵ�ַ
	{//ͬʱ ��*T��ָ��Ľڵ�Ӧ����ɾ�� 
		q = *T;//��¼��ɾ���ڵ��ַ 
		*T = (*T)->lchild;
		// �޸���һ���ڵ�ṹ���е�ָ�룬ʹ��ָ���ɾ���ڵ���Һ��� 
		free(q); 
	}
	else if((*T)->lchild == NULL)
	{
		q = *T;
		*T = (*T)->rchild;
		free(q); 
	}
	else //���Ҿ����� 
	{
		q = *T;
		s = (*T)->lchild;//�Ҵ�ɾ�ڵ�������е����ֵ������ 
		while(s->rchild)//sָ���Ǹ����ֵ 
		{
			q = s;//q ��s��һ�� 
			s = s->rchild;
		}
		(*T)->data = s->data;//�����
		//���� s ���ܻ�������������ô���� ,��s��С���������ӵ� q���ұ�������q 
		
		if(q != *T) q->rchild = s->lchild;//��ʱs���������� 
		else if(q == *T)//��� q �պ��� *T ,�Ǿ���˵*T������Sû�������������������� 
		{
			//��������Ǵ��������ô�ͻ��*T���޹�����������ȫ�̽��ͣ������� ��s��������
			//��ʱӦ�� *T���� ���� s��������
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
