#include <stdio.h>
#include <string.h>
/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char** argv) {
	char a[108];
	
	while(gets(a)!=NULL)
	{
		int flag=0;
		int bk[128]={0};
		for(int i=0;i<strlen(a);i++)
		{
			bk[a[i]]++;
			
		}
		/*for(int i=32,i<=64;i++)
		{
			if(bk[i]>0)
			{flag=1;
			break;
			}
			
		}
		for(int i=91;i<=96;i++)
		{
			if(bk[i]>0)
			{flag=1;
			break;
			}
		}
		for(int i=123;i<=126;i++)
		{
			if(bk[i]>0)
			{flag=1;
			break;
			}
		}*/
		for(int i=65;i<=90;i++)
		{
			if(bk[i]==0&&bk[i+32]==0)
			{
				flag=1;
				break;
			}
		}
		
		if(flag==1) printf("No\n");
		if(flag==0) printf("Yes\n");
	}
	return 0;
}
