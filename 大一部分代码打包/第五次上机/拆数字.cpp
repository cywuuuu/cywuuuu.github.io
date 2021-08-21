#include <stdio.h>
#include <math.h>
/* run this program using the console pauser or add your own getch, system("pause") or input loop */
void prtnumber(int u)
{	
	int i=20;
	while(i>0)
	{	
		if(u>=pow(3,i)&&i>=2)
		{
			if(u>pow(3,i))
			{
			
			printf("3(");
			prtnumber (i);
			printf(")+");
			u=u-pow(3,i);}
			else
			{
				printf("3(");
				prtnumber (i);
				printf(")");
				u=u-pow(3,i);
			}
		}
			
		else
		{
			i--;
		}
		if(u==8)
		{
			printf("3+3+1+1");
			return;
		}
		if(u==7)
		{
			printf("3+3+1");
			return;
		}
		if(u==6)
		{
			printf("3+3");
			return;
		}
		if(u==5)
		{
			printf("3+1+1");
			return;
		}
		if(u==4)
		{
			printf("3+1");
			return;
		}
		if(u==3)
		{
			printf("3");
			return;
		}
		if(u==2)
		{
			printf("1+1");
			return;
		}
		if(u==1)
		{
			printf("1");
			return;
		}
		
		
		
	}

}

int main(int argc, char** argv) {
	int n;
	scanf("%d",&n);
	prtnumber(n);
	return 0;
}
