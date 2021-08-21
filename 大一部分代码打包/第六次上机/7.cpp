#include <stdio.h>
#include <string.h>
/* run this program using the console pauser or add your own getch, system("pause") or input loop */
char a[3000];
int main(int argc, char** argv) {
	int num=0;
	while(gets(a) != NULL)
	{
		num=0;
		for(int i=0;i<strlen(a)-3;i++) // unsinged int -3 可能溢出
		// (int)strlen(a) -3 是正解 
		{
		
			if((a[i]=='w'||a[i]=='W')&&(a[i+1]=='o'||a[i+1]=='O')&&(a[i+2]=='o'||a[i+2]=='O')&&(a[i+3]=='F'||a[i+3]=='f'))
			{	
			num++;
				a[i]='W';a[i+1]='O';a[i+2]='O';a[i+3]='F';
			}
			
		}
		printf("%d\n",num);
		puts(a);
		
	}
	return 0;
}
