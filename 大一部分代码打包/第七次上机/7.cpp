#include <stdio.h>
#include <string.h>
/* run this program using the console pauser or add your own getch, system("pause") or input loop */
int ispalindrome(char *p,int n)
{
	int i;
   	for(i=0;i<n/2;i++)
	{
		if(*(p+i)!=*(p+n-1-i)) return 0;
	}
	return 1;
}
//ע�⿴hint 
int main(int argc, char** argv) {
	char a[400];
	gets(a);
	char *p=a;
	int flag=0,cnt=0;
	for(int i=0;i<strlen(a);i++)
	{	
		flag=0;
		for(int j=2;j<=strlen(a)-i;j++)
		{
			if(ispalindrome(p+i,j)==1)
			{
				flag=1;cnt++;
			}
			
		}
	
	}

	

	if(cnt==0)
	printf("No ProbIem!\n0");
	else printf("DiDaRen Waring\n%d",cnt);
	return 0;
}
