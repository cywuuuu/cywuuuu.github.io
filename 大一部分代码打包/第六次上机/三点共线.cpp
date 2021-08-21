#include <stdio.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */


int main(int argc, char** argv) {
	int k1,b1,k2,b2,k3,b3;
	while(scanf("%d%d%d%d%d%d",&k1,&b1,&k2,&b2,&k3,&b3)!=EOF)
	{
	
	if(k2*b3-b2*k3-(k1*b3-k3*b1)+k1*b2-k2*b1==0) printf("Yes\n");
	else printf("No\n");
	}
	return 0;
}
