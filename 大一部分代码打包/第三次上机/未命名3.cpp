#include<stdio.h>
int main()
{
	int a;
	scanf("%d",&a);
	a&=~(((1<<9)-1)<<8);
	printf("%d",a);
	return 0;
} 
