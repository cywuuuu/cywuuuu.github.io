#include <stdio.h>
#include <math.h>
// �ô����޹����ų��ر����� ��Сn��Χ�� 1e8 
//��1e8��Χ�� 1234 �ᳬ�ޣ��� 5 6����
//�ҵ�4,5�ֽ���зֿ�
//С��ʱ��1,2,3,4,5,6������
//���ʱ��ֻ�ÿ���5,6���� 
// ȡС��Χ �˷�Χ����alg1<alg2�ĳ�����Χ���ֿ��Ա�֤alg1������
//����ȡ����Χʱ alg1���ڳ������������Χ ���迼��
// ͬ��  
long long alg1(long long n)
{	long long u=1;
	for(long long i=n;i>=n-3;i--)
	{
		u*=i;
	}
	u=u/24;
	return u+1;
}

long long alg2(long long n)
{
	long long u=1;
	for(long long i=n;i>=n-2;i--)
	{
		u*=i;
	}
	return u+2;
}

long long alg3(long long n)
{
	return n*(n-7)/2+23333; 
}

long long alg4(long long n)
{	
	return n*(long long)floor(sqrt((double)n))+233333;    //����ת��double�᲻��Σ�� ??
}

long long alg5(long long n)
{	
	return n*(long long) ceil(log2(n))+2333333;
}
long long alg6(long long n)
{
	return 2*n+19522020;
}


/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char** argv) {
	int t;
	scanf("%d",&t);
while(t--)
{	long long alg[7]={0};
	long long n;
	scanf("%lld",&n);
	if(n>1e8) printf("6\n");
	else if(n<=800)
	{
		long long min=1e19;
		alg[1]=alg1(n);
		alg[2]=alg2(n);
		alg[3]=alg3(n);
		alg[4]=alg4(n);
		alg[5]=alg5(n);
		alg[6]=alg6(n);
		for(int i=1;i<=6;i++)
		{
			if(min>alg[i]) 
			{
				min=alg[i];
			}	
		}
		
			for(int i=1;i<=6;i++)
		{
			if(min==alg[i]) 
			{
				printf("%d\n",i);
				break;
			}	
		}
	}

		else if(n<1000000)
	{
		long long min=1e19;
		alg[4]=alg4(n);
		alg[5]=alg5(n);
		alg[6]=alg6(n);
		for(int i=4;i<=6;i++)
		{
			if(min>alg[i]) 
			{
				min=alg[i];
			}	
		}
		
			for(int i=4;i<=6;i++)
		{
			if(min==alg[i]) 
			{
				printf("%d\n",i);
				break;
			}	
		}
	}
	
	else 
	{
		long long min=1e19;
		
		alg[5]=alg5(n);
		alg[6]=alg6(n);
		for(int i=5;i<=6;i++)
		{
			if(min>alg[i]) 
			{
				min=alg[i];
			}	
		}
		
			for(int i=5;i<=6;i++)
		{
			if(min==alg[i]) 
			{
				printf("%d\n",i);
				break;
			}	
		}
	}
	
}	
	return 0;
}
