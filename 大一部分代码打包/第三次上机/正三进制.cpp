#include <stdio.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char** argv) {
	int n;
	while(scanf("%d",&n)!=EOF)
	{	int i=0;	int a[21]={0};
		if(n==0)
		{
			printf("0");//×ÐÏ¸¿´¼Ó´Ö×ÖÌå 
		}
		
		while(n>0)
		{
		
			
			a[i++]=n%3;
			n=n/3;
			
		}
		if(i>=5){
			printf("LONG");
			for(int j=i-1;j>=0;j--)
			{
			
				printf("%d",a[j]);
			}
			printf("\n");
		}
		
		else{
		
			for(int j=i-1;j>=0;j--)
			{
				printf("%d",a[j]);
			}
			printf("\n");
		}
	}
	return 0;
}
