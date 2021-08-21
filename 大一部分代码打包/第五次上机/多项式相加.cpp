#include <stdio.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */
void compprt(int k,int p);
	long long a[200008],s[200008],b[200008],t[200008];int n,m;//系数 指数 
int main(int argc, char** argv) {
	
	scanf("%d%d",&n,&m);
	for(int i=0;i<n;i++)
	{
		scanf("%lld%lld",&a[i],&s[i]);
	}
	for(int i=0;i<m;i++)
	{
		scanf("%lld%lld",&b[i],&t[i]);//数据加入范围 
	}
/*	if(s[0]>=t[0])
	{	
		int i=0;
		while(s[i]>t[0])
		{
			printf("%lld %lld ",a[i],s[i]);
			i++;
		}
		compprt(i,0);
		
	}
	else if(s[0]<=t[0]) 
	{
		int i=0;
		while(t[i]>s[0])
		{
			i++;
			printf("%lld %lld ",b[i],t[i]);
		}
		compprt(0,i);
	}*/
	compprt(0,0);
	return 0;
}

void compprt(int k,int p)
{
	if(k>n-1&&p<m-1)//是否等？ 
	{
		for(int j=p;j<m;j++)
		{
			if(b[j]!=0)printf("%lld %lld ",b[j],t[j]);
		}
		return;
	}
	if(k<n-1&&p>m-1)
	{
		for(int j=k;j<n;j++)
		{
			if(a[j]!=0)printf("%lld %lld ",a[j],s[j]);
		}
		return;
	}
	if(k>=n&&p>=m) return;
	else
	{
	
		if(s[k]>t[p]) 
		{
			if(a[k]!=0)printf("%lld %lld ",a[k],s[k]);
			compprt(k+1,p);
		}
		if(s[k]==t[p]) 
		{	
			if((a[k]+b[p])!=0)printf("%lld %lld ",a[k]+b[p],s[k]);
			compprt(k+1,p+1);
		}
		if(s[k]<t[p])
		{
			if(b[p]!=0)printf("%lld %lld ",b[p],t[p]);
			compprt(k,p+1);
		 } 
	}
	
}
