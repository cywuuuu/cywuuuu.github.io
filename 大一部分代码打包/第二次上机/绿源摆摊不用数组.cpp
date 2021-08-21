#include <stdio.h>
	//判断可能输出结果的类型 long long sum!!! 要考虑可能的计算；仔细读题 
/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char** argv) {
	int n,cnt=0;
	long long sum=0;
	int a,b,c,p,first,second;
	scanf("%d",&n);
	scanf("%d%d%d",&a,&b,&c);
	first=a;
	second=b;
	if(b>a&&b>c){
		cnt++;
		sum+=b;
	}
	
	if(scanf("%d",&p)==EOF)
	{
		if(first>c&&first>second)
	{
			
		cnt++;
		sum+=first;
	}
	
		if(c>first&&c>b)
	{
			
		cnt++;
		sum+=c;
	}
	}
	else
	{
		a=b;
		b=c;
		c=p;
		if(b>a&&b>c)
		{
			cnt++;
			sum+=b;
		}

		while(scanf("%d",&p)!=EOF)
		{
			a=b;
			b=c;
			c=p;
			if(b>a&&b>c)
			{
				cnt++;
				sum+=b;
			}
		}
	
		if(first>c&&first>second)
		{
			
			cnt++;
			sum+=first;
		}
	
		if(c>first&&c>b)
		{
			
			cnt++;
			sum+=p;
		}
	}

	
	
	printf("%d %lld",cnt,sum); 

	return 0;
}
