#include <iostream>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char** argv) {
	int a[100];
	int n,head,tail;
	scanf("%d",&n);
	for(int i=0;i<n;i++)
	{
		scanf("%d",&a[i]);
	}
	head=0;
	tail=n;
	while(head<tail)
	{
		printf("%d",a[head]);
		head++;
		
		a[tail]=a[head];
		head++;tail++;
	}
	return 0;
}
