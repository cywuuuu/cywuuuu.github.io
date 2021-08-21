#include <stdio.h> 
void reverse(char s[])
{
 int temp,i,j;
 for(i=0,j=strlen(s)-1;i<j;i++,j--)
 {
  temp=s[i];
  s[i]=s[j];
  s[j]=temp;
 }
}

void itoh(unsigned n,char s[])
{
 int h,i=0;
 do{
  h=n%16;
  s[i++]=(h<=9)?h+'0':h+'A'-10;
 }while((n/=16)!=0);
 reverse(s);
}
int main()
{
	char s[100];
	unsigned int n;
	scanf("%ud%s",n,s);
	itoh(n,s);
	puts(s);
}
