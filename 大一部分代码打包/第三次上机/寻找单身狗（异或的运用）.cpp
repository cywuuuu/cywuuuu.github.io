#include <stdio.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */
int a[1000008]={0}; 
int main(int argc, char** argv) {
	int n,post=0,x,y;
	int result=0,tmp=0;
	scanf("%d",&n);
	for(int i=0;i<n;i++)
	{
		scanf("%d",&a[i]);
		result^=a[i];
	}
	for(int i=0;i<32;i++)
	{
		if(((result>>i)&1)) {post=i;
		break;
		}
	}
	
	if(result==0)
	{
		int max=-2147483648;
		int min=2147483647;//���ܿո����λ
		int cnt=0; 
		for(int i=0;i<n;i++)
		{
			if(max<a[i]) max=a[i];
			if(min>a[i]) min=a[i];
			if(a[i]==0) cnt++;
		}
		
		if(cnt==1) printf("1 0");//****�Ķ�����������һ�� 
		else printf("%d %d",min,max);
	}
	
	if(result!=0){
	
		tmp=result;
		for(int i=0;i<n;i++)
		{
			if(((a[i]>>post)&1)){
				tmp^=a[i]; 
			}
		}
		if(tmp==0) printf("1 %d",result);
		
		else 
			{x=tmp;
			y=result^tmp;
			if(x<y)
			{
				int tem=x;
				x=y;
				y=tem;
			 } 
			long long pp=(long long)x*y;//������long long pp=x*y;���������ʾ���ͷ���û�õģ��������ٸ�ֵ������ͳ����ˣ���������ʱת�� 
			printf("2 %lld",pp);//****�Ķ��������� 
		}
	}
	return 0;
}
