#include <stdio.h>
#include <string.h>
#include <stdlib.h>
typedef struct table
{
	int mile;
	char dest[100];
}table;
typedef struct node
{
	int mile;
	char dest[100];
	char num[20];
}node;
table tab[100];
/* run this program using the console pauser or add your own getch, system("pause") or input loop */

typedef struct stk
{
	node data[500];
	int top;
}stk;

stk a, b, c;

void pusha(node t)
{
	a.top++;
	a.data[a.top] = t;
}
void pushb(node t)
{
	b.top++;
	b.data[b.top] = t;
}
void pushc(node t)
{
	c.top++;
	c.data[b.top] = t;
}
node popa()
{
	a.top--;
	return a.data[a.top+1];
}
node popb()
{
	b.top--;
	return b.data[b.top+1];
}
node popc()
{
	c.top--;
	return c.data[c.top+1];
}
int oknum = -1;
int cnt = 0;
int main(int argc, char** argv) {
	int n;
	scanf("%d", &n);
	a.top = b.top = c.top = -1;
	for(int i = 0; i < n; i++)
	{
		scanf("%s%d", tab[i].dest, &tab[i].mile);
	}
	int m;
	scanf("%d", &m);
	node t;
	
	for(int i = 0; i < m; i++)
	{
		scanf("%s%s",t.num, t.dest);
		for(int j = 0; j < n; j++)
		{
			if(strcmp(tab[j].dest, t.dest) == 0) 
			{
				t.mile = tab[j].mile;break;
			}
		}
		pusha(t);
	}
	//
	while(a.top > -1)
	{
		t = popa();
		pushb(t);
	}
	while(b.top > -1)
	{
		int max = -1;
		for(int i = 0; i <= b.top; i ++)
		{
			if(max < b.data[i].mile) max = b.data[i].mile;
			
		}
		while(b.data[b.top].mile != max)
		{
			t = popb();
			pusha(t);cnt++;
		}
		t = popb();
		pusha(t);cnt++;
		//
		int flag = 0;
		
		for(int i = a.top-1; i >= 0; i--)
		{
			if(a.data[a.top].mile > a.data[i].mile)
			{
				flag = 1;
				oknum = i;
			}
		}
		if (flag == 1) 
		{
			t = popa();
			pushc(t);
			while(a.top >= oknum)
			{
				t = popa();
				pushb(t);
			}
			t = popc();
			pusha(t);cnt++;
		}
	}
	
	for(int i = 0; i <= a.top; i++)
		printf("%s ", a.data[i].num);
	printf("\n%d",cnt);
	
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
