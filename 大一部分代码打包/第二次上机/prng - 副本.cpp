#include <stdio.h>
void quicksort(int left, int right,long long* seed)
{
	int i,j,t,tmp;
	if(left>right) return;
	tmp=seed[left];
	i=left;
	j=right;
	while(i!=j)
	{
		while(seed[j]>=tmp&&i<j)
		j--;
		while(seed[i]<=tmp&&i<j)
		i++;
		if(i<j)
		{
			t=seed[i];
			seed[i]=seed[j];
			seed[i]=t;
		}
	}
	
	seed[left]=seed[i];
	seed[i]=tmp;
	quicksort(left,i-1,seed);
	quicksort(i+1,right,seed);
	 } 
/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char** argv) {
	long long m,a,b;
	int cnt,p=0;
	long long seed[50010];
	scanf("%lld%lld%lld%lld",&m,&a,&b,&seed[0]);
	for(int i=0;i<=50000;i++)
	{
		seed[i+1]=(seed[i]*a+b)%m;
	}
	quicksort(0,50000,seed);
	
	if(p==0) {
		printf("Not repeated\n");
		printf("%lld",seed[50000]);
	}
	return 0;
}
