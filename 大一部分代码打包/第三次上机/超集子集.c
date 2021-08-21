#include <stdio.h>
#include <stdlib.h>
#include <math.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char *argv[]) {
	int n,x;
	scanf("%d%d",&n,&x);
	for(int i=0;i<pow(2,n);i++)
	{
		if((i&x)==i) printf("%d",i);
	}
		for(int i=0;i<pow(2,n);i++)
	{
		if((i&x)==x) printf("%d",i);
	}
	return 0;
}
