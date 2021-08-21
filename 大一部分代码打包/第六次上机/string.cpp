#include <stdio.h>
#include <string.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char** argv) {
	int t;
	char s[10];
	scanf("%d",&t);
	while(t--)
	{
		//gets(s);gets可以接收空格;而scanf遇到空格、回车和Tab键都会认为输入结束
		scanf("%s",s);
		if(strcmp(s,"len")==0)
		{
			char a[200];
			scanf("%s",a);
			printf("%llu\n",strlen(a));
		}
		else if(strcmp(s,"cmp")==0)
		{
			char a[200],b[200];
			scanf("%s%s",&a,&b);
			if(strcmp(a,b)==0) printf("=\n");
			if(strcmp(a,b)<0) printf("<\n");
			if(strcmp(a,b)>0) printf(">\n");//strcmp 比较的是字典序 
//逐字符比较过程中，一旦发现某一对被比较的字符之间不相等时，这一对字符的大小关系即为这一对字符串的大小关系;
//eg. "abc" < "abd"
//逐字符比较过程中，一旦出现某一个字符串的所有字符都已经经过比较，而另一字符串还存在未被比较的字符时，较短的字符串更小。
//eg. "abc" < "abcde" 
		}
		else if(strcmp(s,"cat")==0)
		{
			char a[500],b[200];
			int n=0;
			scanf("%s%s",a,b);
			scanf("%d",&n);
			strncat(a,b,n);
			puts(a);
		}
	}
	return 0;
}
