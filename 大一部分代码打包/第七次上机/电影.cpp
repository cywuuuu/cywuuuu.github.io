#include <stdio.h>
#include <ctype.h>
#include <string.h>
/* run this program using the console pauser or add your own getch, system("pause") or input loop */
//�ܽ᣺1.���ⵥ�ʵĻ���ȻҪ����ո���Ȼ��Ŀ��δ��д��Ҳû����ȷ˵������Ҫ��������⣬���ܴ�����������������
//1.��������>��� �����Ƿ��ܳ��� 
char a[1008][1008];//������ 
char b[200][20];//���� 
char c[1000][20];//���հ� 
int cnt[1000];//������ 
int main(int argc, char** argv) {
	char s[1008];
	int flag=0;
	gets(s);
	for(int i=0;i<strlen(s);i++)
	{
		s[i]=tolower(s[i]);
	}
	int len=strlen(s);
	s[len]='.';
	s[len+1]='\0';
	
	char* p=s,*pp=s;
	int i=0;
	
	while((pp-s)<=len)
	{
		pp++;
		flag=0;	
		
		while(*pp=='!'||*pp=='?'||*pp=='\''||*pp==';'||*pp=='.'||*pp==','||*pp==' ')
		{
			*pp='\0';pp++;flag=1;
		}
		if(flag==1)
		{strcpy(a[i],p);i++;p=pp;
		}
			
			
			
			
		
	};
	
	int t,j=0;
	scanf("%d",&t);
	getchar(); 
	while(j<t)
	{
		gets(b[j]);
		j++;
	}
	
	for(int k=0;k<t;k++)
	{
		for(int l=0;l<i;l++ )
		{
			if(strcmp(b[k],a[l])==0)
			{
				strcpy(a[l],"++++");
			}
		}
	}
	int row=0;
	for(int l=0;l<i;l++)
	{
	flag=0;
		for(int k=0;k<row;k++)
		{
			if((strcmp(a[l],c[k])==0)&&(strcmp(a[l],"++++")!=0))
			{cnt[k]++;flag=1;
			}
			
		}
		if(flag==0&&(strcmp(a[l],"++++")!=0)) 
		{
			strcpy(c[row],a[l]);
			cnt[row]++;
			row++;
		}
	}
	int max=0,most=0;
	for(int k=0;k<row;k++)
	{
		if(cnt[k]>max) 
		{max=cnt[k];most=k;
		}
	}

printf("%s\n",c[most]);	

	
	
	
	return 0;
}
