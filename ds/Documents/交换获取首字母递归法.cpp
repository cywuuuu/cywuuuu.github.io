#include <stdio.h>
#include <string.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */
void swap(char *a, char *b)
{
	char tmp = *a;
	*a = *b;
	*b = tmp;
}
char data[1000];int num = 0 ;
void perm(int begin, int end)//ÿ�εݹ�
/*
1��ȷ��һ�����λ�� begin 
2����������ĸ�����������ĸ ����֤������������ĸ��ͬ ���У� 
3. ������ ԭ���λ�ã���ͬ��������������ͬ������ĸΨһ�� 
ÿһ���� �����Ƽ�С���ݹ�ģ �����ݹ� 
*/ 
{
	if(begin == end)//data���������ź��ˣ�������ȡ����Ϊ�������ʱ�ǻḴԭ�ģ��������� ֱ�������ʱ״̬�ͺ� 
	{
		num++;
		for(int j = 0;j < end; j++)
		{
			printf("%c",data[j]);
			
		 } printf(" ( %d )\n",num);
		return ;
	}
	else 
	{
		for(int i = begin; i < end ; i++)
		{
			swap(&data[begin],&data[i]);
			perm(begin+1,end);
			swap(&data[begin],&data[i]); // KEYYY!!!!!! 
		}
	}
}
int main(int argc, char** argv) {
	int i = 0;
	gets(data);
	int end = strlen(data);
	perm(0,end); 
	return 0;
}

//���Ҫ�� ��Щ����ȡ��������ȫ���У���ô�� end = 3 ���ɣ�ȡȫ���е�ǰ��������� 
