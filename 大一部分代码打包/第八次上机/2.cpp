#include <iostream>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char** argv) {
	int n;
	scanf("%d",&n);
	int sum=0;
	while(n>0)
	{
		sum+=n%10;
		n=n/10;
	}
	printf("%d",sum);
	return 0;
}
