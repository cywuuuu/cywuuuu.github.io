#include <stdio.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */
int book[20]={0};
int pt[20]={0};
void dfs(int n,int k)
{
	if(k==n)
	{
		for(int i=1;i<=n;i++)
		{
			printf("%5d",pt[i]);
		}
		printf("\n");
		return;
	}
	
	for(int i=1;i<=n;i++)
	{
		if(book[i]==0)
		{
			book[i]=1;
			pt[k+1]=i;
			dfs(n,k+1);
			book[i]=0;//用完回溯时请 撤回bk 使得后续进入函数时可以再利用（当然这次 i 已经用过了，进入下个循环了） 
//这里要不要return 0 呢？ return 0加在最后面 
//因为 如果过早的return （在循环体内 就会提早结束循环 那么 就不能换各种情况了 这才是问题所在！！ 
			
		}
	}
 } 
//模型dfs(）中的通常为位置信息（将信息而该信息需要用bk标记+循环 填入位置中）) 

int main(int argc, char** argv) {
	int n;
	scanf("%d",&n);
	dfs(n,0);
	return 0;
}
