#include <stdio.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char** argv) {
	int n,cnt=0;
	scanf("%d",&n);
	int a[6000];
	
	for(int i=0;i<n;i++)
	{
		scanf("%d",&a[i]);
	 } 
	 
	 for(int i=0;i<n;i++)
	 {
	 	for(int j=i+1;j<n;j++)
	 	{
	 		if((a[i]&a[j])>(a[i]^a[j])) cnt++; //C�����������ȼ� λ�����߼����㿿�󣬼Ӽ����С�����ȡ��ַ�ȵ����⿿ǰ 
		 }//����������� ��a,b��(b,a)��һ��������˳������ν���������� ��a,b��(b,a)����˳��������  ����˳��ͬ���������� 
	 }
	 printf("%d",cnt);
	return 0;
}
