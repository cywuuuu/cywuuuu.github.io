#include <stdio.h>

int n;
int s[18];
int bk[18];
/* run this program using the console pauser or add your own getch, system("pause") or input loop */
void dfs(int k)
{
	if(k==n+1) 
	{
		for(int j = 1; j <= n; j++)
		{
			printf("%d ",s[j]);
		}
		printf("\n");
		return;
	}
	int i = 0;
	for( i = 1; i <= n; i++)
	{
		if(bk[i] == 0)
		{
			s[k] = i;
			bk[i] = 1;
			dfs(k+1);
			bk[i] = 0;
		}
	}
}



int main(int argc, char** argv) {
	
	scanf("%d",&n);
	for(int i = 1 ;i <= n; i++)
	{
		s[i] = i;
	}
	dfs(1);
	return 0;
}
