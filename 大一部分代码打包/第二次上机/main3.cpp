#include <stdio.h>//һ��stdio 

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char** argv) {
	char c;
	int k,p=0;
	scanf("%d",&k);
	while(scanf("%c",&c)!=EOF)//scanf ����ֵ ���� eof���ж�������������c==����������������eof�� 
	{		
		if(c=='\n'&&p==0){p=1;continue;}// �������� {continue;p=1��} ԭ�� continue ̫�� pû����ֵ 
		if('a'<=c&&c<='z') 
		{
			if((c-'a'-k)<0) printf("%c", (c-'a'-k)%26+26+'a');
			if((c-'a'-k)>=0) printf("%c",(c-'a'-k)%26+'a');
		}
		else printf("%c",c);
	}
	
	return 0;
}
