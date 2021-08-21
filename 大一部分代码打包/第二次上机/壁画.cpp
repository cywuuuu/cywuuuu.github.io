#include <stdio.h>
//本题为课本原题 集合合并 
/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char** argv) {
	int n,head=0,tail=0;
	long long l[108]={0},r[108]={0};
	long long sum=0; 
	scanf("%d",&n);
	for(int i=0;i<n;i++)
	{
		scanf("%lld%lld", &l[i],&r[i]);
		
	 } 
	 
	while(tail<n)
	{
		if(r[tail]>=l[tail+1])
		{
			tail++;
		}
		
		else 
		{
			sum+=r[tail]-l[head];
			head=tail+1;
			tail++;
		}
	}
	if(head==tail) sum+=r[tail]-l[head];
	if(head<tail) sum+=r[tail-1]-l[head];
	printf("%lld",sum);
	
	
	return 0;
}
