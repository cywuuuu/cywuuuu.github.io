#include <iostream>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */
squeez(char s[],char c)
{
int i,j;
j=0;//j是前指针 i是全遍历指针 
for(i=0;s[i]!="\0";i++)
{
if(s[i]!=c){
s[j]=s[i];
j++;
};
}
s[j]='\0';
}
int main(int argc, char** argv) {
	return 0;
}
