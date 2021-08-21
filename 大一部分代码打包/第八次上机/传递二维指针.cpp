#include <stdio.h>
#include <stdlib.h>
/* run this program using the console pauser or add your own getch, system("pause") or input loop */
int a[200008][4];
int srank(const void *p1,const void *p2)
{
	if(p1[0]>p2[0])return 1;//p是行指针 二位数组(a[3][4])头地址a是行指针数组（长度4）a[3]的头地址// p1是行指针数组
	//其中的一个元素 是一个行指针，要具体比较 再用行指针【】的取行中的元素； 
	if(p1[0]<p2[0]) return -1;
	if(p1[0]==p2[0]) return 0;
}
int sorder(const void *p1,const void *p2)
{
	if(p1[1]>p2[1])return 1;
	if(p1[1]<p2[1]) return -1;
	if(p1[1]==p2[1]) return 0;
}
void genrank(int a[][3],int n)
{
	int i;
	a[0][2]=1;
	for(int i=1;i<n;i++)
	{
		if(a[i][0]==a[i-1][0])
		a[i][2]=a[i-1][2];
		else a[i][2]=a[i-1][2]+1;
	}
}
int main(int argc, char** argv) {
	int n;
	scanf("%d",&n);
	for(int i=0;i<n;i++)
	{
		scanf("%d",a[i][0]);
		a[i][1]=i;
	}
	qsort(a,n,sizeof(a[0]),srank);
	genrank(a,n);
	qsort(a,n,sizeof(a[0]),sorder);
	for(int i=0;i<n;i++)
	{
		printf("%d: [%d]\n",a[i][0],a[i][2]);
	}
	return 0;
}
