#include <stdio.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */
int book[20]={0};
int pt[20]={0};
void dfs(int n,int k)
{
	if(k==n)
	{
		for(int i=1;i<=n;i++)
		{
			printf("%5d",pt[i]);
		}
		printf("\n");
		return;
	}
	
	for(int i=1;i<=n;i++)
	{
		if(book[i]==0)
		{
			book[i]=1;
			pt[k+1]=i;
			dfs(n,k+1);
			book[i]=0;//�������ʱ�� ����bk ʹ�ú������뺯��ʱ���������ã���Ȼ��� i �Ѿ��ù��ˣ������¸�ѭ���ˣ� 
//����Ҫ��Ҫreturn 0 �أ� return 0��������� 
//��Ϊ ��������return ����ѭ������ �ͻ��������ѭ�� ��ô �Ͳ��ܻ���������� ������������ڣ��� 
			
		}
	}
 } 
//ģ��dfs(���е�ͨ��Ϊλ����Ϣ������Ϣ������Ϣ��Ҫ��bk���+ѭ�� ����λ���У�) 

int main(int argc, char** argv) {
	int n;
	scanf("%d",&n);
	dfs(n,0);
	return 0;
}
