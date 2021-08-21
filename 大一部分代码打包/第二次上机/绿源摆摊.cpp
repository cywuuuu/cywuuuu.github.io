#include <stdio.h>
#include<malloc.h>
/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char** argv) {
	int n,cnt=0,sum=0;
	int *a=(int *)malloc(1000008*sizeof(int));
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
	{
		scanf("%d",&a[i]);
	}
	a[n+1]=a[1];
	a[0]=a[n];
	for(int i=1;i<=n;i++)
	{
		if(a[i]>a[i-1]&&a[i]>a[i+1]) {
			cnt++;sum+=a[i];
		}
	}
	printf("%d %d",cnt,sum);
	free(a);
	
	return 0;
}
