#include <stdio.h>
int main() {
	int Date,year,m,d,w,y,c;
	printf("请输入一个日期(eg:20191130):");
	scanf("%d",&Date);
	year=Date/10000;
	m=Date%10000/100;
	d=Date%100;
	y=year%100;
	c=year/100;
	if(m==1||m==2){
		m+=12;
		y--;
	}
	w=(y+y/4+c/4-2*c+26*(m+1)/10+d-1)%7;
	printf("%d\n",w);
	switch(w){
	case 0:printf("星期日\n");break;
	
	case 1:printf("星期一\n");break;

	case 2:printf("星期二\n");break;

	case 3:printf("星期三\n");break;

	case 4:printf("星期四\n");break;

	case 5:printf("星期五\n");break;

	case 6:printf("星期六\n");break;	
	}
	return 0;
}
