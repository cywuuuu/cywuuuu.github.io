#include <stdio.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */
	int a[100080]={0};
	int b[100080]={0}; //ʮ����η�������5���㣬��λ�� 
int main(int argc, char** argv) {

	int n;	
	int flag=1;
	scanf("%d",&n);
	for(int i=0;i<n;i++)
	{
		scanf("%d",&a[i]);
	}
		for(int i=0;i<n;i++)
	{
		scanf("%d",&b[i]);
	}

	for(int i=1;i<n;i++)
	{
		if(a[i-1]>=a[i]||b[i-1]>=b[i])//Ҫ�ϸ������ܵ� 
		{
		
		if (a[i]<=b[i-1]||b[i]<=a[i-1]){flag=0;printf("no");break;} //�����飬reg��Χ�������ų�ȡ���û� 
		else {
			int tmp=a[i];
			a[i]=b[i];
			b[i]=tmp;
		}
		}
	}

	if(flag==1) printf("yes");
	return 0;

}
