#include <stdio.h>
#include <stdlib.h>
/* run this program using the console pauser or add your own getch, system("pause") or input loop */
int n,m;
 typedef struct node
 {
 	int data;
 	struct node *next;
 } node;
 typedef struct node *linklist;//��ַ 


linklist Listdelete(linklist L, int n, int m ) //��ʼ ��� 
 {
 	
 	linklist p,q;
	p=q= L ;// qȥ����
	int i=1;
	while(p->next!= NULL && i < m-1) 
	{p = p-> next;i++;}
	
		if(p->next== p)
		{	
			q = p->next;
			p->next = q->next;
			printf("%d ",q->data);	
			free(q);
			return NULL;
		}
		else
		{
			q = p->next;
			p->next = q->next;
			printf("%d ",q->data);	
			free(q);
			return Listdelete(p->next, n, m);
		}
	
		
		
	
	
 }
  
int main(int argc, char** argv) {
	linklist L;

	scanf("%d%d",&n,&m);
	linklist now,create;
 	L = (linklist)malloc(sizeof(node));
 	now = L;
	now->data = 1;//��ͷ��Ҫ 
 	for(int i=2;i<=n;i++)
 	{
 		create = (linklist)malloc(sizeof(node));
 		create->data = i;
 		now->next=create;
 		now = create;
	 }
 	now->next= L;
	Listdelete(L,n,m); 
	return 0;
}
