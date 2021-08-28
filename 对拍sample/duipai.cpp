#include <cstdio>
#include <string.h>
#include <cstdlib>
#include <ctype.h>
int main()
{
	/*
	我们今天来看看在windows操作系统下system () 函数详解（主要是在C语言中的应用）
注意：在windows下的system函数中命令可以不区别大小写！
函数名： system
功 能： 发出一个DOS命令
用 法： int system(char *command);
*/
	while(1)
	{
		system("data.exe > in.in");
		system("sample.exe < in.txt > sample.out");
		system("mine.exe < in.txt > mine.out");
		if("fc sample.out mine.out") return 1;
	}




return 0;
}

