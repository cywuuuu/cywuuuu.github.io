#include <stdio.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char** argv) {
	double sum=0;
	
	for(int i=1;i<10000;i++)
	{
		sum+=1/ ((double)i*i*i);
	}
	printf("%.7lf",sum);
	return 0;
}//对于输出数据有个观察，看他是否收敛，不变了 
