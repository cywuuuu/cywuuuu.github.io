#include <stdio.h>


//���ȹ���2��1024 �ӽ�300λ����
//����Ҳ���������ʾ ����ν�߾��� 
int a[1030];
char s[1030];
int b[1030];
int main(int argc, char** argv) {
	int x;
	long long sum=0,first=0;
	scanf("%d",&x);
	getchar();
	gets(s);
	for(int i=0;i<x;i++)
	{
		a[i]=s[i]-'0';
	}
	if(a[0]==0)
	{
		while(a[first]==0)
		{
			first++;
		}	int top=1;
		for(int i=first;i<x;i++)
		{
			int carry=0;
		
			for(int j=0;j<top;j++)
			{
				b[j]*=2;
				b[j]+=carry;
				carry=b[j]/10;
				b[j]=b[j]%10;//b�ĳ�2�Ĳ��� 
			}
			if(carry>0) b[top++]=carry;
			
			
			b[0]+=a[i];//�϶������λ ��λ*k��Զ<=9 //�൱�ڶ̳����������� 
		}
		for(int i=top-1;i>=0;i--)
		{
			printf("%d",b[i]);
		 } 
	}
	else
	{
		for(int i=x-1;i>=0;i--)
		{
			a[i]=!a[i];
		}
		while(a[first]==0)
		{
			first++;
		}
		int top=1;
		for(int i=first;i<x;i++)
		{
			int carry=0;
			for(int j=0;j<top;j++)
			{
				b[j]*=2;
				b[j]+=carry;
				carry=b[j]/10;
				b[j]=b[j]%10;//b�ĳ�2�Ĳ��� 
			}
			if(carry>0) b[top++]=carry;
			b[0]+=a[i];//�϶������λ ��λ*k��Զ<=9 //�൱�ڶ̳����������� 
		}
		b[0]++;
		printf("-");
		for(int i=top-1;i>=0;i--)
		{
			printf("%d",b[i]);
		 } 
	}
	
	
	return 0;
}
/*
#include <stdio.h>
char s[1100];
int a[1100], ans[1100];
int main()
{
	int n;
	int f = 0;
	int i, j;
	int top;
	scanf("%d", &n);
	scanf("%s", s);
	for (i = 0; i < n; i++)
	{
		a[i] = s[i] - '0';
	}
	
	if (a[0] == 1)
	{
		f = 1;
		i = n;
		while (a[--i] == 0)
		; // �ҵ����λ��1
		if (i)
		{
		for (j = 0; j < i; j++)
		a[j] = a[j] ^ 1; // ��λȡ��
		}
	}
	
	top = 1;
	
	for (i = 0; i < n; i++)
	{
		int carry = 0;
		for (j = 0; j < top; j++)
		{
			ans[j] *= 2; // ��λ��2
			ans[j] += carry; // ���Ͻ�λ
			carry = ans[j] / 10; // �����λ
			ans[j] %= 10; // ��λ�Ľ��
		}
		if (carry) // ���н�λ
		ans[top++] = carry;
		ans[0] += a[i];
	}
	
	if (f == 1)putchar('-');
	
	for (i = top - 1; i >= 0; i--)
	{
		printf("%d", ans[i]);
	}
	
	return 0;
}*/
