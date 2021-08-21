#include <stdio.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */
	int a[1000008],b[1000008];
int main(int argc, char** argv) {
	int n,t;
	scanf("%d%d",&n,&t);

	for(int i=0;i<n;i++)
	{
		scanf("%d",&a[i]);
	}
	for(int i=0;i<t;i++)
	{
		scanf("%d",&b[i]);
	}
	
	for(int i=0;i<t;i++)
	{	
		int high=n-1,low=0;
		int mid=(high+low)/2;
		int search=b[i];
		int flag=0;
	
		while(high>=low)
		{	mid=(high+low)/2;
			if(a[mid]>search)
			{
				high=mid-1;
			}
			else if(a[mid]==search)
			{
				printf("true\n");
				flag=1;
				break;
			}
			else if(a[mid]<search)
			{
				low=mid+1;
			}
		}
		
		if(flag==0) printf("false\n");
	}
	
	return 0;
}
