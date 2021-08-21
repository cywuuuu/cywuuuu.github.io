#include <stdio.h>
#include <string.h>
/* run this program using the console pauser or add your own getch, system("pause") or input loop */
//两个用制表符分开的。。vs用两个制表符 ——审题的细致 
int main(int argc, char** argv) {
	char a[100];
	gets(a);
	if(strcmp(a,"I_Love_BUAA")==0) printf("10\t25");
	else if(strcmp(a,"1952_2020")==0) printf("68 1025");
	else if(strcmp(a,"SHIE_COLLEGE")==0) printf("37\n\r73");
	else if(strcmp(a,"buaa-2020-fall-programming")==0) printf("2020\t10");
	else if(strcmp(a,"Beihang-University")==0) printf("1952 2020");
	else printf("2333\n\r6666");
	return 0;
}
