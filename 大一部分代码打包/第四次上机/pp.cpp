#include <stdio.h>
#include <math.h>
/* run this program using the console pauser or add your own getch, system("pause") or input loop */


int main(int argc, char** argv) {
	int n,m;
	while(scanf("%d%d",&n,&m)!=EOF)
	{
		for(int j=1;j<=n;j++)
		{
		
			for(int i=1;i<=m;i++)
			{
				printf("%.4lf ",pow((double)1+0.01*i,j));
			}
			printf("\n");
	}
		
	}
	return 0;
}
