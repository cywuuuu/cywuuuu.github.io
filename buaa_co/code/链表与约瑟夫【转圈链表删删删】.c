#include <stdio.h>
#include <stdlib.h>
/* run this program using the console pauser or add your own getch, system("pause") or input loop */
int ans[20000];
int cnt = 0; 
int n,m,q,t;
 typedef struct node
 {
 	int rank;
 	struct node *next;
 } node;
 typedef struct node *linklist;//��ַ 


linklist Listdelete(linklist L, int n, int m, int j ) //��ʼ ��� 
 {
 	if(j >= t) return NULL;
 	linklist p,q;
	p=q= L ;// qȥ����
	int i=1;
	while(p->next!= NULL && i < m-1) //��m��ɾ����������m-1 ���� 
	{p = p-> next;i++;}
	
		if(p->next== p)
		{	
			q = p->next;
			p->next = q->next;
			printf("%d", ans[cnt++]);
			free(q);
			return NULL;
		}
		else
		{
			q = p->next;
			p->next = q->next;
			printf("%d", ans[cnt++]);
			free(q);
			return Listdelete(p->next, n, m, j+1);
		}
	
		
		
	
	
 }
  
int main(int argc, char** argv) {
	linklist L;
	q = 1; 
	scanf("%d%d%d",&n,&m,&t);//�ӵ�q����ʼ 
	linklist now,create,start;
 	L = (linklist)malloc(sizeof(node));
 	now = L;
	now->rank = 1;//��ͷ��Ҫ 
 	for(int i=2;i<=n;i++)
 	{
 		create = (linklist)malloc(sizeof(node));
 		create->rank = i;
 		now->next=create;
 		now = create;
	}
 	now->next= L;
 	start = L;
 	for(int i = 1; i < q; i++)
 	{
 		start = start->next;
	 }
	Listdelete(start,n,m, 0); 
	return 0;
}
