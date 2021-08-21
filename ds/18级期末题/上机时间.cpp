#include <stdio.h>
#include <stdlib.h>
#include <string.h>
/* run this program using the console pauser or add your own getch, system("pause") or input loop */
typedef struct stu
{
	int time;
	int num;
	char ss[300];
}stu;

stu a[300];
int tot = -1;
int cmp(const void *x, const void *y)
{
	stu *a = (stu *)x;stu *b = (stu *)y;
	if(a->time == b->time) return a->num-b->num;
	else return a->time - b->time;
}
int main(int argc, char** argv) {
	int n;
	scanf("%d", &n);
	while(n--)
	{
		int time,num;char s[300];
		scanf("%s%d%d",s,&num,&time);
		int flag = 0;
		for(int i = 0; i <= tot; i++)
		{
			if(a[i].num == num) 
			{
				flag = 1; 
				a[i].time += time;
				break;
			}
		}
		if(flag == 0) 
		{
			tot++;
			a[tot].num = num;
			strcpy(a[tot].ss, s);
			a[tot].time = time; 
		} 
	}
	qsort(a,tot+1,sizeof(a[0]),cmp);
	for(int i = 0; i <= tot; i++)
	{
		printf("%s %d %d\n", a[i].ss, a[i].num, a[i].time);
	}
	return 0;
}
/*
10
wanghai 19373001 3600
liupeng 19374521 1796
zhanghuimei 19182538 2421
lipengyou 19230908 7329
qinhong 19060211 650
zhaopin 17182785 1076
sunliang 15375026 2028
zhanghuimei 19182538 2537
jikehong 16373890 4263
wanghai 19373001 58

20
wanghai 19373001 3600
liupeng 19374521 1796
zhanghuimei 19182538 2421
lipengyou 19230908 7329
qinhong 19060211 650
zhaopin 17182785 1076
sunliang 15375026 2028
zhanghuimei 19182538 2537
jikehong 16373890 4263
wanghai 19373001 58
qinhong 19060211 123
zhanghuimei 19182538 3311
liuxu 19373289 1239
hongfei 19372976 900
sunliang 15375026 1000
liupeng 19374521 1862
zhanghuimei 19182538 32
sunliang 15375026 630
wanghai 19375091 9023
zhanghuimei 19182538 1096

*/ 
