#include <iostream>
#include <cmath>
#include <string.h>
using namespace std;
int res[2000], a[2000], b[2000];
/* run this program using the console pauser or add your own getch, system("pause") or input loop */

void mult(int x[], int y[], int res[])//1 是个位 
{
	int tmp[2000];
	memset(tmp, 0, sizeof(tmp)); 
	for(int i = 1; i <= 500; i++)
		for(int j = 1; j <= 500; j++)
			tmp[i+j-1] += x[i] * y[j];
	for(int i = 1; i <= 500; i++)
	{
		int carry = tmp[i]/10;
		tmp[i+1] += carry;
		tmp[i] = tmp[i]%10; 
	}
	memcpy(res,tmp,sizeof(tmp));
}
void add(int x[], int y[], int res[])
{
	int tmp[2000];
	memset(tmp, 0, sizeof(tmp));
	for(int i = 1; i <= 500; i++)
		for(int j = 1; j <= 500; j++)
			
}
int main(int argc, char** argv) {
	int p;
	scanf("%d", &p);
	printf("%d\n",(int)(p * log10(2) + 1));
	a[1] = 2;
	res[1] = 1;
	while(p)
	{
		if(p % 2 == 1) mult(a,res,res);
		mult(a,a,a);//是吧幂数翻倍 
		p = p/2;
	}
	res[1] -= 1;
	for(int i = 500; i >= 1; i--)
	{
		printf("%d", res[i]);
		if((i-1) % 50 == 0) printf("\n");
	}
	return 0;
}
