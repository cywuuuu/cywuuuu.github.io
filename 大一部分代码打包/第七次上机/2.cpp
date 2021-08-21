#include <stdio.h>
//œÎ«Â‘Ÿ–¥ 
/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char** argv) {
	int t,l,r;
	int book[48]={0};
	int cnt=0;
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d%d",&l,&r);
		for(int i=l-1;i<r;i++)
		{
			book[i]=1;
		}
	}
		for(int i=0;i<48;i++)
		{
			if(book[i]==0) cnt++;
		}
	printf("%d",cnt);
	return 0;
}
