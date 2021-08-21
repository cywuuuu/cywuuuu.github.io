#include <iostream>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */
struct queue
{
	int data[100];
	int head;
	int tail;
};
int main(int argc, char** argv) {
	struct queue yiwen;
	int n;
	scanf("%d",&n);
	yiwen.head=0;
	yiwen.tail=n;
	for(int i=0;i<n;i++)
	{
		scanf("%d",&yiwen.data[i]);
	}
	
	while(yiwen.head<yiwen.tail)
	{
		printf("%d",yiwen.data[yiwen.head]);
		yiwen.head++;
		
		yiwen.data[yiwen.tail]=yiwen.data[yiwen.head];
		yiwen.tail++;
		yiwen.head++;
		
	}
	return 0;
}
