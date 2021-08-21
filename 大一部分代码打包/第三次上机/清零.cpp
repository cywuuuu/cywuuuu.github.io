#include <stdio.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char** argv) {
	int a;
	scanf("%d",&a);
	a&=~(((1<<8)-1)<<8);  //清除8位：把1提到9位-1；变成8个1高位在7bit；提8位到15bit 
	printf("%d",a);
	return 0;
} 

