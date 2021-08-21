#include <stdio.h>
/*题目中给出了当前汉诺塔上每个圆盘的位置，要求移动到第三根柱子上，我们来考虑这样一个函数
move(a, from, to) 表示将 从起点 移动到终点 ，我们为了移动 ，则需要将所有比 小的
圆盘移动到除了 之外的第三根柱子上，然后才能移动 。所以将 从 移动到 可以分为
这两步：
1. 将所有比 小的圆盘移动到不是 也不是 的柱子上；
2. 移动 。
在移动的过程中， 的起点可能会发生变化，我们用一个数组 来记录。*/ 
int start[100]; // 记录每个圆盘所在的位置
int cnt; // 记录移动的步数
// move函数的作用是将a从起点from移动到终点to
void move(int a, int from, int to)
{
int i;
if (from == to)
return; // 如果起点和终点重合，则不用移动
for (i = a - 1; i > 0; i--) // 将比a小的所有圆盘移动到不是起点也不是终点的柱子上
move(i, start[i], 6 - from - to);
// 移动a
printf("%d:%d-->%d\n", a, from, to);
start[a] = to;
cnt++;
}
int main()
{
int n, i;
scanf("%d", &n);
for (i = 1; i <= n; i++)
scanf("%d", &start[i]);
for (i = n; i > 0; i--) // 从大到小依次移动圆盘
move(i, start[i], 3);
printf("%d", cnt);
return 0;
}
