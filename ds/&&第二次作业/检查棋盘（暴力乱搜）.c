#include <stdio.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */
int a[21][21];
int check(int x, int y)
{
	int dir[4][2] = {{1,0},{0,1},{1,1},{1,-1},}; 
	int cnt = 0;
	int k, l;
	cnt = 0;int p; 
	for( p = 0; p <= 4; p++)
	{
		cnt = 0;
		for(k = x, l = y; x>0&&x<=19&&y>0&&y<=19&&cnt < 4; k += dir[p][0], l += dir[p][1])
		{
			if(a[k][l]==a[x][y]) cnt++;
			else 
			{
				break;
			}
		}
		if(x<=0&&x>19&&y<=0&&y>19) continue;
		else if(cnt==4 &&(a[x-dir[p][0]][y - dir[p][1]]==0 || a[k][l]==0)&& (x-dir[p][0]>0&&x-dir[p][0]<=19&&y - dir[p][1]>0&&y - dir[p][1]<=19) && k>0 && k<=19 && l>0 && l<=19) return 1;
		
	}
	return -1;
}
//连成4个棋子，
//且该4个棋子的两端至少有一端为空位置。
int main(int argc, char** argv) {
	int flag = 0; int i; int j;
	for( i = 1; i <= 19; i++ )
	{
		for(j = 1; j <= 19; j++)
		{
			scanf("%d",&a[i][j]);
		}
	}
		for(i = 1; i <= 19; i++ )
	{
		for(j = 1; j <= 19; j++)
		{
			if(a[i][j] != 0)
			{
				if(check(i,j) == 1)
				{
					printf("%d:%d,%d\n", a[i][j], i, j);
					flag = 1;
				} 
			}
		}
	}
	if(flag == 0) printf("No\n");
	return 0;
}
