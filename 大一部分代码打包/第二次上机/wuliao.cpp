#include <stdio.h>
#include<math.h>
int main()
{
 long long s=0,i,n;
 while(scanf("%d",&n)!=EOF)
 { 
 int a[n];
 s=0;
 for(i=0;i<n;i++)
 {
  	scanf("%d",&a[i]);
	

 } 
  for(i=0;i<n;i++){
  s+=a[i]*pow(10,i);
  }
  
 if(s%2==0)
 {
  printf("Smash it with 2!\n");
 }
 else if(s%3==0)
 {
  printf("Smash it with 3!\n");
  } 
 else if(s%5==0)
 {
  printf("Smash it with 5!\n");
 }
 else if(s%7==0)
 {
  printf("Smash it with 7!\n");
 }
 else if(s%11==0)
 {
  printf("Smash it with 11!\n");
 }
 else if(s%13==0)
 {
  
   printf("Smash it with 13!\n");
 }
 else
 {
  printf("qwq\n");
 }
 }
}
