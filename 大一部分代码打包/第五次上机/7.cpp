#include <stdio.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */
int a1[100008]={0},xb1[100008]={0},a2[100008]={0},xb2[100008]={0},a3[100008]={0},xb3[100008]={0};

int main(int argc, char** argv) {
	int n,m;
	
	scanf("%d%d",&n,&m);
	for(int i=0;i<n;i++)
	{
		scanf("%d%d",&a1[i],&xb1[i]);
	}
	for(int i=0;i<m;i++)
	{
		scanf("%d%d",&a2[i],&xb2[i]);
	}
	int p=0;
	for(int i=0;i<m;i++)
	{
		for(int j=0;j<n;j++)
		{
			if(xb1[i]==xb2[j]) 
			{	
				
				a3[p]=a1[i]+a2[i];
				p++;
			}
			else if (a1[])
		}
	}
	return 0;
}
