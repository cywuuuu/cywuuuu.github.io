#include <stdio.h>
int main(int argc, char** argv) {
	long long m,a,b;
	int p=0;
	long long seed[50010];
	scanf("%lld%lld%lld%lld",&m,&a,&b,&seed[0]);
	for(int i=0;i<=50000;i++)
	{
		seed[i+1]=(seed[i]*a+b)%m;	
		
		if(i>=2){
		
		for(int j=1;j<i;j++)
		{
	
			if(seed[i]==seed[j]) 
			{	
				p=1;
				printf("Duplicate found\n");
				printf("%lld %d",seed[j],i);
				return 0;
		 	} 

		}
		
		}	
		if(p==1) break;
	}
	if(p==0) {
		printf("Not repeated\n");
		printf("%lld",seed[50000]);
	}
	return 0;
}
