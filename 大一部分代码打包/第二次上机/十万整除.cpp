#include <stdio.h>
void div(int* a,int x,int y)
{
	int i=0;
	if(x%y==0) 
	{
		a[i]=x/y; return;
	}
	
	if(x>y) 
	{
		a[i]=x/y;
		i++;
		div(a,x%y,y);
	}
	else if(x<y)
	{
		i++;
		div(a,(10*x),y);
	}
}
/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char** argv) {
	int x,y;
	scanf("%d%d",&x,&y);
	
	int a[100]={0};
	div(a,x,y); 
	
	
	return 0;
}
