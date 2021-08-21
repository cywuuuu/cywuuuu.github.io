#include <stdio.h>


/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char** argv) {
	long long s;
	int i=0,flag=0; 
	int max=0;
	scanf("%lld",&s);
	if(s==1) printf("4"); 
	else if(s==2) printf("6");
	else if(s==3) printf("8");
	else{
	
		for(i=2;i*i<=s;i++)
		{
			if(s%i==0)
			{
				flag=1;
				max=i;
			}
		} 
		if(flag==1)printf("%lld",2*s/max+2*max);
		else printf("%lld",2+2*s);
	}
	
	return 0;
}
