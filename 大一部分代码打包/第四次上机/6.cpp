#include <stdio.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char** argv) {
	int n;
	char c;
	scanf("%c%d",&c,&n);
	for(int i=0;i<2*n+1;i++)
	{
		if(i<n)
		{
		
		for(int j=0;j<n-i-1;j++)
		{
			printf("%c",c);
		}
		for(int j=0;j<2*i+1;j++)
		{
			if(j<=i) 
			printf("%c",'A'+j);
			if(j>i)
			printf("%c",'A'+i-(j-i));
		}
		for(int j=0;j<n-i-1;j++)
		{
			printf("%c",c);
		}
		printf("\n");
		}
	
		
		if(i>n+1)
		{
		
		for(int j=0;j<n-(2*n-i)-1;j++)
		{
			printf("%c",c);
		}
		
		for(int j=0;j<2*(2*n-i)+1;j++)
		{
			if(j<=(2*n-i)) 
			printf("%c",'A'+j);
			if(j>(2*n-i))
			printf("%c",'A'+(2*n-i)-(j-(2*n-i)));
		}
		for(int j=0;j<n-(2*n-i)-1;j++)
		{
			printf("%c",c);
		}
		printf("\n");
		}
	}
	return 0;
}
