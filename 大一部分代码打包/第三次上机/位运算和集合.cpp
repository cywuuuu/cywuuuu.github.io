#include <stdio.h>
#include <math.h>
/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char** argv) {
//看清、慢慢读题 理解多组数据 指的是多个两行
 
char x[108]={0},y[108]={0};
	while(scanf("%s\n%s",&x,&y)!=EOF)
	{
		
	int a[26]={0},b[26]={0};

	int m=0,n=0;
	int k=0,g=0,l=0;
		for(int i=0;i<108;i++)
		{
			if(x[i]-'a'>=0)a[x[i]-'a']=1;
			if(x[i]-'a'>=0)b[y[i]-'a']=1;
		}
		
	
	
	
	for(int i=0;i<26;i++)
	{
		m+=a[i]*pow(2,i);
		if(a[i]==1)
		{
			printf("%c",'a'+i);
		}
		
	}printf("\n");
	for(int j=0;j<26;j++)
	{
		n+=b[j]*pow(2,j);
		if(b[j]==1)
		{
			printf("%c",'a'+j);
		}
			
	}printf("\n");
	k=m&n;g=m|n;l=m^n;
	
	
	for(int i=0;i<26;i++)
	{
		if(((k>>i)&1)==1) 	printf("%c",'a'+i);
		
	}
	printf("\n");
	 for(int i=0;i<26;i++)
	{
		if(((g>>i)&1)==1) 	printf("%c",'a'+i);
		
	}
	printf("\n");
	 for(int i=0;i<26;i++)
	{
		if(((l>>i)&1)==1) 	printf("%c",'a'+i);
		
	}
		printf("\n");
	
		for(int i=0;i<108;i++)
	{
		x[i]=0;y[i]=0;
	}
}

	return 0;
}
