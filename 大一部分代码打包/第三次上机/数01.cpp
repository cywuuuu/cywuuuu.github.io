#include <stdio.h>
#include <math.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */
int cntone(int x)
{	
	if(x==0) return 0;
	int cnt=0;
	for(int k=0;k<21;k++)
	{
		cnt+=((x>>k)&1);
	}
	return cnt;
}
int cntzero(int x)
{
	if(x==0) return 1;
	int cnt=0,flag=0;
	for(int p=19;p>=0;p--)
	{
		if(((x>>p)&1)&&flag==0)
		{
			flag=1;
		}
		if(((x>>p)&1)==0&&flag==1)  //λ���� 1.����һ���������2.ȡ01ֱ�����ơ��� 3.λ�������ȼ��ܵ͵� 
		{
			flag=1;cnt++;
		}
		
	}
	return cnt;
}
 


int main(int argc, char** argv) {
	int l,r;
	scanf("%d%d",&l,&r);
	long long sumone=0,sumzero=0;
	for(int i=l;i<=r;i++)
	{
		
		
		
		sumone+=cntone(i);
		sumzero+=cntzero(i);
	}
	printf("%lld %lld",sumzero,sumone);
	
	 
	return 0;
}
