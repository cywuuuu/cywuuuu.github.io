#include <stdio.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char** argv) {
	int n;
	scanf("%d",&n);
	int bk[20008]={0};
	while(n--)
	{
		int l=0,r=0;
		
		scanf("%d%d",&l,&r);
		for(int i=l;i<=r;i++)
		{
			int tmp=i;
			int cnt=0;
			while(tmp>0)
			{
				if(tmp%10==2||tmp%10==0||tmp%10==7||tmp%10==3) cnt++;
				tmp=tmp/10;
			}
				if((cnt==2||cnt==0||cnt==7||cnt==3)&&bk[i]==0) //"=="!!!!!!!!¡°==¡± 
				{
					printf("%d ",i);
					bk[i]=1;
				}
		}
		printf("\n");
	}
	return 0;
}
