#include <stdio.h>
#include <stdlib.h> 
#define N 10010
int a[N][3] = {0}, b[N][3] = {0}; // 第一列a[i][0]:位置 ; 第二列a[i][1]:输入顺序 ; 第三列a[i][2]:朝向
const char ansstr[][10] = {"N", "S", "Turning"}; // 用字符串常量简化代码
int rank(const void **a, const void **b)
{
return (*((int *)a) - *((int *)b)); // 按照二维数组的第一列的数值从小到大排序每行
}
int id(const void **a, const void **b)
{
return (*((int *)a + 1) - *((int *)b + 1)); // 按照二维数组的第二列的数值从小到大排序每行
}
int main()
{
int l, n, t, i;
char p;
scanf("%d%d%d", &l, &n, &t);
for (i = 0; i < n; i++)
{
a[i][1] = i + 1;
scanf("%d %c", &a[i][0], &p);
if (p == 'S')
{
b[i][0] = a[i][0] + t;
b[i][2] = 1;
}
else if (p == 'N')
{
b[i][0] = a[i][0] - t;
b[i][2] = 0;
}
}
qsort(a, n, sizeof(a[0]), rank); // 把 a 数组每行按照初始位置从北至南排序
qsort(b, n, sizeof(b[0]), rank); // 把 b 数组每行按照最终位置从北至南排序
for (i = 0; i < n; i++)
{
b[i][1] = a[i][1];
if (i < n - 1 && b[i][0] == b[i + 1][0])
{
b[i][2] = 2;
b[i + 1][2] = 2;
} // T 秒之后恰好相遇的同学方向需要单独处理
}
qsort(b, n, sizeof(b[0]), id); // 把 b 数组每行按照输入顺序从先到后排序
for (i = 0; i < n; i++)
if (b[i][0] < 0 || b[i][0] > l)
printf("Finished\n"); // 走出 TD 线
else
printf("%d %s\n", b[i][0], ansstr[b[i][2]]); // 还在 TD 线上的，输出位置和朝向
return 0;
}
