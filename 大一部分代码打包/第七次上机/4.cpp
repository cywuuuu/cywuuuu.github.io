#include <stdio.h>
#include <string.h>
/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char** argv) {
int *x;
*x = 10;

x += 10;
*x *= 2;
x -= 10;

printf("%d", *x);
	return 0;
}
