#include <stdio.h>
int main() {
	int Date,year,m,d,w,y,c;
	printf("������һ������(eg:20191130):");
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
	case 0:printf("������\n");break;
	
	case 1:printf("����һ\n");break;

	case 2:printf("���ڶ�\n");break;

	case 3:printf("������\n");break;

	case 4:printf("������\n");break;

	case 5:printf("������\n");break;

	case 6:printf("������\n");break;	
	}
	return 0;
}
