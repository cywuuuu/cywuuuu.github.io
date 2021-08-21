#include <iostream>
int p=0;
int hanoi(int n,char first,char tran,char target)
{
	if(n==1) {
	printf("%c to %c \n", first, target, p); p++;return 0;
	}
	
	else {
	hanoi(n-1,first,target,tran);
	printf("%c to %c \n",first,target);p++;
	hanoi(n-1,tran,first,target);
	}
	
}
/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char** argv) {
	int n;
	
	scanf("%d",&n);
	hanoi(n,'A','B','C');
	printf("\n %d",p);
	return 0;
}
