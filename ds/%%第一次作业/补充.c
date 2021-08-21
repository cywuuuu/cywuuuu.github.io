#include <string.h>
#include <stdio.h> 
#include <ctype.h>
/* run this program using the console pauser or add your own getch, system("pause") or input loop */
char s[200];
int main(int argc, char** argv) {
	scanf("%s",&s);
	char *p = s;
	while(*p != '\0')
	{
	
			if(*p == '-'&&isupper(*(p-1))&&isupper(*(p+1)))
			{
				for(int i = *(p-1)+1; i < *(p+1); i++)
				{
					printf("%c",i);
				}
			}
			else if(*p == '-'&&islower(*(p-1))&&islower(*(p+1)))
			{
				for(int i = *(p-1)+1; i < *(p+1); i++)
				{
					printf("%c",i);
				}
			}	
			else if(*p == '-'&&isdigit(*(p-1))&&isdigit(*(p+1)))
			{
				for(int i = *(p-1)+1; i < *(p+1); i++)
				{
					printf("%c",i);
				}
			}	
		
			else printf("%c",*p);
		p++; 
	}
	return 0;
}
