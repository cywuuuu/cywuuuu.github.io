#include <stdio.h>
#define N 100005

int main()
{
   int shang[N], where[N], x, y, i, j;
   const char a[8] = "integer";
   const char b[20] = "terminating decimal";
   const char c[20] = "recurring decimal";

   scanf("%d%d", &x, &y);
   if (x % y == 0)
   {
    printf("%s\n", a);
    printf("%d", x / y);
   }
   else
   {
    shang[0] = x / y;
    x %= y;
    for (i = 1; (!where[x]) && x; i++)//����߼� �³��ֵ�xҪ�Ƚ����ǲ���֮ǰ���ֹ��ˣ����ֹ���һ���ˣ�����where��x�������ҵ�֮ǰ�Ƿ����x�������ͬʱ&&����ʹ���������� 
    {
     where[x] = i;
     shang[i] = 10 * x / y;
     x = 10 * x % y;
    }
    if (!x)
    {
     printf("%s\n%d.", b, shang[0]);
     for (j = 1; j < i; j++)
      printf("%d", shang[j]);
    }
    else
    {
     printf("%s\n%d.", c, shang[0]);
     for (j = 1; j < where[x]; j++)
      printf("%d", shang[j]);
     printf("_");
     for (; j < i; j++)
      printf("%d", shang[j]);
     printf(" [%d]", i - where[x]);
    }
   }

   return 0;
}
