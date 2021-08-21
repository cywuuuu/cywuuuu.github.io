#include <stdio.h>
#include <string.h>
/* run this program using the console pauser or add your own getch, system("pause") or input loop */
char a[108][108];
char t[108];
int main(int argc, char** argv) {
	int n;
	scanf("%d",&n);
	getchar();
	for(int i=0;i<n;i++)
	{
		gets(a[i]);
	}
	for(int i=0;i<n-1;i++)
	{
		for(int j=0;j<n-1-i;j++)
		{
			if(strlen(a[j])>strlen(a[j+1])) 
			{
				strcpy(t,a[j]);
				strcpy(a[j],a[j+1]);
				strcpy(a[j+1],t);
			}
			
			else if (strlen(a[j])==strlen(a[j+1])) 
			{
				int k=0;
				while(a[j][k]!='\0')
				{
					if(a[j][k]!=a[j+1][k])
					{	
						
						if(a[j+1][k]=='6')
						{
							strcpy(t,a[j]);
							strcpy(a[j],a[j+1]);
							strcpy(a[j+1],t);
						}
						else if(a[j][k]!='6'&&a[j+1][k]>a[j][k])//考虑清楚 条件间的互相影响 两种发生
						// 一种条件下 xx发生，另一条件需是第一条件不发生时发生 
						{
							strcpy(t,a[j]);
							strcpy(a[j],a[j+1]);
							strcpy(a[j+1],t);
						}
						break;
					}
					k++;
				}
			}
		}
	}
	for(int i=0;i<n-1;i++)
	{
		printf("%s",a[i]);
		printf("\n");
	}
	printf("%s",a[n-1]);
	
	return 0;
}
