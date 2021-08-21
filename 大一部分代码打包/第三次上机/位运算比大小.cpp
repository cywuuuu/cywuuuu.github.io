#include <stdio.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char** argv) {
	int n,cnt=0;
	scanf("%d",&n);
	int a[6000];
	
	for(int i=0;i<n;i++)
	{
		scanf("%d",&a[i]);
	 } 
	 
	 for(int i=0;i<n;i++)
	 {
	 	for(int j=i+1;j<n;j++)
	 	{
	 		if((a[i]&a[j])>(a[i]^a[j])) cnt++; //C语言运算优先级 位运算逻辑运算靠后，加减居中、括号取地址等等特殊靠前 
		 }//无序数对理解 （a,b）(b,a)算一个，调换顺序无所谓；有序数对 （a,b）(b,a)调换顺序算两个  考虑顺序不同带来的区别 
	 }
	 printf("%d",cnt);
	return 0;
}
