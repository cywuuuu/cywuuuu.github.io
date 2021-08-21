#include <stdio.h>
#include <string.h>
int index(char s[],char t[])
{
 int i,j,k;
 for(i=0;s[i]!='\0';i++)
 {
  for(j=i,k=0;t[k]!='\0'&&s[j]==t[k];j++,k++)
   ;
  if(t[k]=='\0')
   return i;
 }
 return -1;
}

main()  
{
           char s[100],t[100];
           scanf("%s%s",&s,&t);
           printf("%d",index(s,t));
} 
