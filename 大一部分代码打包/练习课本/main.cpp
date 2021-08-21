#include <iostream>
#define NumOf(a) (sizeof(a)/sizeof(a[0])) 
int isprime(int v)
{
	for(int i=2;i*i<=v;i++)
	{
		if(v%i==0) return 0;
	}
	return 1;
}
/* run this program using the console pauser or add your own getch, system("pause") or input loop */
int hd=0,tail=4, queue[10000]={2,3,5,7};
int digits[]={1,3,7,9};


int main(int argc, char** argv) {
	int i,m,n,len,end=0;
	scanf("%d",&n);
	for(len = 1;len<n;len++)
	{
		for(end=tail;hd<=end;hd++)
		{
			m=queue[hd]*10;
			for(i=0;i<4;i++) 
			{
				
				m+=digits[i];
				if(isprime(m)) queue[tail++]=m;
			}
		}
	}
	return 0;
}
