#include <stdio.h>
#include <string.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char** argv) {
	int t;
	char s[10];
	scanf("%d",&t);
	while(t--)
	{
		//gets(s);gets���Խ��տո�;��scanf�����ո񡢻س���Tab��������Ϊ�������
		scanf("%s",s);
		if(strcmp(s,"len")==0)
		{
			char a[200];
			scanf("%s",a);
			printf("%llu\n",strlen(a));
		}
		else if(strcmp(s,"cmp")==0)
		{
			char a[200],b[200];
			scanf("%s%s",&a,&b);
			if(strcmp(a,b)==0) printf("=\n");
			if(strcmp(a,b)<0) printf("<\n");
			if(strcmp(a,b)>0) printf(">\n");//strcmp �Ƚϵ����ֵ��� 
//���ַ��ȽϹ����У�һ������ĳһ�Ա��Ƚϵ��ַ�֮�䲻���ʱ����һ���ַ��Ĵ�С��ϵ��Ϊ��һ���ַ����Ĵ�С��ϵ;
//eg. "abc" < "abd"
//���ַ��ȽϹ����У�һ������ĳһ���ַ����������ַ����Ѿ������Ƚϣ�����һ�ַ���������δ���Ƚϵ��ַ�ʱ���϶̵��ַ�����С��
//eg. "abc" < "abcde" 
		}
		else if(strcmp(s,"cat")==0)
		{
			char a[500],b[200];
			int n=0;
			scanf("%s%s",a,b);
			scanf("%d",&n);
			strncat(a,b,n);
			puts(a);
		}
	}
	return 0;
}
