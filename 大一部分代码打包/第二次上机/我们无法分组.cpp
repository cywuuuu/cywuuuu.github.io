#include <stdio.h>
#include <stdlib.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char *argv[]) {
	int n,cnt=0,t=0;
	long long sum=0;//��ϸ˼����ʾ��˼�����ݷ�Χ���ܴ�������� 
	scanf("%d",&n);
	int a[205]={0};
	int b[205]={0};
	while(scanf("%d",&b[cnt])!=EOF)//ѭ��һ���жϲ��ɾͻ��Ժ󶼲����ˣ���ý�ȥ֮����continue�� EOF��д ��Сд���У��� ��eof�ж�ʲôʱ�����У�
	//scanf %s�޷���ȡ�ո񡢻س�tab/ 
	//gets �޷� ��ȡ�س�
	//ֻ�ܶ�һ���ַ� �жϿ��� �� ������� 
	{
		cnt++;
	 } 
	for(int i=0;i<cnt;i++)
	{
		sum+=b[i];
	}
		for(int i=0;i<cnt;i++)
	{

		a[cnt-i-1]=b[i];
	}
	double aveall= (double)sum/cnt;
	sum=0;
	
	for(int k=0;n*k<=cnt;k++)
	{
		sum=0;
		for(int j=0;j<n;j++)
		{
			sum+=a[n*k+j];
		}
		if((double)sum/n >= aveall) 
		{
			printf("Group:%d\n",k+1);
			for(int j=0;j<n;j++)
			{
				printf("%d\n",a[n*k+j]);
			}
		}
		
	}
	
	if(cnt%n==0)return 0;
	else 
	{
		printf("out of range\n");
		for(int j=0;j<(cnt%n);j++)
		printf("%d\n",a[cnt-cnt%n+j]);
	}
	return 0;
}
