#include <stdio.h>
#include <string.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */
void swap(char *a, char *b)
{
	char tmp = *a;
	*a = *b;
	*b = tmp;
}
char data[1000];int num = 0 ;
void perm(int begin, int end)//每次递归
/*
1、确定一个光标位置 begin 
2、都让首字母交换后面个字母 （保证换后结果的首字母不同 排列） 
3. 光标后移 原光标位置（不同数分类下来）不同的首字母唯一类 
每一类中 光标后移减小数据规模 继续递归 
*/ 
{
	if(begin == end)//data都给你重排好了，无需提取（因为后面回溯时是会复原的！！！！） 直接输出此时状态就好 
	{
		num++;
		for(int j = 0;j < end; j++)
		{
			printf("%c",data[j]);
			
		 } printf(" ( %d )\n",num);
		return ;
	}
	else 
	{
		for(int i = begin; i < end ; i++)
		{
			swap(&data[begin],&data[i]);
			perm(begin+1,end);
			swap(&data[begin],&data[i]); // KEYYY!!!!!! 
		}
	}
}
int main(int argc, char** argv) {
	int i = 0;
	gets(data);
	int end = strlen(data);
	perm(0,end); 
	return 0;
}

//如果要从 这些里面取三个数的全排列，那么令 end = 3 即可（取全排列的前三个输出） 
