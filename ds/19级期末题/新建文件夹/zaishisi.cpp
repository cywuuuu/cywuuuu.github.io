#include <stdio.h>
#include <string.h>
#include <stdio.h>
/* run this program using the console pauser or add your own getch, system("pause") or input loop */

typedef struct node
{
	int dis;
	char num[20];
	char dest[100];
}node;
node table[1000];
typedef struct stk
{
	node cargo[10000];
	int top;
}stk;
stk a,b,c;

void pusha(node x)
{
	++a.top;
	a.cargo[a.top] = x;
}
void pushb(node x)
{
	++b.top;
	b.cargo[b.top] = x;
}
void pushc(node x)
{
	++c.top;
	c.cargo[c.top] = x;
}
node popa()
{
	a.top--;
	return a.cargo[a.top+1];
}
node popb()
{
	b.top--;
	return b.cargo[b.top+1];
}
node popc()
{
	c.top--;
	return c.cargo[c.top+1];
}
int isemptya()
{
	if(a.top == -1)
	return 1;
	else return 0;
}
int isemptyb()
{
	if(b.top == -1)
	return 1;
	else return 0;
}
int isemptyc()
{
	if(c.top == -1)
	return 1;
	else return 0;
}
int isainorder(int x)
{
	for(int i = 0; i < x; i++)
	{
		if(a.cargo[i].dis < a.cargo[i+1].dis)
		{
			return 0;
		}
	}
	return 1;
}
int tot = 0;
int onum = -1;
int cnt = 0;
int main(int argc, char** argv) {
	a.top = b.top = c.top = -1;
	int n;
	scanf("%d", &n);
	for(int i = 0; i < n; i++)
	{
		scanf("%s%d", table[i].dest, &table[i].dis);
	 } 
	int m;
	scanf("%d", &m);node tmp;
	for(int i = 0 ; i < m; i++)
	{
		scanf("%s%s",tmp.num,tmp.dest);
		for(int j = 0; j < n; j++)
		{
			if(strcmp(tmp.dest, table[j].dest) ==0 )
			{
				tmp.dis = table[j].dis;
				break;
			}
		}
		pusha(tmp);
	}
	while(isemptya() == 0)
	{
		tmp = popa();
		pushb(tmp);
	}
	while(isemptyb() == 0)
	{
		int max = -1;int pos = -1;//b.cargo[pos]
		for(int i = 0; i <= b.top; i++)
		{
			if(max < b.cargo[i].dis)
			{
				max = b.cargo[i].dis;
			}
		}
		for(int i = b.top; i >= 0; i--)
		{
			if(max == b.cargo[i].dis)
			{
				pos = i;
				break;
			}
		}
		while(b.top >= pos)
		{
			tmp = popb();
			pusha(tmp);cnt++;
		}
		if((a.top > onum + 1))
		{
			tmp = popa();
			pushc(tmp);
			while(a.top > onum)//a.cargo[a.top]
			{
				tmp = popa();
				pushb(tmp);
			}
		tmp = popc();
		pusha(tmp);cnt++;
		onum++;
		}
		else if(a.top == onum + 1)
		{
			onum++;
		}
	}
	for(int i = 0; i <= a.top; i++)
	{
		printf("%s ",a.cargo[i].num);
	}
	printf("\n%d", cnt);
	return 0;
}
/*
10
shijiazhuang 280
xingtai 390
xinxiang 610
zhengzhou 689
wuchang 1221
chibi 1339
yueyang 1434
changsha 1559
shaoguan 2057
guangzhou 2273
12
0039 guangzhou
5217 xingtai
0262 yueyang
7205 wuchang
3211 guangzhou
4893 shijiazhuang
2283 shaoguan
0890 guangzhou
8729 wuchang
6839 shijiazhuang
2122 changsha
3280 wuchang
*/
