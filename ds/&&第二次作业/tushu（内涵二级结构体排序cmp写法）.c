#include <stdio.h>
#include <stdlib.h>
#include <string.h>
 typedef struct 
{
	char name[1000];
	char data[1000];
	int rank; 
}lx;
lx a[200];lx moban;int bk[2000];
int cmp(const void* x,const void *y){
    lx *a = (lx*)x;
	lx *b =  (lx*)y;
	int i = strcmp (a->name,b->name);
	if( i)
	return i;
	else return a->rank - b->rank;
}
int main(int argc, char** argv) {
	int n,flag = 0,cnt = 1;
	scanf("%d", &n);
	int i;
	for(i = 0; i < n; i++)
	{
		scanf("%s%s", a[i].name, a[i].data);
		a[i].rank = i;
	}
	qsort(a,n,sizeof(a[0]),cmp); 
	for(i = 1; i < n; i++)
	{
		int lenname = strlen(a[i].name);
		if(strncmp(a[i].name,a[i-1].name,lenname) ) 
		{
			flag = 1;
			cnt = 1;
		}
		else flag = 0;
		if(flag == 0 && !(strcmp(a[i].data, a[i-1].data)))
		{
			bk[i] = 1;
		}
		else if(flag == 0 && strcmp(a[i].data, a[i-1].data))
		{
			int len = strlen(a[i].name);
			a[i].name[len] = '_';
			a[i].name[len+1] = '0' + cnt;
			cnt++;
		}
	}
	for(i = 0; i < n; i++)
	{
		if(bk[i] == 0)printf("%s %s\n", a[i].name, a[i].data);
	}
	return 0;
}
