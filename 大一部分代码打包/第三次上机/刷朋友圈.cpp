#include <stdio.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */
//���������ջ񣺲����⣻��ע��߽��������ڱ�Եʱ����ʼ��󣩿��Ǵ�ʱ����� 
//���� ��ʼ�ͻ��ʼ����һ�� ����cnt=1������ʱ������һ�Ѿ�մ��������޿ɷ��ʲ����ٷ������Ź�����ĻҲֻ�跭һ�μ��� 
int main(int argc, char** argv) {
	long long l,n,cnt=1;
	long long sum=0;
	long long a[105];
	scanf("%lld%lld",&l,&n);
	for(int i=0;i<n;i++)
	{
		scanf("%lld",&a[i]);
	}
	
	for(int i=0;i<n;i++)
	{
		sum+=a[i];
		if(sum==l) { sum=0;cnt++;if(i==n-1)cnt--;
		}
		if(sum>l){
			sum=0;cnt+=2;
			if(i==n-1)cnt--;
		}
	}
	printf("%lld",cnt); 
	return 0;
}

