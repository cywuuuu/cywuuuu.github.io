#include <stdio.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */
	int bk[100008]={0},shang[200008]={0},yushu[100008]={0};
int main(int argc, char** argv) {
	int x,y,i=0,j=0,ox,oy,flag=0;

	scanf("%d%d",&x,&y);
	ox=x,oy=y;x=x%y;
	if(ox%oy==0) 
	{
		printf("integer\n");
		printf("%d",ox/oy);
	}
	
	else
	{
		i=0;
		while(x%y!=0)
		{
			x*=10;
			shang[i++]=x/y;	
			bk[x%y]++;
			yushu[x/y]++;
			if(x%y==0) 
			{
				flag=1;break;
			 } 
			if(bk[x%y]>=2&&yushu[x/y]>=2) break;
//商与余数不一一对应 
			x=x%y;
		}
		if(flag==0)
		{
				for(j=0;j<=i-1;j++)
			{
				if(shang[j]==shang[i-1]) break;
			}
			printf("recurring decimal\n");
			printf("%d.",ox/oy);
			for(int k=0;k<i-1;k++)
			{
				if(k==j)printf("_%d",shang[k]);
				else printf("%d",shang[k]);
			}
			printf(" [%d]",i-j-1);
		}
		else 
		{
			printf("terminating decimal\n");
			printf("%d.",ox/oy);
			for(int k=0;k<i;k++)
			{
				printf("%d",shang[k]);
			}
			printf("\n");
		}
		
		
	}
	return 0;
}
