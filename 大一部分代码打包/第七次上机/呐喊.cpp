#include <stdio.h>
#include <string.h>
#include <ctype.h>
/* run this program using the conso
注意是否会去等！！！边界条件很重要，平时就要注意好 

le pauser or add your own getch, system("pause") or input loop */
char a[100][120];
int isone(char *s)
{
	if(strcmp(s,"Yahoo!")==0) return 1;
	else return 0;
}

int istwo(char *s)
{
	char* p=s;
	if((p=strrchr(s,'='))!=NULL)
	{
		while(p>=s)//可以出现在第一位 
		{	
			
			if(*p=='+') return 1;
			p--; 
		}
		return 0;
	}
	
	else return 0;
}

int isthree(char *s)
{
	if(s[strlen(s)-1]=='\\') return 1; //即便是字符单独也要转义 
	else return 0;
}

int isfour(char *s1,char *s2)
{
	int cnt=0;
	if(strlen(s1)==strlen(s2))
	{
		for(int i=0;i<strlen(s1);i++)
		{
			if(s1[i]!=s2[i]) cnt++;
		}
		if(cnt==1||cnt==0) return 1;
		else return 0;
	}
	else return 0;
}

int isfive(char *s)
{
	int flag=0;
	for(int i=0;i<strlen(s);i++)
	{
		if(isalpha(s[i])) 
		{
			flag=1;
			if(isupper(s[i])) return 0;
		}
		
	}
	if(flag==0) return 0;
	else return 1;
}


int main(int argc, char** argv) {
char s1[30],s2[30];//s1上一个 s2新的
		gets(s1);
		int j=0;
	if(isone(s1))
	{
		strcpy(a[j],"Yahuu!");
	}
	else if(istwo(s1))
	{
		strcpy(a[j],"......");
	}
	else if(isthree(s1))
	{
		strcpy(a[j],s1);
		a[j][strlen(s1)-1]='\0';
	}
	else if (isfive(s1))
	{
		a[j][0]='\\';
		for(int i=0;i<strlen(s1);i++)
		{
			
				a[j][i+1]=toupper(s1[i]);
			
		}
		a[j][strlen(s1)+1]='/';
		
	}
	else {
		strcpy(a[j],s1);
	}
	strcpy(s2,s1);
	while(gets(s1)!=NULL)
	{
		j++;
		if(isone(s1))
		{
			strcpy(a[j],"Yahuu!");
		}
		else if(istwo(s1))
		{
			strcpy(a[j],"......");
		}
		else if(isthree(s1))
		{
			strcpy(a[j],s2);
			strcat(a[j],s1);
			a[j][strlen(a[j])-1]='\0';
		
		}
		else if(isfour(s1,s2))
		{
			strcpy(a[j],"Repeat:");
			strcat(a[j],s2);
		}
		else if (isfive(s1))
		{
			a[j][0]='\\';
			for(int i=0;i<strlen(s1);i++)
			{
				
					a[j][i+1]=toupper(s1[i]);
				
			}
			a[j][strlen(s1)+1]='/';
			
		}
		else {
			strcpy(a[j],s1);
		}
		strcpy(s2,s1);
	  }  
	
for(int i=j;i>=1;i--)
{
	puts(a[i]);
}
printf("%s",a[0]);
	return 0;
}
