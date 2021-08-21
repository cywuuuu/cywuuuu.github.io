#include <stdio.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */


int main(int argc, char** argv) {
	int l,n,cnt=1;
	long long sum=0;
	int a[105];
	scanf("%d%d",&l,&n);
	for(int i=0;i<n;i++)
	{
		scanf("%d",&a[i]);
	}
	
	for(int i=0;i<n;i++)
	{
		sum+=a[i];
		if(sum==l) { sum=0;cnt++;
		}
		if(sum>l){
			sum=0;cnt+=2;i++; 
		}
	}
	printf("%d",cnt); 
	return 0;
}
	
