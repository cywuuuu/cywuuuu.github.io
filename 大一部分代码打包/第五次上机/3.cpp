#include <stdio.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char** argv) {
	int l,r;
	scanf("%d%d",&l,&r);
	for(int i=1;i<=9;i++)
	{
		for(int j=1;j<=i;j++)
		{
			if(j*i<l||j*i>r)
			printf("%d * %d = %d ",j,i,j*i);
		}
		printf("\n");
	}
	return 0;
}
