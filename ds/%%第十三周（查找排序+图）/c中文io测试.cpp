#include"stdio.h"
int main()
{
char b[3]="你";//一个汉字占2个字节，这里第三个(b[2])是为了存放结束符('\0')的
char c[11]="";
scanf("%s",c);//这里5个汉字，共10个字节，还有一个放了结束符
printf("%c%c\n",b[0],b[1]);//输出汉字把两个字符一起输出
int i;
for(i=0;i<=10;i++)//这样也是
printf("%c",c[i]);
}
