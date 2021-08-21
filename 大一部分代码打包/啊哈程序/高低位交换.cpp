#include <stdio.h>
#include <math.h>
/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char** argv) {
	unsigned int n,ans=0,gao=0,di=0;
	scanf("%u",&n); 
	gao=(n>>16);
	di=(n<<16)>>16;
	ans=ans|(gao);
	ans=ans|(di<<16);
	printf("%u",ans);
	return 0;
}
