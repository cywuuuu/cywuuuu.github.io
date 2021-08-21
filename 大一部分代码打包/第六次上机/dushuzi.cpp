#include <stdio.h>
#include <string.h>
#include <stdlib.h>
/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char** argv) {

	char s[20];
	char p[11][100]={"ling","yi","er","san","si","wu","liu","qi","ba","jiu"};
	gets(s);
	int i=0;
	while(s[i]!='\0')
	{	
		int l=s[i]-48;
		if(s[i]=='-') printf("fu ");
		else if(s[i]=='+') printf("zheng ");
		else if(s[i]=='.') printf("dian ");
		
		else printf("%s ",p[l]);
		i++;
	}	return 0;
}
