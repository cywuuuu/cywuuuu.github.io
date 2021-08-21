#include <iostream>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */
bool isprime(int x)
{
	for(int i=2;i*i<x;i++)
	{
		if(x%i==0) return 0;
	}
	return 1;
}
int main(int argc, char** argv) {
	
 int a[10];
 int p=1,i,n,sum;
 scanf("%d",&n);
 int prime[5]={1,2,3,5,7};
 while(1)
 {
 sum=0;p=1;
 for(int j=1;j<=n;j++)
 {
  
  for(int i=0;i<5;i++)
  {
  
   sum+=prime[i];
   if(isprime(sum)==0) {
    p=0; sum-=prime[i];
   }
   else break;
  }
  sum*=10;
 }
 
 if(p==1)printf("%d",sum);
 }
 return 0;
}

