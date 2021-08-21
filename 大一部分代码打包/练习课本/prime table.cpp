#include <iostream>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */
int isprime(int a)
{	int p=0;
	for(int i=2;i*i<=a;i++)
	{
		if(a%i==0) return 0;
	}

	return 1;
}

int main(int argc, char** argv) {
		for(int i=1;i<1000;i++)
	{
		if(isprime(i)) printf("%d ",i);
	}
	return 0;
}
