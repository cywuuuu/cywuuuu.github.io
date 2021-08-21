#include <stdio.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */
int air(int x,int a,int b)
{
	if(x<=a) return air(air(x+b+1,a,b),a,b);
	if(x>a)  return x-b;
}
int main(int argc, char** argv) {
	int a,b,x;
	while(scanf("%d%d%d",&a,&b,&x)!=EOF){

	printf("%d\n",air(x,a,b));
		}
	return 0;
}
