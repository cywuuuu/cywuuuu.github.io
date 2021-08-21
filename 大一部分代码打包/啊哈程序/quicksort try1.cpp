#include <stdio.h>
int a[101],n;
/* run this program using the console pauser or add your own getch, system("pause") or input loop */

void quicksort(int left,int right)
{
	if(left>right) return;
	int i=left;
	int j=right;
	int	tmp=a[left];
	while(i!=j)
	{
		while(i<j&&a[j]>=tmp) j--;
		while(i<j&&a[i]<=tmp) i++;
		if(i<j) {
			int t=a[i];
			a[i]=a[j];
			a[j]=t;
		}
	}
		a[left]=a[i];
		a[i]=tmp;
		quicksort(left,i-1);
		quicksort(i+1,right);
		return;
					
}


int main(int argc, char** argv) {
	int i,j;
	scanf("%d",&n);
	for(i=0;i<n;i++)
	{
		scanf("%d",&a[i]);
		}	
		
	quicksort(0,n-1);
	for(i=0;i<n;i++)
	{
		printf("%d",a[i]);
		}		
	return 0;
}
