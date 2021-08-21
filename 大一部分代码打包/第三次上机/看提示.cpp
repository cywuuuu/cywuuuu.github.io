#include <stdio.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */
//考虑数据范围、大点好；看清题目变量再动 
int main(int argc, char** argv) {
	long long a;
	scanf("%lld",&a);
	printf("%lld\n",(a ^ 114514) >> 2);
	if(((((a ^ 114514) >> 2) + 521) & 1) > 0 ) printf("I can see the hint");
	else printf("HINT!");
	return 0;
}
