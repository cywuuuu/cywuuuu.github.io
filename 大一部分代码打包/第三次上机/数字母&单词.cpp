#include <stdio.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char** argv) {
	int a[95]={0};
	char ch,p;
	int cnt=1,l=0,flag=0;
	while ( ( ch = getchar() ) != EOF ) {
		if(l==0)
		{
			l=1;
			if((65<=ch&&ch<=90)||(ch>=97&&ch<=122))	{flag=1;a[ch-32]++;//�߼���ϵ���������ڲ��ң��ⲿ���� �� 
			}
			if((ch>=32&&ch<=64)||(ch>=91&&ch<=96)||(ch>=123&&ch<=126)) flag=0;
		}

		else if(l==1) {
		
		if(flag==1&&((65<=ch&&ch<=90)||(ch>=97&&ch<=122))) //ǰ��Ϊ��ĸ ����Ϊ��ĸ 
		{a[ch-32]++;flag=1;
		}
		else if(flag==1&&((ch>=32&&ch<=64)||(ch>=91&&ch<=96)||(ch>=123&&ch<=126)))//ǰ��Ϊ��ĸ������Ϊ���� 
		{
			cnt++; flag=0; 
		}
		else if(flag==0&&((65<=ch&&ch<=90)||(ch>=97&&ch<=122)))// ǰ���� ����ĸ 
		{
			flag=1;a[ch-32]++;
		}
		else if(flag==0&&((ch>=32&&ch<=64)||(ch>=91&&ch<=96)||(ch>=123&&ch<=126))) //ǰ����� �������
		{
			flag=0;
		}
		}
		
	 }
	int max=0;
	for(int i=33;i<=58;i++)
	{
		if(a[i]+a[i+32]>max) max=a[i]+a[i+32];
	}
	
	for(int i=33;i<=58;i++)
	{
		if(a[i]+a[i+32]==max) printf("%c",i+64);
	}
	printf("\n");
	printf("%d",cnt);
	return 0;
}
