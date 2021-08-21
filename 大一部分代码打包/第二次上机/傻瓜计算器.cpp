#include <stdio.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char** argv) {
 
	double a,b,c,d,e,f,all;
	char g,h,i,j,k;
	//正确
	//scanf("%lf %c %lf %c %lf %c %lf %c %lf %c %lf",&a,&g,&b,&h,&c,&i,&d,&j,&e,&k,&f);
//错例	
scanf("%lf%c%lf%c%lf%c%lf%c%lf%c%lf",&a,&g,&b,&h,&c,&i,&d,&j,&e,&k,&f);//%c==getchar 会吸入空白符 
	if(g=='+') {
		all=a+b;
	}
	if(g=='-')
	{
		all=a-b;
	}
	if(g=='/')
	{
		all=a/b;
	}
	if(g=='*')
	{
		all=a*b;
	}
	
	/********************/
		if(h=='+') {
		all+=c;
	}
	if(h=='-')
	{
		all-=c;
	}
	if(h=='/')
	{
		all/=c;
	}
	if(h=='*')
	{
		all*=c;
	}
	
	/********************i,d*/
		if(i=='+') {
		all+=d;
	}
	if(i=='-')
	{
		all-=d;
	}
	if(i=='/')
	{
		all/=d;
	}
	if(i=='*')
	{
		all*=d;
	}
	
	/********************j,e*/
		if(j=='+') {
		all+=e;
	}
	if(j=='-')
	{
		all-=e;
	}
	if(j=='/')
	{
		all/=e;
	}
	if(j=='*')
	{
		all*=e;
	}
	
	/********************k,f*/
		if(k=='+') {
		all+=f;
	}
	if(k=='-')
	{
		all-=f;
	}
	if(k=='/')
	{
		all/=f;
	}
	if(k=='*')
	{
		all*=f;
	}
	
	printf("%014.9lf",all); 
	return 0;
}
