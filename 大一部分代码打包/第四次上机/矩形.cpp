#include <stdio.h>
/* run this program using the console pauser or add your own getch, system("pause") or input loop */
int isin(int maxx,int minx,int maxy,int miny,int xi,int yi)
{
	if(xi<=maxx&&xi>=minx&&yi<=maxy&&yi>=miny) return 1;
	else return 0;
}

int main(int argc, char** argv) {
	int n,m;//n juxing m dian
	scanf("%d%d",&n,&m);
	int x[5][54]={0},y[5][54]={0},xi[1008]={0},yi[1008]={0};//xiyi is for point、 x[][]is for diffrent corner of each the square 
	int maxx[54]={-2001},minx[54]={2001},maxy[54]={-2001},miny[54]={2001};// each squares region  非0不能一次性复值 
	for(int i=0;i<54;i++)
	{
		maxx[i]=-2001;
		minx[i]=2001;
		maxy[i]=-2001;
		miny[i]=2001;
	 } 
	for(int i=0;i<n;i++)
	{
		scanf("%d%d%d%d%d%d%d%d",&x[1][i],&y[1][i],&x[2][i],&y[2][i],&x[3][i],&y[3][i],&x[4][i],&y[4][i]);
		for(int j=1;j<=4;j++)
		{
			if(maxx[i]<x[j][i]) maxx[i]=x[j][i];
			if(minx[i]>x[j][i]) minx[i]=x[j][i];
			if(maxy[i]<y[j][i]) maxy[i]=y[j][i];
			if(miny[i]>y[j][i]) miny[i]=y[j][i];
		}
	}
	
	for(int j=0;j<m;j++)
	{
		scanf("%d%d",&xi[j],&yi[j]);
	}
	
	int cnt;
	for(int i=0;i<n;i++)
	{	cnt=0;
		for(int j=0;j<m;j++)
		{
			if(isin(maxx[i],minx[i],maxy[i],miny[i],xi[j],yi[j])) cnt++;
		}
		printf("%d\n",cnt);
	}
	
	return 0;
}
