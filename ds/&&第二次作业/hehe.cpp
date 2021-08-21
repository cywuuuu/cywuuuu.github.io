#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef struct
{
	char name[1000];
	char data[1000];
	char link[2000];
}lx;
lx a[200];
/* run this program using the console pauser or add your own getch, system("pause") or input loop */
int cmp ( const void *a , const void *b ) 
{ 
return strcmp( ((lx *)a->link) , ((lx *)b)->link ); 
} 

int main(int argc, char** argv) {
	int n;
	scanf("%d", &n);
	int i;
	for(i = 0; i < n; i++)
	{
		scanf("%s%s", a[i].name, a[i].data);
		a[i].link = strcat(a[i].name, a[i].data);
	}qsort(a,n,sizeof(s[0]),cmp); 
	for(i = 1; i < n; i++)
	{
		int cnt = 0;
		if ()
	}
	return 0;
}
