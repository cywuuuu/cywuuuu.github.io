#include <stdio.h>
	long long a[1000008]={0},b[1000008]={0};
/* run this program using the console pauser or add your own getch, system("pause") or input loop */
//审题！！！是 第 多少多少 ,不是大小多少 
int main(int argc, char** argv) {
	int m,n;

	scanf("%d%d",&m,&n);
	for(int i=1;i<=n;i++)
	{
		scanf("%lld",&a[i]);
		b[i]=b[i-1]+a[i];
	}
	while(m--)
	{
		int l,r;
		scanf("%d%d",&l,&r);
		printf("%lld\n",(b[r]-b[l-1])/(r-l+1));
	}
	return 0;
}
