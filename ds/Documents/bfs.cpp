#include <stdio.h>
#include <string.h>
#include <stdlib.h>
/* run this program using the console pauser or add your own getch, system("pause") or input loop */
char a[1000][1000];
int bk[1000][1000];
int direct[4][2]=
{
	{-1,0},{1,0},{0,-1},{0,1}
};
struct pos
{
	int x;
	int y;
};
struct que 
{
	struct pos data[30000];
	int front, rear;
};
int enque(struct que* q, int i, int j)
{
	if(q->rear +1 == 30000) return -1;
	q->data[q->rear].x = i;
	q->data[q->rear].y = j;
	q->rear++;
	return 0;
}
int deque(struct que* q)
{
	q->front++;
}

int main(int argc, char** argv) {
	
	int w,h;
	while(scanf("%d%d",&w,&h)!=EOF)
	{
	struct que *q = (struct que *)malloc(sizeof(struct que));
	q->front = 0 ;
	q->rear = 0 ;
	struct pos pos;
	int cnt = 0;
	char tmp;
	for(int i = 0; i < 1000; i++)
	{
		for(int j = 0; j < 1000; j++)
		{
			bk[i][j] = 0;
			a[i][j] = 0;
		}
	}

	for(int i = 0; i < h; i++)
	{
		for(int j = 0; j < w; j++)
		{
			scanf("%c",&tmp);
			if(tmp=='\n')
			{
				j--;
			}
			else
			{
			a[i][j] = tmp;
			bk[i][j] = 0;
			if( a[i][j] == '@')
			{
				pos.x = i;
				pos.y = j;
			}}
		}
	}
	enque(q,pos.x,pos.y);
	bk[pos.x][pos.y] = 1;
	while(q->front < q->rear)
	{
		for(int i = 0;i < 4;i++){
			if(q->data[q->front].x + direct[i][0]>=0 && q->data[q->front].y + direct[i][1]>=0 && q->data[q->front].x + direct[i][0]<h && q->data[q->front].y + direct[i][1]<w)
			{
			
			if(a[q->data[q->front].x + direct[i][0]][q->data[q->front].y + direct[i][1]]=='.'&&bk[q->data[q->front].x + direct[i][0]][q->data[q->front].y + direct[i][1]]==0)
			{
				enque(q, q->data[q->front].x + direct[i][0], q->data[q->front].y + direct[i][1]);
				bk[q->data[q->front].x + direct[i][0]][q->data[q->front].y + direct[i][1]]=1;
			}}
		}
		deque(q);
		
	}
		for(int i = 0; i < h; i++)
	{
		for(int j = 0; j < w; j++)
		{
			if(bk[i][j]==1) cnt++;
		}
	}
	printf("%d\n",cnt);
	}
	return 0;
}
