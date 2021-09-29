/* 
 Author: ¿Ó≤”
 Result: WA	Submission_id: 3602499
 Created at: Mon Sep 20 2021 01:05:11 GMT+0000 (Coordinated Universal Time)
 Problem_id: 4555	Time: 7	Memory: 1732
*/

#include <stdio.h>

int main()
{
//	int a[1000]={0};
//	int b[1000]={0};
//	int i=0;
//	
//	while(a[i-1]!=-1)
//	{
//		scanf("%d%d",&a[i],&b[i]);
//		i++;
//	}
//	for(int j=0;j<i-1;j++){
//		printf("%d\n",a[j]%b[j]);
//		
//	}
	int a,b;
	while(scanf("%d%d", &a, &b) != EOF)
	{
		if(a == -1) break;
		printf("%d", a%b);
	}
	return 0;
}
