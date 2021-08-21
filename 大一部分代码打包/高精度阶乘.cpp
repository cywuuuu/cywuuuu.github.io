#include <stdio.h>
#include <string.h>
/* run this program using the console pauser or add your own getch, system("pause") or input loop */
	long long a[1000000];
int main(int argc, char** argv) {
	int n;int last=1;
	a[0]=1;
	scanf("%d",&n);
	for(int i=2;i<=n;i++)
	{
		long long carry=0;
		
		for(int j=0;j<last;j++)
		{	
			a[j]*=i; 
			if(a[j]<0) 
			{
				printf("£¡£¡£¡\n");
				break;
			}
			a[j]+=carry;
			carry=a[j]/10;
			a[j]%=10;
			
		}
		while(carry)
		{
			a[last++]=carry%10;
			carry/=10;
		}
	}
	for(int i=last-1;i>=0;i--)
	{
		printf("%d",a[i]);
	}
	return 0;
}
