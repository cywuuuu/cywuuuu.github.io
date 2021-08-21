#include <stdio.h>
#include <string.h>
#include <ctype.h>
/* run this program using the console pauser or add your own getch, system("pause") or input loop */

char line[30000];
char line2[30000];
void move(int wh, int l, int len)
{
	int i;
	if(l > 0)
	{
		for(i = len + l; i >= wh; i--)
		{
			line[i] = line[i-l];
		}
	}
	else if( l < 0)
	{
		for(i = wh; i <= len + l; i++)
		{
			line[i] = line[i-l];
		}
	}
	
}
void move2(int wh, int l, int len)
{
	int i;
	if(l > 0)
	{
		for(i = len + l; i >= wh; i--)
		{
			line2[i] = line2[i-l];
		}
	}
	else if( l < 0)
	{
		for(i = wh; i <= len + l; i++)
		{
			line2[i] = line2[i-l];
		}
	}
	
}
int main(int argc, char** argv) {
	char fr[100];
	char to[100];
	gets(fr);
	gets(to);
	int lenf = strlen(fr);
	int lent = strlen(to);
	
	FILE *in,*out;
	if(((in = fopen("filein.txt","r"))==NULL))
	{
		printf("ERR");
	return 0;
	}
	if((out = fopen("fileout.txt","w"))==NULL)
	{
		printf("ERR");
		return 0;
	}

	while(fgets(line,20000,in)!=NULL)
	{
		
		int len = strlen(line);
		int len2 = strlen(line2);
		for(int i = 0; i < len; i++)
		{
			line2[i] = tolower(line[i]);
		}
		char *p = line;int wh;
		char *p2 = line2;int wh2;
		while(p2!=NULL)
		{		
			if((p2=strstr(p2, fr))!=NULL)
			{
				wh2 = p2 - line2;
				len = strlen(line);
				len2 = strlen(line2);
				move(wh2,lent - lenf, len);
				move2(wh2,lent - lenf, len2);
				int i;
				for(i = 0; i < lent; i++)
				{
					line[wh2+i] = to[i];
				}
					for(i = 0; i < lent; i++)
				{
					line2[wh2+i] = to[i];
				}
			}
			
		}
		fputs(line,out);memset(line,'\0',20000);memset(line2,'\0',20000);
	}
	fclose(in);
	fclose(out);
	return 0;
}
