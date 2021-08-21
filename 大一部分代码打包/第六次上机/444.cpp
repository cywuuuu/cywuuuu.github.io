#include <stdio.h>
#include <string.h> 
char a[500][500];
/* run this program using the console pauser or add your own getch, system("pause") or input loop */
void do1 (int x,int y,int a, int b)
{	//x,y=1;
	for(int i=0;i<b;i++)
	{
		for(int j=0;j<a;j++)
		{	
			if(j<i)
			a[x+i-1][x+j-1]='A'+j;
			else 
			a[x+i-1][x+j-1]='A'+j;
		}
	}
}

int main(int argc, char** argv) {
//	int m,n;
//	scanf("%d%d",&m,&n);
	do1(1,1,5,3);
	return 0;
}
