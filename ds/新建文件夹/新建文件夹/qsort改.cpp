#include <bits/stdc++.h>
int a[5000008];
void swap(int &a,int &b)
{
	int tmp = a;
	a = b;
	b = tmp;
}
/* run this program using the console pauser or add your own getch, system("pause") or input loop */
void qsort(int l, int r,int k)
{
	int i = l;
	int j = r;
	int mid = a[(l+r)>>1];
	do{
		while(a[j]>mid) j--;
		while(a[i]<mid) i++;
		if(i<=j) 
		{
			swap(a[i],a[j]);
			i++;
			j--;
		}
	}while(i<=j);
	if( k <= j) qsort(1,j,k);
	else if( i<=k ) qsort(i,r,k);
	else if(j<k&&k<i) {
		printf("%d",a[j+1]);
		return;
	}
	
}
int main(int argc, char** argv) {
	int n,k;
	scanf("%d%d",&n,&k);
	for(int i = 0; i < n; i++)
	{
		scanf("%d",&a[i]);
	}
	qsort(0,n-1,k);
	return 0;
}
