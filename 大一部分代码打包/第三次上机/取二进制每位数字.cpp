#include <stdio.h>
#include <math.h>
/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char** argv) {
	int p,a;
	scanf("%d",&a);
	
	for(int i=31;i>=0;i--)
	{
		p=(a&(1<<i))/pow(2,i);
		p=abs(p);
		printf("%d",p);
	}
	return 0;
}
