#include <stdio.h>


//首先估计2的1024 接近300位！！
//整数也得是数组表示 ，所谓高精度 
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
				b[j]=b[j]%10;//b的乘2的操作 
			}
			if(carry>0) b[top++]=carry;
			
			
			b[0]+=a[i];//肯定不会进位 个位*k永远<=9 //相当于短除法的逆运算 
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
				b[j]=b[j]%10;//b的乘2的操作 
			}
			if(carry>0) b[top++]=carry;
			b[0]+=a[i];//肯定不会进位 个位*k永远<=9 //相当于短除法的逆运算 
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
		; // 找到最低位的1
		if (i)
		{
		for (j = 0; j < i; j++)
		a[j] = a[j] ^ 1; // 高位取反
		}
	}
	
	top = 1;
	
	for (i = 0; i < n; i++)
	{
		int carry = 0;
		for (j = 0; j < top; j++)
		{
			ans[j] *= 2; // 本位乘2
			ans[j] += carry; // 加上进位
			carry = ans[j] / 10; // 算出进位
			ans[j] %= 10; // 本位的结果
		}
		if (carry) // 还有进位
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
