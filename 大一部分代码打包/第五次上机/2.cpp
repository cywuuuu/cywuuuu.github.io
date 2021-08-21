#include <stdio.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char** argv) {
	int n,m,x,y,z;
	scanf("%d%d%d%d%d",&n,&m,&x,&y,&z);
	printf("%d",(n-x+m+z+y-1)%7+1);
	return 0;
}
