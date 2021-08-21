#include <stdio.h>
#include <string.h>
#define MAX 290
char s1[MAX],s2[MAX];
int num1[MAX],num2[MAX];
int ans[MAX]; 
int len1,len2; 
/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int compare(int *num1, int *num2)
{
	int i = 0;
	while(num1[i] == num2[i] && i < MAX ) i++;
	if(i==MAX) return 1;
	if (num1[i] >= num2[i]) return 1;//1大或等 
	else return 0; 
}

void reverse(int* a)
{
	
	
		int i = 0, j = MAX-1;
		while(i <= j)
		{
			int tmp = a[i];
			a[i] = a[j];
			a[j] = tmp;
			i++;
			j--;
		}
	

}

int minus(int *num1, int *num2, int len1, int type)
{
	int carry = 0,tmp;
	for(int i = 0; i < MAX; i++)
	{
		 tmp = num1[i] - num2[i] + carry;
		if(tmp < 0) 
		{
			ans[i] = tmp + 10;
			carry = -1;
		}
		else
		{
			ans[i] = tmp;
			carry = 0;
		}
	}
	while(ans[len1-1] == 0 && len1 > 1 ) len1--;
	if(type == 0) printf("-");
	for(int i = len1-1; i >= 0; i--)
	{
		printf("%d",ans[i]);
	}
}


int main(int argc, char** argv) {
	scanf("%s%s",s1,s2);
	int type;
	len1 = strlen(s1);
	len2 = strlen(s2);
	for(int i = 1; i <= len1; i++)
	{
		num1[MAX-i] = s1[len1 - i]-'0';
	}
	for(int i = 1; i <= len2; i++)
	{
		num2[MAX-i] = s2[len2 - i]-'0';
	}
	
	if(len2 > len1) type = 0;//为负数 
	if(len2 < len1) type = 1;//为正数 
	if(len2 == len1) 
	{
		if(compare(num1,num2)==1) type = 1; //正 
		else type = 0; 
	}
	reverse(num1); reverse(num2);
	if(type == 1) minus(num1, num2, len1,type);
	else minus(num2, num1, len2,type);
	
	
	return 0;
}
