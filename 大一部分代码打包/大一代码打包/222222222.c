#include <stdio.h>
#include <stdlib.h> 
#define N 10010
int a[N][3] = {0}, b[N][3] = {0}; // ��һ��a[i][0]:λ�� ; �ڶ���a[i][1]:����˳�� ; ������a[i][2]:����
const char ansstr[][10] = {"N", "S", "Turning"}; // ���ַ��������򻯴���
int rank(const void **a, const void **b)
{
return (*((int *)a) - *((int *)b)); // ���ն�ά����ĵ�һ�е���ֵ��С��������ÿ��
}
int id(const void **a, const void **b)
{
return (*((int *)a + 1) - *((int *)b + 1)); // ���ն�ά����ĵڶ��е���ֵ��С��������ÿ��
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
qsort(a, n, sizeof(a[0]), rank); // �� a ����ÿ�а��ճ�ʼλ�ôӱ���������
qsort(b, n, sizeof(b[0]), rank); // �� b ����ÿ�а�������λ�ôӱ���������
for (i = 0; i < n; i++)
{
b[i][1] = a[i][1];
if (i < n - 1 && b[i][0] == b[i + 1][0])
{
b[i][2] = 2;
b[i + 1][2] = 2;
} // T ��֮��ǡ��������ͬѧ������Ҫ��������
}
qsort(b, n, sizeof(b[0]), id); // �� b ����ÿ�а�������˳����ȵ�������
for (i = 0; i < n; i++)
if (b[i][0] < 0 || b[i][0] > l)
printf("Finished\n"); // �߳� TD ��
else
printf("%d %s\n", b[i][0], ansstr[b[i][2]]); // ���� TD ���ϵģ����λ�úͳ���
return 0;
}
