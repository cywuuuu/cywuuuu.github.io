#include <stdio.h>
#include <string.h>
#include <stdlib.h> 
/* run this program using the console pauser or add your own getch, system("pause") or input loop */

typedef struct node
{
	int dep;
	int path[1000];
}node;
node a[500];
int width[1000];
int main(int argc, char** argv) {
	a[1].dep = 1;
	a[1].path[0] = 1;
	width[1] = 1;
	int n;
	scanf("%d", &n);
	int pre;
	int num;
	for(int i = 0; i < n-1; i++)
	{
		scanf("%d%d",&pre,&num);
		a[num].dep = a[pre].dep + 1;
		width[a[num].dep]++;
		memcpy(a[num].path, a[pre].path, a[pre].dep * sizeof(a[pre].path[0]));
		a[num].path[a[num].dep-1] = num;
	}
	int max_depth = -1;
	int max_width = -1;
	for(int i = 1; i <= n-1; i++)
	{
		if(max_depth < a[i].dep) max_depth = a[i].dep;
		if(max_width < width[i]) max_width = width[i];
	}
	

	int from,to;
	int len = 0;
	scanf("%d%d", &from, &to);int i = 0;	printf("%d\n%d\n", max_depth, max_width);
	for(i = 0; a[from].path[i] == a[to].path[i]; i++);
	len = 2*(a[from].dep - i) + a[to].dep - i;
	printf("%d", len);
	return 0;
}
