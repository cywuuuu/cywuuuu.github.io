#include <stdio.h>
#include <string.h>
/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char** argv) {
	char s[3000],l[3000],m[3000],n[3000],r[3000];
	int a,b,c,f1=0,f2=0,f3=0,i=0;
	gets(s); 
	while(1)
	{
		f1=0,f2=0,f3=0;
		for(i=strlen(s)-1;i>=0;i--)
		{
			if(s[i]=='g') {c=i;
			
			f1=1;
			break;} 
		}
		for(i=c;i>=0;i--)
		{
			if(s[i]=='u'){
				b=i;f2=1;break;
				
			}
		}
		for(i=b;i>=0;i--)
		{
			if(s[i]=='b')
			{
				a=i;f3=1;break;
			}
		}
		if(f1*f2*f3==0) break;
		s[a]='\0';
		s[b]='\0';
		s[c]='\0';
			strcpy(l,s);
			strcpy(m,&s[a+1]);
			strcpy(n,&s[b+1]);
			if(c+1<=strlen(s)-1)
			strcpy(r,&s[c+1]);
		
		strcat(s,m);
		strcat(s,n);
		strcat(s,r);
		
}puts(s);
	return 0;
}
