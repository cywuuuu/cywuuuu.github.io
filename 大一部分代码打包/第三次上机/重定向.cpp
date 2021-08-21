#include <stdio.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char** argv) {
	freopen("301.txt","w",stdout);//默认会创建一个文件、如果没有的话 
	int n;
	int a[600]={0},b[600]={0},c[600]={0};
	long long d[600]={0},e[600]={0};
	double f[600]={0},g[600]={0};
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
	{
		scanf("%d",&a[i]);
		if(a[i]==1) scanf("%d%d",&b[i],&c[i]); 
		if(a[i]==2) scanf("%lld%lld",&d[i],&e[i]);
		if(a[i]==3) scanf("%lf%lf",&f[i],&g[i]);
	}
	for(int i=1;i<=n-1;i++)
	{
		if(a[i]==1) printf("%d\n",b[i]+c[i]); 
		if(a[i]==2) printf("%lld\n",d[i]+e[i]);
		if(a[i]==3) printf("%.4lf\n",f[i]+g[i]);
	}
	
		if(a[n]==1) printf("%d",b[n]+c[n]); 
		if(a[n]==2) printf("%lld",d[n]+e[n]);
		if(a[n]==3) printf("%.4lf",f[n]+g[n]);
	
	fclose(stdout);
	return 0;
}
