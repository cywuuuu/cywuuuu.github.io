#include<stdio.h>
int main()
{
	int t=0,seq=0,same=0,n;
	long long a[100000],b[100000];
  	int count=0;
	scanf("%d",&t);
	int result[20];
	for(int j=1;j<=t;j++)
	{	count=0;
		scanf("%d",&n);
		for(int i=0;i<=n-1;i++)
		{
			scanf("%lld",&b[i]);
		}
		
		for(int i=0;i<=n-1;i++)
		{
			scanf("%lld",&a[i]);
		}
		//赋值 
		
		
		while(true) //不断循环至same=1 break，记录count； 
		{
			same=1;
			for(int i=0;i<=n-1;i++)
			{
				if(a[i]!=b[i])
				{
					same=0;
					break;
				}
			}//not same get in loop
			
			if(same==1)
			{
			break;
			}//same break 
					 
			if(a[1]>a[0])
			{
				seq=1;//go up
				for(int i=1;i<n;i++)
				{					
					if(a[i]<a[i-1])
						{
							seq=0;//乱序 
							break;
						}
				}
			}
		
			if(a[0]>a[1])
			{
				seq=-1;//go down 
				for(int i=1;i<n;i++)
				{
					if(a[i-1]<a[i])
					{
						seq=0;
						break;
					}
				}
			}
			//判断数组中的数递增/递减 
			if(seq==0)
			{
				for(int i=0;i<=n/2-1;i++)
				{
				long long c=a[i];
					a[i]=a[n-1-i];
					a[n-1-i]=c;
				}
				count++;
				
				same=1;
				for(int i=0;i<=n-1;i++)
				{//判断a b数组一致性 
					if(a[i]!=b[i])
					{
						same=0;
						break;
					}
				}
				break;
			}
			
			else if(seq==1)
			{
				for(int i=n-1;i>=1;i--)
				{
					a[i]=a[i]-a[i-1]; 	
				}
				count++;		
			}
			
			else if(seq==-1)
			{
				for(int i=0;i<=n/2-1;i++)
				{
				long long	c=a[i];
					a[i]=a[n-1-i];
					a[n-1-i]=c;
				}
				count++;
			}
		}	
		
		if(same==1)
		{
			result[j-1]=count;
		}
		else if(same==0)
		{
			result[j-1]=-1;
		}
		
	}
	
	for(int j=0;j<=t-1;j++)
	{
		printf("%d\n",result[j]);
	}
	return 0;
	
}
