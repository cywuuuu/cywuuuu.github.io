#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <stdlib.h>
//����hash 
//FILE* fp = freopen("P3370_2.in","r",stdin);
int cmp (const void * a, const void * b)
{
   return ( *(int*)a - *(int*)b );
}
typedef unsigned long long ull;
ull mod = 1<<30;
ull base = 999979, prime = 1e9+7;
//����һ������(���������)��Ϊģ���������õ���1<<30
//����һ��base���ƣ�������233
/*
2. hash[i]=(hash[i-1]*p+idx(s[i]))%mod
pȡһ��6��8λ��������modȡһ����������һ��ȡ1e9+7��1e9+9
��ȫָ�������� �������ԣ�*/
/* run this program using the console pauser or add your own getch, system("pause") or input loop */
ull hash[300000]={0}; 
char s[200000];
int main(int argc, char** argv) {
	ull hashnum=0;
	int n=0;
	scanf("%d",&n); 
	int cnt=0,much=0;
	while(scanf("%s",s)!=EOF)
	{
		hashnum = 0;
		int len = strlen(s);
		for(int i = 0 ;i < len ;i++)
		{
			hashnum = (hashnum*base + (ull)s[i])%mod+prime;
		}
		hash[cnt] = hashnum;
		cnt++;
	}
	qsort(hash,cnt,sizeof(ull),cmp);
	for(int i=0;i<cnt-1;i++)
	{
		if(hash[i]!=hash[i+1])much++;
	}
	printf("%d",much+1);
//	fclose(fp);
	return 0;
}
/*
����˫hash(100)

#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
typedef unsigned long long ull;
ull base=131;
struct data
{
    ull x,y;
}a[10010];
char s[10010];
int n,ans=1;
ull mod1=19260817;
ull mod2=19660813;
ull hash1(char s[])
{
    int len=strlen(s);
    ull ans=0;
    for (int i=0;i<len;i++)
        ans=(ans*base+(ull)s[i])%mod1;
    return ans;
}
ull hash2(char s[])
{
    int len=strlen(s);
    ull ans=0;
    for (int i=0;i<len;i++)
        ans=(ans*base+(ull)s[i])%mod2;
    return ans;
}
bool comp(data a,data b)
{
    return a.x<b.x;
}
main()
{
    scanf("%d",&n);
    for (int i=1;i<=n;i++)
    {
        scanf("%s",s);
        a[i].x=hash1(s);
        a[i].y=hash2(s);
    }
    sort(a+1,a+n+1,comp);
    for (int i=2;i<=n;i++)
        if (a[i].x!=a[i-1].x || a[i-1].y!=a[i].y)
            ans++;
    printf("%d\n",ans);
}
*/
