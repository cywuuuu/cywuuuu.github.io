#include <stdio.h>
#include <stdlib.h>
#define MAX 10000
int tot = 0;
/* run this program using the console pauser or add your own getch, system("pause") or input loop */
typedef struct 
{
	int in;
	int num;
}person;
typedef struct
{
	person data[MAX];
	int front;
	int rear;
}queue;
void init(queue *q);
int getsize(queue *q);
int enqueue(queue *q, person *a);
int dequeue(queue *q, person *a);
int sum;

int main(int argc, char** argv) {
	int m;int n;
	int yushu = 0;
	int type = 0;
	scanf("%d", &m);
	queue *a = (queue*)malloc(sizeof(queue));
	init(a);
	int cnt = 0;
	while(m--)
	{
		cnt++;
		scanf("%d", &n);person *tmp = (person*) malloc(sizeof(person));
		for(int i = 0; i < n; i++)
		{
			tmp->in = cnt;
			tmp->num = ++tot;
			enqueue(a, tmp);
		}
		 sum = getsize(a);
		if(sum >= 21 && sum < 28) type = 4;
		else if(sum >= 28) type = 5;
		else type = 3;
		person *get = (person*) malloc(sizeof(person));
		
		for(int i = 0; i < type; i++)
		{	 
			if(dequeue(a, get)==1)
			{
			printf("%d : %d\n", get->num, cnt - get->in);
			}
		
		}sum = getsize(a);
		if(sum >= 21 && sum < 28) type = 4;
		else if(sum >= 28) type = 5;
		else type = 3;
	}
	while(getsize(a)!= 0)
	{
		cnt++;
		 sum = getsize(a);
		if(sum >= 21 && sum < 28) type = 4;
		else if(sum >= 28) type = 5;
		else type = 3;
		person *get = (person*) malloc(sizeof(person));
		
		for(int i = 0; i < type; i++)
		{
			sum = getsize(a);
		if(sum > 21 && sum <= 28) type = 4;
		else if(sum > 28) type = 5;
		else type = 3;
		if(i >= type) continue;
			if(dequeue(a, get)==1)
			{
			printf("%d : %d\n", get->num, cnt - get->in);
			}
			sum = getsize(a);
		if(sum >= 21 && sum < 28) type = 4;
		else if(sum >= 28) type = 5;
		else type = 3;
		}
	}
	return 0;
}
void init(queue *q)
{
	q->front = 0;
	q->rear = 0;
}
int getsize(queue *q)
{
	return (q->rear - q->front + MAX)%MAX;
}

int enqueue(queue *q, person *a)
{
	if((q->rear + 1)%MAX ==  q->front)
	return -1;;
	q->data[q->rear] = *a;
	q->rear = (q->rear + 1)%MAX;
	return 1;
}
int dequeue(queue *q, person *a)
{
	if(q->front == q->rear) return -1;
	*a = q->data[q->front];
	q->front = (q->front + 1)%MAX;
	return 1;
}


