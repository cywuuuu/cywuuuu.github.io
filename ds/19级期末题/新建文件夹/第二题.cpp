#include <stdio.h>
#include <string.h>
#include <stdlib.h>
/* run this program using the console pauser or add your own getch, system("pause") or input loop */

typedef struct 
{
	int l;
	int r;
	int on;
}node;

node a[1000];

int cmp(const void *x, const void *y)
{
	return ((node *)x)->l - ((node *)y)->l;
}

int main(int argc, char** argv) {
	int n;
	scanf("%d", &n);
	for(int i = 0; i < n; i++)
	{
		scanf("%d%d", &a[i].l, &a[i].r);
		a[i].on = 1;
	}
	qsort(a,n,sizeof(a[0]),cmp);
	for(int i = 0; i < n; i++)
	{
		if(a[i].on == 1)
		{
			for(int j = i + 1; j < n; j++)
			{
				if(a[i].r + 1 == a[j].l) 
				{
					a[i].r = a[j].r;
					a[j].on = -1;
				}
			}
		}
	}
	
	for(int i = 0; i < n; i++)
	{
		if(a[i].on == 1)
		{
			printf("%d %d\n", a[i].l, a[i].r);
		}
	}
	return 0;
}
