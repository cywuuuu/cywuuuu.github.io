#include <stdio.h>
#include <math.h>
	int a[1008][2];char s[100];
	int b[4][2];
/* run this program using the console pauser or add your own getch, system("pause") or input loop */
double d(int i, int j)
{
	return ((double)a[i][0]-a[j][0])*((double)a[i][0]-a[j][0])+((double)a[i][1]-a[j][1])*((double)a[i][1]-a[j][1]);
}

int main(int argc, char** argv) {
	int n,yy,wh1,wh2,wh3;
	double min=0x7fffffff;
	gets(s);
	sscanf(s,"%d%d",&n,&yy);
	for(int i=0;i<n;i++)
	{
		scanf("%d%d",&a[i][0],&a[i][1]);
	}
	for(int i=0;i<n;i++)
	{
		if(a[i][1]!=yy) continue;
		else
		{
			for(int j=0;j<n;j++)
			{
				if(i==j) continue;
				else
				{
					for(int k=0;k<n;k++)
					{
						if(((i==k)+(i==j)+(j==k))==0)
						{
							if(min>(d(i,j)+d(i,k)+d(j,k))) 
							{
								min=d(i,j)+d(i,k)+d(j,k);
								wh1=i;wh2=j;wh3=k;
							}
						}
					}
				}
			}
		}
	}	
	b[0][0]=a[wh1][0];
	b[0][1]=a[wh1][1];
	b[1][0]=a[wh2][0];
	b[1][1]=a[wh2][1];
	b[2][0]=a[wh3][0];
	b[2][1]=a[wh3][1];
	for(int i=0;i<2;i++)
	{
		for(int j=0;j<2;j++)
		{
			if(b[j][0]>b[j+1][0])
			{
				int tmp=b[j][0];
				b[j][0]=b[j+1][0];
				b[j+1][0]=tmp;
				tmp=b[j][1];
				b[j][1]=b[j+1][1];
				b[j+1][1]=tmp;
			}
		}
	}

	for(int i=0;i<2;i++)
	{
		for(int j=0;j<2;j++)
		{
			if((b[j][0]==b[j+1][0])&&b[j][1]>b[j+1][1])
			{
				int tmp=b[j][0];
				b[j][0]=b[j+1][0];
				b[j+1][0]=tmp;
				tmp=b[j][1];
				b[j][1]=b[j+1][1];
				b[j+1][1]=tmp;
			}
		}
	}
	for(int i=0;i<3;i++)
	{
		for(int j=0;j<2;j++)
		{
			printf("%d ",b[i][j]);
		}
		printf("\n");
	}
	return 0;
}
