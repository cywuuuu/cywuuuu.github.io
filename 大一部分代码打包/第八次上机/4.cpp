#include <stdio.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char** argv) {
	int t;
	scanf("%d",&t);
	int a[100]={0};
	int l;
	int sum=0;
	for(int i=0;i<t;i++)
	{
		scanf("%d",&l);
		if(a[l]<3)a[l]++;
	}
	for(int i=0;i<100;i++)
	{
		sum+=a[i];
	}
	printf("%d",sum);
	return 0;
}
