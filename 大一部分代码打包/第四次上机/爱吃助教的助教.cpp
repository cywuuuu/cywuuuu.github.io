#include <stdio.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char** argv) {
	int m=0,n=0,cnt=0;
	double exp;
	int a[101][101]={0};
	int type[4]={0};//record line type number
	scanf("%d%d%lf",&m,&n,&exp);

	for(int i=0;i<m;i++)
	{	cnt=0;
		for(int j=0;j<n;j++)
		{
			scanf("%d",&a[i][j]);
		
			if(a[i][j]==0) cnt++;
		}
			if(a[i][0]==2)
			{
				type[2]++;
				
			}
		    else if(a[i][0]==3)
			{
				type[3]++;
				
			}
			
			else
			{
			if((double)cnt/n>=exp) type[0]++;
			 else type[1]++;
			 }
	}
	
	if(type[0]/m>=exp) printf("your factory has produced nice zhujiao !");
	else {
		int max=0,mark=0;
		for(int i=1;i<=3;i++)
		{
			if(max<type[i]) 
			{
				max=type[i];
				mark=i;
			} 
		}
		if(mark==1) printf("bad assembly lines !");
		if(mark==2) printf("terribly sweet !");
		if(mark==3) printf("your zhujiao are still raw !");
	}
	//�����������
	//1.���������������塢��Χ�������ݽṹ
	//2. ���̡�ϸ�ڡ���ʾ���߽��������Լ�����һ��������������̺�Ҫ�� 
		
	
		
	
	 
	
	return 0;
}
