#include <stdio.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */
int x[3000008];
int sum(int u)
{
	int su=0;
	while(u)
	{
		su+=u%10;
		u/=10; 
	}
	 return su;
}

int mult(int u)
{
	int mul=1;
	while(u>1)
	{
		mul*=u%10;
		u/=10;
	}
	return mul;
}

int isjin(int u)
{
	if(sum(u)>=20&&mult(u)>=162)
	{
		return 1;
	}
	else return 0;
}
int main(int argc, char** argv) {
	int t,l,r,num;
	for(int i=1;i<3e6+8;i++)
	{
		x[i]=isjin(i)+x[i-1];
	}
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d%d",&l,&r);
		if(x[r]-x[l-1]>0) printf("%d\n",x[r]-x[l-1]);
		else printf("404 Not Found\n");
	}
	return 0;
}
