#include <stdio.h>
long long num[1000009];
char op[1000008];
int cnt = 0;
int sum = 0;
int main()
{
	 freopen("P1981_2.in","r",stdin);
	scanf("%lld", &num[cnt]);
	while(scanf("%c", &op[cnt])!= EOF)
	{
		if(op[cnt]=='\n') continue;
		scanf("%lld", &num[++cnt]);
		num[cnt] %=10000;
	}
	for(int i = cnt-1; i >= 0; i--)
	{
		if(op[i] == '*')
		{
			num[i] = (num[i]*num[i+1])%10000;
			num[i+1] = 0;
		}
	}
	for(int i = 0; i <= cnt; i++)
	{
		sum += num[i]; 
		sum %= 10000;
	}
	printf("%d", sum);
}
