#include <stdio.h>
#define MAX 100
/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char** argv) {
	int n;
	int c[100] = {1,1};
	scanf("%d", &n);
 for(int i = 2; i <= n; i++)
 {
 	for(int j = 0; j < i; j++)
 	{
 		c[i] += c[j]*c[i-j-1]; 
	 }
 }
 printf("%d", c[n]);
	return 0;
}
