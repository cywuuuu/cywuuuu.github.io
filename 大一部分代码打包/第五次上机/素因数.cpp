#include <stdio.h>
int isprime(int u)
{	
	if(u==1) return 0;
	if(u==2) return 1;
	else{
		for(int i=2;i*i<=u;i++)
		{
			if(u%i==0) return 0;
			}	
		return 1;
	}
}
/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char** argv) {
	int n;
	while(scanf("%d",&n)!=EOF)
	{
	int cnt=0;
	for(int i=1;i<=n;i++)
	{
		if(n%i==0)
		{
		
		if(isprime(i)) cnt++;
		}
	}
	printf("%d\n",cnt);//****千万别忘了！！！回车！！！ 
	}
	return 0;
}
