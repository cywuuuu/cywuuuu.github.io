#include <stdio.h>

int main()
{
	int a[100008];
	int n,max=-100,min=200000000,cnt,sum=0;
	scanf("%d",&n);
	cnt=n;
	for(int i=0;i<n;i++)
	{
		scanf("%d",&a[i]);
	}
		for(int i=0;i<n;i++)
	{
		if(a[i]<min) min=a[i];
		if(a[i]>max) max=a[i];
	}
	for(int i=0;i<n;i++)
	{
		if(a[i]==max){cnt--;a[i]=0;}
		else if(a[i]==min){cnt--;a[i]=0;}
	}

	for(int i=0;i<n;i++)
	{
		sum+=a[i];
	}
	//循环内定义变量，作用域仅在循环内 eg 
	/*for（）{int sum} 外面就没的用了*/ 
	if(cnt==0) printf("#DIV/0!\n");
	if(cnt>0) printf("%.2lf\n",(double)sum/cnt);
	return 0; 
	
}
