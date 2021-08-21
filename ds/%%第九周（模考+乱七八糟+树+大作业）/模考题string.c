#include <stdio.h>
#include <ctype.h>
#include <string.h>
/* run this program using the console pauser or add your own getch, system("pause") or input loop */
	char s1[200];
	char s2[200];
	char ans[200]; 
int main(int argc, char** argv) {

	gets(s1);
	gets(s2);
	int m;
	int n;
	int type = 0;//×ó¶ÔÆë 
	
	if(s1[1] == '-')
	{
		type = 1;
	}//ÓÒ¶ÔÆë 
	if(type == 1)
	{
		sscanf(s1,"%%-%d:%dS", &m,&n);
	}
	else
	{
		sscanf(s1,"%%%d:%dS", &m,&n);
	}
	
	for(int i = 0; i < n; i++)
	{
		ans[i] = '#';
	 }
	s2[m] = '\0';
	//%-20:30S
//Hello, word!
	int len = strlen(s2);
	
	if(type == 0)//×ó¶ÔÆë 
	{
		strncpy(ans,s2, len);
	}
	else if(type == 1)
	{
		if(len > n)
		strncpy(ans,s2,len);
		else
		{
			strncpy(ans+ n - len, s2,len);
		 }
	}
	printf("%s",ans);
		return 0;
}
/*
##################Hello, word!
##################Hello, word!
%8:30S
Hello, word!
*/
