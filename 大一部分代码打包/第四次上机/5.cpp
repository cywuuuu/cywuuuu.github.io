#include <stdio.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char** argv) {
	 int t,n;
	 scanf("%d",&t);
	 while(scanf("%d",&n)!=EOF)
	 {
	 	int a[108]={0};
	 	for(int i=0;i<n;i++)
	 	{
	 		scanf("%d",&a[i]);
		 }
		 int flag=0,cnt=0,len=0,pt=0;
		 for(int i=0;i<n;i++)
		 {
		 	if(flag==0&&a[i]==1) 
		 	{
		 		flag=1;
		 		cnt++;
			 }
			 else if(flag==1&&a[i]==1)
			 {
			 	cnt++;
			 }
			 else if(flag==1&&a[i]==0)
			 {
			 	flag=0;
			 	if(len<cnt)
			 	{
			 		len=cnt;pt=i-len+1;
			 		cnt=0;
				 }
			 }
			 
			 
		 }
		 if(flag==1)
		 {
		 		if(len<cnt)
			 	{
			 		len=cnt;
					pt=n-len+1;
			 		cnt=0;
				 }
		 }
		 printf("%d %d\n",len,pt);
	 	
	 }
	return 0;
}
