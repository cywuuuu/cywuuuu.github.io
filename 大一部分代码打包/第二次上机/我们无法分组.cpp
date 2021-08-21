#include <stdio.h>
#include <stdlib.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char *argv[]) {
	int n,cnt=0,t=0;
	long long sum=0;//仔细思考提示，思考数据范围可能带来的溢出 
	scanf("%d",&n);
	int a[205]={0};
	int b[205]={0};
	while(scanf("%d",&b[cnt])!=EOF)//循环一旦判断不成就会以后都不成了，最好进去之后在continue； EOF大写 ！小写不行！！ ，eof判断什么时候能行？
	//scanf %s无法读取空格、回车tab/ 
	//gets 无法 读取回车
	//只能读一次字符 判断控制 再 调整输出 
	{
		cnt++;
	 } 
	for(int i=0;i<cnt;i++)
	{
		sum+=b[i];
	}
		for(int i=0;i<cnt;i++)
	{

		a[cnt-i-1]=b[i];
	}
	double aveall= (double)sum/cnt;
	sum=0;
	
	for(int k=0;n*k<=cnt;k++)
	{
		sum=0;
		for(int j=0;j<n;j++)
		{
			sum+=a[n*k+j];
		}
		if((double)sum/n >= aveall) 
		{
			printf("Group:%d\n",k+1);
			for(int j=0;j<n;j++)
			{
				printf("%d\n",a[n*k+j]);
			}
		}
		
	}
	
	if(cnt%n==0)return 0;
	else 
	{
		printf("out of range\n");
		for(int j=0;j<(cnt%n);j++)
		printf("%d\n",a[cnt-cnt%n+j]);
	}
	return 0;
}
