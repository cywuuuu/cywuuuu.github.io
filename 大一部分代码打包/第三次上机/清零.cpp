#include <stdio.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char** argv) {
	int a;
	scanf("%d",&a);
	a&=~(((1<<8)-1)<<8);  //���8λ����1�ᵽ9λ-1�����8��1��λ��7bit����8λ��15bit 
	printf("%d",a);
	return 0;
} 

