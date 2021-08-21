#include <iostream>
#define NumOf(a)  (sizeof(a)/sizeof(a[0])) 
/* run this program using the console pauser or add your own getch, system("pause") or input loop */
int head=0,tail=4,queue[MAX_Q]={2,3,5,7};
int digits[]={1,3,7,9};

int main(int argc, char** argv) {
	int i,m,n,len,end=0;
	scanf("%d",&n);
	for(len=1;len<=n;len++)
	{
		for(end=tail;head<end;head++)
		{
			m=queue[head]*10;
			for(i=0;i< NumOf(digits);i++) if(isPrime(m+digits[i])) queue[tail++]=m+digits[i];
		}
	}	
	
	for(i=end;i<tail;i++)y 
	printf("%d\n",queue[i]);
	return 0;
}
