#include <stdio.h>
#include <string.h>
/* run this program using the console pauser or add your own getch, system("pause") or input loop */
char s[100009];int rank[100009];
int main(int argc, char** argv) {
	int t,l,r;
	gets(s);
	sscanf(s,"%d",&t);
	while(t--)
	{
	
		
		gets(s);r=strlen(s);	l=1;
		for(int i=0;i<(int)(strlen(s)-1);i++)
		{
			if(s[i]==s[i+1]) continue;
			if(s[i]>s[i+1]) 
			{
				int k=i;
				while(s[k]==s[i])
				{
					k--;
				}
				for(int j=k+1;j<=i;j++)
				{
					rank[j]=l;
					l++;
				}
			
			}
			else if(s[i]<s[i+1])
			{
				int k=i;
				while(s[k]==s[i])
				{
					rank[k--]=r--;
				}
				
			}
		 } 
		 rank[strlen(s)-1]=r;
		 for(int i=0;i<strlen(s);i++)
		 {
		 	printf("%d ",rank[i]);
		 }
		 printf("\n");
	}
	return 0;
}
