#include <stdio.h>
#include <string.h>
/* run this program using the console pauser or add your own getch, system("pause") or input loop */
char ma[1008][30000];
int main(int argc, char** argv) {
	int max=1;
	int i=0;
	while(gets(ma[i])!=NULL)
	{
		
		if(strlen(ma[i])>=max) 
		{
		max=strlen(ma[i]);
		i++;
		}
		
	}
	i--;
	printf("%d\n",max);
	while(i>=0)
	{
		if(strlen(ma[i])==max) printf("%s\n",ma[i]);
		i--;
	}
	return 0;
}
