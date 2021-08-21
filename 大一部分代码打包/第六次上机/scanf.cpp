#include <stdio.h>
#include <string.h>
char a[200];
/* run this program using the console pauser or add your own getch, system("pause") or input loop */
void add(int len)
{
	if(len==1)
	{
		if('0'<=a[len-1]&&a[len-1]<='8') 
		{
		a[len-1]++;
		puts(a);
		return;
		}
		else if (a[len-1]=='9') 
		{
			printf("10");
			for(int i=1;i<strlen(a);i++)
			{
				printf("%c",a[i]);
			}
			return;
		}
		
	}
	else{
	if('0'<=a[len-1]&&a[len-1]<='8') 
	{	
		a[len-1]++;
		puts(a);
		return;
	}
	if (a[len-1]=='9') 
	{ 
	a[len-1]='0'; 
	add(len-1);
	} 
		}
}

int main(int argc, char** argv) {
	

	scanf("%s",a);
	add(strlen(a));
	return 0;
}
