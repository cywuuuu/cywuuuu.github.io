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
	//ѭ���ڶ�����������������ѭ���� eg 
	/*for����{int sum} �����û������*/ 
	if(cnt==0) printf("#DIV/0!\n");
	if(cnt>0) printf("%.2lf\n",(double)sum/cnt);
	return 0; 
	
}
