#include <stdio.h>
#include <string.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

/*char s[2008][200];
int cnt[2008];//用来记录所对应的前面子串链的个数 

int main(int argc, char** argv) {
	int n;
	scanf("%d", &n);
	for(int i = 1; i <= n ; i++)
	{
		scanf("%s",&s[i]);
	}
	for(int i = 1; i <= n ; i++)
	{
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
	for(int i = 1; i <= n; i++)
	{
		if(max < cnt[i]) max = cnt[i];
	}
	printf("%d",max+1);
	return 0;
}*/
int trie[1000010][26];
int n[1000010];
int pos = 1;
char s[2008][200];
void insert(cahr str[])
{
	int len = strlen(str);
	for(int i = 0; i < len; i++)
	{
		int p;
		int x = str[i]- 'a';
		if(trie[p][x] == 0)
		{
			trie[p][x] == pos++;
		}//pos++保证了每横行只可能有一个数、 并用trie 中的pos记录下一个字母的行位置 //find时可以跳跃 
		p = trie[p][x];//告诉我下一行在那里吧嘿嘿 
		num[p] ++; 
	}
}

int find(char str[])
{
	int len = strlen(str);
	for(int i = 0; i < len; i++)
	{
		int x = str[i] - 'a';
		if(trie[p][x] == 0)
		{
			return 0;
		}
		p = trie[p][n];
		
	}
	return num[p];
}


int main()
{
	int nn,max = -1;
	scanf("%d", &nn);
	for (int i = 0; i < nn; i++)
	{
		scanf("%s", s[i]);
	}
	for (int i = 0; i < nn; i++)
	{
		if(max < find())
	}
}
