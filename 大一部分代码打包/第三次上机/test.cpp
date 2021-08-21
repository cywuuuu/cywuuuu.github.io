#include <stdio.h>
int main() 
{
int c, n=0;
while( (c = getchar()) != EOF ) 
if(c == '\n') n++; 
printf("You input %d lines. \n", n);
return 0;
}
