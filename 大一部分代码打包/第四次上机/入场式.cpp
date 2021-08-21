#include <stdio.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */
	int a[100080]={0};
	int b[100080]={0}; //十的五次方后面有5个零，六位数 
int main(int argc, char** argv) {

	int n;	
	int flag=1;
	scanf("%d",&n);
	for(int i=0;i<n;i++)
	{
		scanf("%d",&a[i]);
	}
		for(int i=0;i<n;i++)
	{
		scanf("%d",&b[i]);
	}

	for(int i=1;i<n;i++)
	{
		if(a[i-1]>=a[i]||b[i-1]>=b[i])//要严格增则不能等 
		{
		
		if (a[i]<=b[i-1]||b[i]<=a[i-1]){flag=0;printf("no");break;} //人肉检查，reg范围，反面排除取并用或 
		else {
			int tmp=a[i];
			a[i]=b[i];
			b[i]=tmp;
		}
		}
	}

	if(flag==1) printf("yes");
	return 0;

}
