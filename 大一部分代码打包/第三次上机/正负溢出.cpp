#include <stdio.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char** argv) {
	long long a,b;
	scanf("%lld%lld",&a,&b);
	if(a+b<0&&a>0&&b>0) printf("PO!"); //�ж�����˳�� ������ a>0&&b>0&&a+b<0 ǰ���Զ��ж�a+b>0 ���治�ж��� 
	else if(a+b>0&&a<0&&b<0) printf("NO!");
	else if(a==-9223372036854775808&&b==-9223372036854775808)printf("NO!");
	else printf("%lld",a+b);
	
	return 0;
}
