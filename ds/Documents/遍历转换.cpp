#include <stdio.h>
#include <string.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

void get(char* s1,char *s2)
{
	int len = strlen(s2);
	if(len > 0){
	 
	char ch = s2[len-1];
	char s11[1000]={0},s12[1000]={0},s21[1000]={0},s22[1000]={0};
	printf("%c",ch);
	char *p;
	if((p = strchr(s1,ch))!=NULL)
	{
		*p = '\0';p++;
		int len1 = strlen(s1);
		int len2 = strlen(p);
		strncpy(s11,s1,len1);
		strncpy(s12,p,len2);
		strncpy(s21,s2,len1);
		strncpy(s22,&s2[len1],len2);
		get(s11,s21);
		get(s12,s22); 
	}
	else return;
	
	}
}

int main(int argc, char** argv) {
	char s1[1000],s2[1000];
	scanf("%s",s1);
	scanf("%s",s2);
	get(s1,s2);
	return 0;
}
