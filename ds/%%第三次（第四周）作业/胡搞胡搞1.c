#include <stdio.h>
#include <string.h>
#include <stdlib.h> 
int bk[2000]; char s1[20000];char s2[20000];
char ma[20000][3];
char hash[200000];	int place;
int cnt;char last;
char ans[20000];
char ans2[20000];
typedef struct node
{
	char ch;
	struct node *next;
}node;
typedef struct node *linklist;
/* run this program using the console pauser or add your own getch, system("pause") or input loop */
void quchong()
{
	
	int len = strlen(s1);
	int i,cnt=0;
	for(i = 0; i < len; i++)
	{
		if(bk[s1[i]] == 0)
		{
			s2[cnt++] = s1[i];
			bk[s1[i]] = 1;
		}
	}
}
void jiaru ()
{
	int i = strlen(s2);
	int j;
	for( j = 32 ; j <= 126; j++)
	{
		if(bk[j] == 0)
		{
			s2[i++] = j ;
		}
	}
}
void listcreate(linklist head)
{
	int len = strlen(s2);
	linklist p = head;  
	for(int i = 1; i < len; i++) 
	{
		linklist create = (linklist) malloc (sizeof(node));
		create->ch = s2[i];
		create->next = p->next;
		p->next = create; 
		p = create;
	}
	p->next = head->next;
}
linklist Listdelete(linklist L, int m) //起始 差距 
 {
 	
 	linklist p,q;
	p = q = L ;// q去遍历
	int i=1;  
	while(p->next!= NULL && i < m-1) 
	{p = p-> next;i++;}
	
		if(p->next== p)
		{	
			q = p->next;
			p->next = q->next;
			ma[cnt][0] = place;
			ma[cnt][1] = q->ch;
			cnt++;
			hash[place] = q->ch;
			place = q->ch;
			m = q->ch;
			last = q->ch;
			free(q);
			return NULL;
		}
		else
		{
			q = p->next;
			p->next = q->next;
			ma[cnt][0] = place;
			ma[cnt][1] = q->ch;
			cnt++;
			hash[place] = q->ch;
			place = q->ch;
			m = q->ch;
			free(q);
			return Listdelete(p->next, m);
		}
 }
int main(int argc, char** argv) {
	gets(s1);
	quchong();
	jiaru();
	linklist a = (linklist) malloc(sizeof(node));
	a->ch = s2[0]; a->next = NULL;
	listcreate(a);
	place = a->ch; 
	int m = a->ch;
	Listdelete(a->next,m);
	hash[last] = s2[0];
	FILE *in = fopen("in.txt","r");
	FILE *out = fopen("in_crpyt.txt","w");
	/*for(int i = 32; i <= 126; i++)
	{
		printf("%c",hash[i]);
	}*/
	
	while(fgets(ans,900,in)!=NULL)
	{
		int len = strlen(ans);int i;
		for(i = 0; i < len; i++)
		{
			fprintf(out,"%c", (char)hash[ans[i]]);
		}
		fprintf(out,"\n");
		
	}
	/*char c;
	while((c=fgetc(in))!=EOF)
	{
        if(c >= 32&& c <= 126)
		{
            fputc(hash[c],out);
        }
        else fputc(c,out);
    }*/ 
	fclose(in);
	fclose(out);
	return 0;
}
