#include <iostream>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */
int search(int* a,int low,int high,int v)
{
	
	if(low>high) return -1;
	int p=(low+high)/2;
	if(v==a[p]) return p;
	
	else if(a[p]<v)
	{
		
		search(a,(low+high)/2+1,high,v);
	}

	else
		search(a,low,(low+high)/2-1,v);
	
	
	

} 

int main(int argc, char** argv) {
	int a[1000];
	int v,n;
	scanf("%d %d",&n, &v);
	for(int i=0;i<n;i++)
	{
		scanf("%d",a[i]);
	}
	printf("%d",search(a,0,n-1,v ));
	return 0;
}
