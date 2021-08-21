#include <stdio.h>
#include <math.h>
/* run this program using the console pauser or add your own getch, system("pause") or input loop */
double dis(int xa,int ya,int xb,int yb)
{
	double dis=sqrt(((double)xa-xb)*(xa-xb)+((double)ya-yb)*(ya-yb));
	return dis;
}

int main(int argc, char** argv) {
	int xa,ya,ra,xb,yb,rb;
	while (scanf("%d%d%d%d%d%d",&xa,&ya,&ra,&xb,&yb,&rb)){
	

	double dist=dis(xa,ya,xb,yb);
	if(xa==xb&&ya==yb&&ra==rb)
	{
		printf("fu zhi zhan tie bu xiang ma\n");
	}
	else if(ra==rb)
	{
		printf("zong you ren yao yong jian pan ai ge qiao\n");
	}
	else if(xa==xb&&ya==yb)
	{
		printf("Ctrl+C/V tian xia di yi\n");
	}
	else if(dist<abs(ra-rb))
	{
		printf("zhe ci ying gai dou hui fu zhi le ba\n");
	}
	else if(fabs(dist-abs(ra-rb))<pow(10,-6))
	{
		printf("oo00OO00ooo0OO0oo0OooO00oo\n");
	}
		else if(dist>abs(ra-rb)&&dist<(ra+rb))
	{
		printf("lIllIIlI11lIIIlIl1l1111\n");
	}
	else if(fabs(dist-(ra+rb))<pow(10,-6))
	{
		printf("rrnnmnrmrnmrnrmnrmrnrm\n");
	}
	else if(ra+rb<dist)
	{
		printf("qpgqopgqopgopqgpqggqpoogoo\n");
	}
}
	return 0;
}
