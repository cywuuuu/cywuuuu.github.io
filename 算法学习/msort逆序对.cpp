#include <iostream>
using namespace std;

/* run this program using the console pauser or add your own getch, system("pause") or input loop */
int tmp[700086];
int a[700086];
long long ans = 0;//long long
void mergesort(int l, int r)
{
	if(l >= r) return;
	int mid = ( l + r )/2;
	mergesort(l, mid);
	mergesort(mid + 1, r);
	int i,j,k;
	for( i = l,j = mid + 1,k = l; i <= mid && j <= r;)
	{
		if(a[i] <= a[j])
		tmp[k++] = a[i++];
		else 
		{
			tmp[k++] = a[j++];
			ans += mid - i + 1;//即前面组（已经排好了升序）中的右边的部分（都比a[j]要大） 
		}
	}
	while(i<=mid)
	tmp[k++] = a[i++];
	while(j<=r)
	tmp[k++] = a[j++];
	for(int i = l; i <= r; i++)
	{
		a[i] = tmp[i];
	}
}

int main(int argc, char** argv) {
	int n;
	scanf("%d", &n);
	for(int i = 0; i < n; i++)
	{
		scanf("%d",&a[i]);
	}
	mergesort(0,n-1);
	printf("%lld\n", ans);
	return 0;
}
