#include <stdio.h>
#define N 1010
#define ll long long
char str[N], *p;
char *normalize(char *x) 
	{
		if (x[1] == '-') return x + 1;
		x[0] = '+';
		return x;
	}
	
	int isDigit(char x)
	 {
	return x >= '0' && x <= '9';
	}
	ll coef[10];
int main() 
{
	int i, x0;
	scanf("%d", &x0);
	scanf("%s", str + 1);
	p = normalize(str);
	while (*p) 
	{
		int sign = (*p++) == '+' ? 1 : -1;
		ll c = 0, a = 0;
	 // coefficiency
		if ((*p) == 'x') c = 1;
		
		else {
			while (isDigit(*p))
			c = c * 10 + (*p++) - '0';
			}
	 // 'x', power
			if ((*p) == 'x') 
			{
				p++;
				if ((*p) == '^')
				{
					p++;
					while (isDigit(*p))
					a = a * 10 + (*p++) - '0';
				} 
				else 
				{
					a = 1;
				}
			}
		coef[a] += c * sign;
	}
// f(x) = f(x0) + f'(x0)(x - x0)
	ll fx = 0, dfx = 0;
	for (i = 5; i >= 0; i--) fx = fx * x0 + coef[i];
	for (i = 5; i >= 1; i--) dfx = dfx * x0 + 1LL * i * coef[i];
// px + q + R(x)
	ll p = dfx, q = fx - dfx * x0;
	int first = 1;
	if (p) 
	{
		if (p == -1) printf("-");
		else if (p != 1) printf("%lld", p);
		printf("x");
		first = 0;
	}
	if (q) 
	{
		if (!first && q > 0) printf("+");
		printf("%lld", q);
		first = 0;
	}
	if (!first) printf("+");
	printf("R(x)");
return 0;
}
