#include <stdio.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */
int isrun(int y)
{
	if((y%4==0&&y%100!=0)||y%400==0)
	{
		return 1;
	}
	
	else return 0;
}

int main(int argc, char** argv) {
	int y,m,d,sum,manyday;
	int run[13]={0,31,29,31,30,31,30,31,31,30,31,30,31};
	int notrun[13]={0,31,28,31,30,31,30,31,31,30,31,30,31};
	while(scanf("%d%d%d",&y,&m,&d)!=EOF){
	sum=0,manyday=0;
	
	if(isrun(y)) 
	{
		if(run[m]<d) {printf("lT lS A WRONG DATE\n");continue;}
		
	}
	
	if(isrun(y)==0)
	{
		if(notrun[m]<d) {printf("lT lS A WRONG DATE\n");continue;}
		
	}
	
	
	for(int i=0;i<y;i++)
	{
		if(isrun(i)) manyday+=366;
		if(isrun(i)==0) manyday+=365;
	}
	
//
	if(isrun(y))
	{
		for(int i=1;i<=m-1;i++)
		{
			manyday+=run[i];
		}
	}
	
	else if(isrun(y)==0){
		for(int i=1;i<=m-1;i++)
		{
			manyday+=notrun[i];
		}
	}
	
	manyday+=d;
	printf("%d\n",(manyday-1)%7+1);
	
}	
	
	return 0;
}
