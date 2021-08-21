#include <stdio.h>
#include <stdlib.h>
int ans[20000][2];
int cnt;
/* run this program using the console pauser or add your own getch, system("pause") or input loop */

typedef struct node 
{
	int ind;
	int an;
	struct node *next; 
} node;
typedef node *linklist;

void linklistcreate(linklist head)
{
	int x,y;
	linklist now = head;
	char ch;
	while(scanf("%d%d",&x,&y)==2)
	{
		
		linklist q = (linklist)malloc(sizeof(node)); 
		now->next = q; 
		q->an = x;
		q->ind = y;
		now = q;
		if((ch = getchar())=='\n') break;
	}
	now->next = NULL;
}
void listinsert(int indx, int aa, linklist c)
{
	linklist p = c; 
	
	while( p->next != NULL && indx > p->next->ind )
	{
		p = p->next; 
	}
	if(p->next == NULL)
	{
		linklist create = (linklist)malloc(sizeof(node));
		create->next = p->next; 
		create->ind = indx;
		create->an = aa; 
		p->next = create;
	}
	else if(p->next->ind == indx){
		p->next->an += aa;
	
	}
	else{
		linklist create = (linklist)malloc(sizeof(node));
		create->next = p->next;
		create->ind = indx;
		create->an = aa; 
		p->next = create;
	}
		
	
	
}
void listprint(linklist c)
{
	linklist l = c->next;
	while(l != NULL)
	{
		ans[cnt][0] = l->an;
		ans[cnt][1] = l->ind;cnt++;
		l = l->next;
	}
	while(cnt--)
	{
		printf("%d %d ", ans[cnt][0], ans[cnt][1]);
	}
}
void listccreate(linklist a, linklist b, linklist c)
{
	linklist p = a->next,q = b->next, now = c;
	while( p != NULL) 
	{
		q = b->next;
		while( q != NULL)
		{
			int indx = p->ind + q->ind;
			int aa = p->an * q->an;
			listinsert(indx,aa,c);
			q = q->next;	
		}
		p = p->next;
		
	}
}


int main(int argc, char** argv) {
	linklist a,b,c;
	a = (linklist)malloc(sizeof(node));
	b = (linklist)malloc(sizeof(node));
	c = (linklist)malloc(sizeof(node));
	c->ind = 0; c->an = 0; c->next = NULL;
	linklistcreate(a);
	linklistcreate(b);
	listccreate(a,b,c);
	listprint(c);
	return 0;
}
