#include <stdio.h>
#include <string.h>
#include <stdlib.h>
/* run this program using the console pauser or add your own getch, system("pause") or input loop */
typedef struct
{
	char name[100];
	char anth[100];
	char pub[100];
	char date[100];
	int rank;
	int on;
 } book;
 book a[3800];
 int cnt;
 int cmp(const void* x,const void *y){
    book *a = (book*)x;
	book *b =  (book*)y;
	int i = strcmp (a->name,b->name);
	if(i) return i;
	else return a->rank - b->rank;
}
 void add(int cnt)
 {
 	scanf("%s%s%s%s", a[cnt].name, a[cnt].anth,a[cnt].pub,a[cnt].date);
 	a[cnt].rank = cnt;  
 }
int main(int argc, char** argv) {
	FILE *fp = fopen("books.txt", "r");
	FILE *out = fopen("ordered.txt","w");
	int cnt = 0;
	while(fscanf(fp,"%s%s%s%s", a[cnt].name, a[cnt].anth,a[cnt].pub,a[cnt].date)!=EOF)
	{
		a[cnt].rank = cnt; ++cnt;
	}
	qsort(a,cnt,sizeof(a[0]),cmp); 
	int type;
	while(scanf("%d",&type)!=EOF)
	{
		if(type == 0) break;
		if(type == 1)
		{
			add(cnt);
			
			cnt++;qsort(a,cnt,sizeof(a[0]),cmp); //×¢Òâqsort ÅÅÐò·¶Î§ 
		 } 
		 if(type == 2)
		 {		char *p;
				char key[100];
				scanf("%s",key);int i; 
		 	for( i = 0; i < cnt; i++)
			{	

				if((p = strstr(a[i].name,key))!=NULL && a[i].on == 0)
				printf("%-50s%-20s%-30s%-10s\n", a[i].name, a[i].anth,a[i].pub,a[i].date);
			}
		 }
		 if(type == 3)
		 {
		 	char *p;
			char key[100];
			scanf("%s",key);int i;
		 	for( i = 0; i < cnt; i++)
			{	
				if((p = strstr(a[i].name,key))!=NULL)
				{
					a[i].on = -1;
				}
			}
			qsort(a,cnt,sizeof(a[0]),cmp); 
		 }
	}int i;
	for(i = 0; i < cnt; i++)
			{
				if(a[i].on == 0)
				fprintf(out,"%-50s%-20s%-30s%-10s\n", a[i].name, a[i].anth,a[i].pub,a[i].date);
			}
	
	 fclose(fp);
	 fclose(out);
	return 0;
}
