#include <stdio.h>
#include <string.h>
#include <ctype.h>
/* run this program using the console pauser or add your own getch, system("pause") or input loop */
char ans[1000], s1[1000],s2[1000] ;
int bk[27] = {0};
void quchong()
{
	
	int len = strlen(s1);
	int i,cnt=0;
	for(i = 0; i < len; i++)
	{
		if(bk[s1[i]-'a'] == 0)
		{
			s2[cnt++] = s1[i];
			bk[s1[i]-'a'] = 1;
		}
	}
}
void jiaru ()
{
	int i = strlen(s2);
	int j;
	for( j = 25 ; j >= 0; j--)
	{
		if(bk[j] == 0)
		{
			s2[i++] = j + 'a';
		}
	}
}

int main(int argc, char** argv) {

	scanf("%s", s1);
	quchong();
	jiaru();
	FILE *in = fopen("encrypt.txt","r");
	FILE *out = fopen("output.txt","w");
	while(fgets(ans,900,in)!=NULL)
	{
		int len = strlen(ans);int i;
		for(i = 0; i < len; i++)
		{
			if(isalpha(ans[i]))
			ans[i] = s2[ans[i]-'a'];
		}
		fputs(ans, out);
	}
	fclose(in);
	fclose(out);
	return 0;
}
