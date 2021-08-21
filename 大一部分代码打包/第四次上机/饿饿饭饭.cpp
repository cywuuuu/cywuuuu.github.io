#include <stdio.h>
//看清数据范围 开多少数组 
/* run this program using the console pauser or add your own getch, system("pause") or input loop */
int searchroute(int* a,int n)
{
	
	if(a[0]==0) return 0;
	if(*a>0)
	{
		if(*a>=n-1) return 1; 
		else{
		
			for(int i=1;i<=*a;i++)
			{
				
				if(searchroute(a+i,n-i)) 
				{
				return 1;}
				
				
			}
			return 0;
		}
	}
	
	
}

int main(int argc, char** argv) {
	int t,n=0;
	scanf("%d",&t);
	int a[1000]={0};
	while(t--)
	{
		
		scanf("%d",&n);
		for(int i=0;i<n;i++)
		{
			scanf("%d",&a[i]);

		}
		if(searchroute(a,n)) printf("Completed!\n");
		else printf("You lose!\n");
	}
	fclose(stdout);
	fclose(stdin);
	return 0;
}
