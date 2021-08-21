#include <iostream>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char** argv) {
	int n,hd=0,tl=0;
	int a[50000],b[50000];
	scanf("%d",&n);
for(int i=0;i<n;i++)
{
	scanf("%d %d",&a[i],&b[i]);
}
for(int i=0;i<n-1;i++)
{
	if(b[i]>=a[i+1])
	{
		tl=i+1;
	}
	if(b[i]<a[i+1])
	{
		printf("(%d,%d) %d %d",a[hd],b[tl],hd,tl);
		hd=i+1;tl=i+1;
	}
	
}	
		printf("(%d,%d) %d %d",a[hd],b[tl],hd,tl);	
	
	return 0;
}
