#include <stdio.h>
#include <math.h>
/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char** argv) {
	int x[10086]={0},y[10086]={0},m,n;
	scanf("%d%d",&m,&n);
	int i=0,cnt=0,sum=0;
	char p;
	while(scanf("%c",&p)!=EOF)//scanf中的转换类型，要保证读入的数和%一致，存时转换 
	{
		if(p!='\n'){ //排除 
		x[i]=p;
		i++;cnt++;
		}
	}
	for(int i=1;i<=cnt;i++)
	{
		if(x[i]>='A'&&x[i]<='Z') x[i]=x[i]-'A'+10;
		if(x[i]>='0'&&x[i]<='9') x[i]=x[i]-'0';
	}
	
	for(int i=0;i<cnt;i++)
	{
		sum+=x[i]*pow(m,cnt-1-i);
	}


	return 0;
}
