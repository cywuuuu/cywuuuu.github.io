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
		while(len!=0&&s2[i]!=s2[len+1])//注意啦！！ len若可以为0 则开始会被卡住  //不匹配但是小了没准可以
		//针对一个 i （及i处的真前后缀匹配）(i trasverse through the whole)  用while 往前跳  
			len=next[len];
		if(s2[i]==s2[len+1]){
			len++;}
			next[i]=len;//匹配了就+1； 
		
		
		
	}
}

int kmp(char *s1, char *s2)
{
	int i=0,j=0;
	int len1 = strlen(s1+1);
	int len2 = strlen(s2+1);//strlen 出去！！ 
	for( i = 1;i <= len1; i++)//i一直动着 ，没必要匹配成功了，i在回去，j会自动调整的 
	{
		
		while(j>0 && s1[i]!=s2[j+1])//调整移动时 i 不变  
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
