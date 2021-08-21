#include<stdio.h>
int main(int argc,char *argv[])
{
    int i;
    for(i=0;i<argc;i++)
        printf("第 %d 个参数是 %s\n",i+1,argv[i]);
    return 0;
}
