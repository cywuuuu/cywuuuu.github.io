#include <stdio.h>
#include <string.h>
/* run this program using the console pauser or add your own getch, system("pause") or input loop */


int main(int argc, char** argv) {
	int n;
	char s[108][108],m[2000];
	int flag=0;
	gets(s[0]);
	sscanf(s[0],"%d",&n);
	for(int i=0;i<n;i++)
	{
		gets(s[i]);
	}
	gets(m);
	int i=0;
	while(i<strlen(m))
	{
		for(int j=0;j<n;j++)
		{
			flag=0;
			for(int k=0;k<strlen(s[j]);k++)
			{
				if(s[j][k]!=m[k+i])
				{
					flag=1;
					break;
				}
			}
			if(flag==0) {
			i+=strlen(s[j]);
			printf("m%d",j);
			break;}
			//暴力解法即可，无需考虑多解可能？ 
		}
		
	}
	return 0;
}
