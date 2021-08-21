#include <iostream>
int cmn(int m,int n)
{
	if(n==0||m==n)
	{
		return 1;
	}
	else return m*cmn(m-1,n-1)/n;//oreder of zhengchu
}
/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char** argv) {
	int a,b;
	scanf("%d%d",&a,&b);
	printf("%d",cmn(a,b));
	return 0;
}
