#include <stdio.h>//一定stdio 

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char** argv) {
	char c;
	int k,p=0;
	scanf("%d",&k);
	while(scanf("%c",&c)!=EOF)//scanf 返回值 个数 eof，判断输入内容请用c==。。，不定数请用eof， 
	{		
		if(c=='\n'&&p==0){p=1;continue;}// 错误案例： {continue;p=1；} 原因 continue 太早 p没付上值 
		if('a'<=c&&c<='z') 
		{
			if((c-'a'-k)<0) printf("%c", (c-'a'-k)%26+26+'a');
			if((c-'a'-k)>=0) printf("%c",(c-'a'-k)%26+'a');
		}
		else printf("%c",c);
	}
	
	return 0;
}
