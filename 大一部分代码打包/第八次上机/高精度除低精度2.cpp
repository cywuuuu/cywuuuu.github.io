#include <stdio.h>
#include <string.h>
#include <math.h>
/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char** argv) {
	int q;
	char s[1008];
	int a[1008];
	scanf("%d",&q);
	int last=0,first=0; 	getchar();
	while(q--)
	{
		first=0;
	
		int cnt=0;
		memset(a,0,sizeof(a));
		gets(s);
		for(int i=0;i<strlen(s);i++)
		{
			a[i]=s[i]-'0';
		}
		last=strlen(s)-1;
		while(a[first]!=0)
		{
			for(int i=first;i<last;i++)
			{
				if(a[i]%2==0)
				{
					a[i]/=2;
				}
				else
				{
					a[i+1]+=10;
					a[i]/=2;
				}
			}
			if(a[last]%2==1) 
			{
			a[last]/=2;
			cnt++;
			}
			else
			{
				a[last]/=2;
			}
			if(a[first]==0) first++;
		}
		printf("%d\n",cnt);
		
		
		
	}
	return 0;
}
