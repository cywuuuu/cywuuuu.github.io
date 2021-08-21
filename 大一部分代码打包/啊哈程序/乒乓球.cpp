#include <stdio.h>
#include <string.h>
#include <math.h>
/* run this program using the console pauser or add your own getch, system("pause") or input loop */
char s[70008],in[2560];
int main(int argc, char** argv) {
	char *p=s;
	int win=0,loss=0;
	while(gets(in)!=NULL)
	{
		strcat(s,in);
	}
	while(*p!='E')
	{
		if((win<=11&&loss<=11)||abs(win-loss)<=2)
		{
			if(*p=='W') win++;
			if(*p=='L') loss++;
			if(abs(win-loss)>=2&&(win>=11||loss>=11))
			{
				printf("%d:%d\n",win,loss);
				win=0;
				loss=0;
			}
		}
		p++;
		
	}//WWWWWLLLLLLWLWLWLWLWLWLWLWLWLWWWE
	printf("%d:%d\n",win,loss);
	printf("\n");
	
	win=0,loss=0,p=s;
	while(*p!='E')
	{
		if((win<=21&&loss<=21)||abs(win-loss)<=2)
		{
			if(*p=='W') win++;
			if(*p=='L') loss++;
			if(abs(win-loss)>=2&&(win>=21||loss>=21))
			{
				printf("%d:%d\n",win,loss);
				win=0;
				loss=0;
			}
		}
		p++;
		
	}
	printf("%d:%d\n",win,loss);
	
	
	return 0;
}
