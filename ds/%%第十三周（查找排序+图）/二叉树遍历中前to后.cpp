#include <stdio.h>
#include <string.h>
/* run this program using the console pauser or add your own getch, system("pause") or input loop */
char qian[50];
char zhong[50];
char hou[50];
void bianli(int l1, int r1, int l2, int r2)
{
	if(l1 > r1 || l2 > r2) //必须严格大于！！ 
	{
		return;
	}
	int p = 0;
	for(int i = l1; i <= r1; i++)
	{
		if(qian[l2] == zhong[i])
		{
			p = i;	
		
		}
	}
	bianli( l1, p-1, l2 + 1, l2 + p - l1);
			bianli( p+1, r1, l2 + p+1-l1, r2);
			printf("%c", zhong[p]); 
	
}
int main(int argc, char** argv) {
	scanf("%s%s", zhong,qian);
	int len = strlen(qian);
	bianli(0,len-1,0,len-1);
	return 0;
}
