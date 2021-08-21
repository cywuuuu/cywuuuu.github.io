#include <stdio.h>

char str[999999999];
int main(){
long long i,sum;
scanf("%s",str);
for (i=0,sum=0;str[i]!='\0';i++)
sum+=str[i]-'0';
printf("%d",(sum - 1) % 9 + 1);
return 0;
}
