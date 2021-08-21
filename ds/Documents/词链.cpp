#include <stdio.h>
#include <string.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int s[2008][200];
int cnt[2008];//用来记录所对应的前面子串链的个数 

int main(int argc, char** argv) {
	int n;
	scanf("%d", &n);
	for(int i = 0; i < n ; i++)
	{
		scanf("%s",&s[i]);
		for(int j = i - 1; j >= 1; j-- )
		{
			if(strstr(s[i],s[j])==s[i])
			{
				cnt[i] = cnt[j] + 1;
				break;
			}
		}
	}
	int max = -1;
	for(int i = 0; i < n; i++)
	{
		if(max < cnt[i]) max = cnt[i];
	}
	printf("%d",max);
	return 0;
}
