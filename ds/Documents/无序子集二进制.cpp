#include <stdio.h>
#include <string.h>
//������� ���� �Ӽ����� 
//�Ӽ����� ���ö�������� (������������ 
/* run this program using the console pauser or add your own getch, system("pause") or input loop */
char data[1000]={0};
int bk[1000] = {0};
int s[1000]={0};
/*int main(int argc, char** argv) {
	int n;//cmn
	gets(data); 
	scanf("%d",&n);
	int cnt = strlen(data);
	for(int i = 0; i < (1<<cnt); i++)
	{
		int kk = i;
		int num = 0;
		while(kk)
		{
			num++;
			kk = kk & (kk-1); //�����õ�popcnt 
		}
		if(num == n)
		{
			for(int j = 0; j < cnt; j++)
			{
				if((i>>j) & 1)
				{
					printf("%c",data[j]);
				}
			}
			printf("\n");
		}
	 } 
	return 0;
}*///ԭ��
//�İ� ��dfs

void dfs(int op,int cnt, int m,int n) 
{
	if(cnt == n) {
		for(int j=0; j<n ;j++)
		{
			printf("%3d",s[j]);
		};
		printf("\n");
		return;
	}
	for(int i = op; i < m;i++)
	{
		if(bk[i]==0){
		s[cnt] = data[i];
		bk[i] = 1;
		dfs(i+1,cnt+1,m,n);
		bk[i] = 0;
		}
	}
}

int main()
{
	int m,n;
	scanf("%d%d",&m,&n);
	for(int i = 0; i < m; i++)
	{
		data[i] = i+1;
	}
	dfs(0,0,m,n);
}
