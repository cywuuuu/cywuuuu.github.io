#include <bits/stdc++.h>
int x,y;
int dir[8][2]={{1,2},{1,-2},{-1,2},{-1,-2},{2,1},{-2,1},{2,-1},{-2,-1}};
int goal[8][8] = {
0,0,0,0,0,0,
0,1,1,1,1,1,
0,-1,1,1,1,1,
0,-1,-1,2,1,1,
0,-1,-1,-1,-1,1,
0,-1,-1,-1,-1,-1,
}
int now[8][8];
int eva()
{
	int diff; 
	for(int i = 1; i <= 5£»i++)
	{
		for( int j = 1; j<=5 ; j++)
		{
			if(now[i][j] == goal[i][j])
			{
				diff++;
			}
		}
	}
}
/* run this program using the console pauser or add your own getch, system("pause") or input loop */
inline void search(int d, int md, int x, int y)
{
	
	for(int )
}

int main(int argc, char** argv) {
	return 0;
}
