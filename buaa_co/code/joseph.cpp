 #include "stdio.h"
 
 /* 
  已知n个人（以编号1，2，3...n分别表示）围坐在一张圆桌周围。从编号为1的人开始报数，
 数到m的那个人出列；他的下一个人又从1开始报数，数到m的那个人又出列；依此规律重复下去，
 直到圆桌周围的人全部出列。   
 */
 int main(){
 	int n,m,flag=0;
 	printf("please input n and m:");
 	scanf("%d%d",&n,&m);
 	int i,count=0,len,arr[n+1]={0};
 	for(i=1;i<=n;i++){
 		arr[i]=i;
	 }
	len=1; 
	while(flag!=n)//判断是否人数为n，因为一共n个人 
	{
		if(len==n+1){
			len=1;//如果超过人数，就将其下标置为1，从头遍历 
		}
		if(arr[len]!=0){//如果数组不为0，就计数，已经输出的人将其值赋值为了0 
			count++;				
		}
		if(count==m)//如果计数值为m，就输出该点的值，并将其赋值为0 
		{
			count=0;
			printf("%d\n",arr[len]);
			arr[len]=0;
			flag++;//用来记录已经输出了的人的个数	
		}
			
		len++;//循环一次，len++	
	}
	return 0;
 }

