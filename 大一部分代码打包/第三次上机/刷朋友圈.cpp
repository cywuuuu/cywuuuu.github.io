#include <stdio.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */
//本题最大的收获：步骤题；请注意边界条件；在边缘时（开始最后）考虑此时的情况 
//本题 开始就会初始化翻一次 所以cnt=1；最终时考虑万一已经沾满则后面无可翻故不用再翻；若撑过了屏幕也只需翻一次即可 
int main(int argc, char** argv) {
	long long l,n,cnt=1;
	long long sum=0;
	long long a[105];
	scanf("%lld%lld",&l,&n);
	for(int i=0;i<n;i++)
	{
		scanf("%lld",&a[i]);
	}
	
	for(int i=0;i<n;i++)
	{
		sum+=a[i];
		if(sum==l) { sum=0;cnt++;if(i==n-1)cnt--;
		}
		if(sum>l){
			sum=0;cnt+=2;
			if(i==n-1)cnt--;
		}
	}
	printf("%lld",cnt); 
	return 0;
}

