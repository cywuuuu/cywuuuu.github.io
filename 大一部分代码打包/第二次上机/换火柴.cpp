#include <stdio.h> 
#include <math.h>
/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char** argv) {
	int t;	
	long long x[20008],y[20008],k[20008];
	scanf("%d",&t);
	for(int i=0;i<t;i++)
	{
		scanf("%lld%lld%lld",&x[i],&y[i],&k[i]);
	}

	for(int i=0;i<t;i++){

	if((k[i]-1+y[i]*k[i])%(x[i]-1)==0) printf("%lld\n",(k[i]-1+y[i]*k[i])/(x[i]-1)+k[i]);
	else printf("%lld\n",(k[i]-1+y[i]*k[i])/(x[i]-1)+k[i]+1);	
	//printf("%lld\n",(ceil((k[i]-1+y[i]*k[i])/(double)(x[i]-1))+k[i]));
	//为什么不对啊 ceil 可以吗？ //两个案例都是可以整除的不太好啊 
	}
	return 0;
}
