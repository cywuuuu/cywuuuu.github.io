#include <stdio.h>
#include <math.h>
/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char** argv) {
	int t;
	scanf("%d",&t);
	unsigned long long a,b,c;
	while(t--)
	{
		scanf("%llu%llu",&a,&b);
		double p=log2(a);
		double q=log2(b);
		if((p+q)>64) printf("But it is the same for mudulo 2^64.\n");
		else printf("Here's where the parade begins!\n");
		
	}
	return 0;
}
