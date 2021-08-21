#include <stdio.h>
#include <string.h>
int next[1000008];	char s1[1000008],s2[1000008];
/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int gennext(int *next,char *s2)
{
	next[0]=0;
	int len=0;
	int len2 = strlen(s2+1);
	for(int i = 2;i <= len2; i++)
	{
		while(len!=0&&s2[i]!=s2[len+1])//ע�������� len������Ϊ0 ��ʼ�ᱻ��ס  //��ƥ�䵫��С��û׼����
		//���һ�� i ����i������ǰ��׺ƥ�䣩(i trasverse through the whole)  ��while ��ǰ��  
			len=next[len];
		if(s2[i]==s2[len+1]){
			len++;}
			next[i]=len;//ƥ���˾�+1�� 
		
		
		
	}
}

int kmp(char *s1, char *s2)
{
	int i=0,j=0;
	int len1 = strlen(s1+1);
	int len2 = strlen(s2+1);//strlen ��ȥ���� 
	for( i = 1;i <= len1; i++)//iһֱ���� ��û��Ҫƥ��ɹ��ˣ�i�ڻ�ȥ��j���Զ������� 
	{
		
		while(j>0 && s1[i]!=s2[j+1])//�����ƶ�ʱ i ����  
		{
			j=next[j];
		}	
		
		if(s1[i]==s2[j+1])
		{
			j++; 
		}
		if(j==len2)
		{
			printf("%d\n",i-len2+1);j=next[j];
		}
	}
}

int main(int argc, char** argv) {
	scanf("%s",s1+1);
	scanf("%s",s2+1); 
	gennext(next, s2);
	kmp(s1,s2);
	int len2 = strlen(s2+1);
	for(int i=1;i<=len2 ;i++)
	{
		printf("%d ",next[i]);
	}
	
	
	return 0;
}
