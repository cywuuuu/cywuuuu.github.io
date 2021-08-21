#include <stdio.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char** argv) {
	int target,hash,cnt=0;
	scanf("%d%d",&target,&hash);
	for(int i=0;i<32;i++)
	{
		cnt+=((hash>>i)&1)==0;
	}
	if(target==cnt)printf("coins++");
	else printf("continue to work hard");
	return 0;
}
