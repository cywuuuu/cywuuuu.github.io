#include <cstdio>
#include <string.h>
#include <cstdlib>
#include <ctype.h>
int main()
{
	/*
	���ǽ�����������windows����ϵͳ��system () ������⣨��Ҫ����C�����е�Ӧ�ã�
ע�⣺��windows�µ�system������������Բ������Сд��
�������� system
�� �ܣ� ����һ��DOS����
�� ���� int system(char *command);
*/
	while(1)
	{
		system("data.exe > in.in");
		system("sample.exe < in.txt > sample.out");
		system("mine.exe < in.txt > mine.out");
		if("fc sample.out mine.out") return 1;
	}




return 0;
}

