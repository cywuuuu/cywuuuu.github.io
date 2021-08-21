#include <iostream>
 
/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int gcd(int a, int b)
{
	if(a>b) {int t=a;a=b;b=t;
	}
	if(a==0) return b;
	else gcd(b%a,a);

}

int main() {

	int a,b,c;
	scanf("%d%d",&a,&b);
	c=gcd(a,b);
	printf("\n%d",c);
	return 0;
}
