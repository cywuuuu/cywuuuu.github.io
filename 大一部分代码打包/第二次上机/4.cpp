#include <stdio.h>

int main()
{
	int a[100008];
	int n,max=0,min=10^9,cnt,sum=0;
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
	//ѭ���ڶ�����������������ѭ���� eg sum 
	if(cnt==0) printf("#DIV/0!");
	if(cnt>0) printf("%.2lf",(double)sum/cnt);
	return 0; 
	
}
