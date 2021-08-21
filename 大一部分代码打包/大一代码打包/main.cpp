#include <stdio.h>
/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char** argv) {
	int a[11]={0};
	int n;
	scanf("%d\n",&n);
	for(int i=0;i<n;i++)
	{
		int b;
		scanf("%d",&b);
		a[b]++;
	}
	for(int i=10;i>=0;i--)
	{
		for(int j=0;j<a[i];j++) printf("%d ",i);
	}
	
	return 0;
}
