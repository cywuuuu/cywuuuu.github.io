#include <bits/stdc++.h>
using namespace std;

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

#define LEN 362880
typedef struct node
{
	int state [9];
	int dis;
}node;
int dir[4][2] ={{-1,0},{1,0},{0,-1},{0,1}};
int bk[LEN] = {0};
int start[9],goal[9]={1,2,3,8,0,4,7,6,5};
long long fac[10] ={1,1,2,6,24,120,720,5040,40320,362880} ;
int ifavl(int str[],int n)//≈–÷ÿ 
{
	long long result = 0;
	for(int i=0; i<n;i++)
	{
		int cnt = 0;
		for(int j = i+1;j<n;j++)
		{
			if(str[j]<str[i]) cnt++;
		 } 
		 result += fac[n-1-i] * cnt;  
	} 
	if(bk[result]==1) return 0;
	else 
	{bk[result] = 1;return 1;} //ø…”√ 
}
int bfs()
{
	node head;
	memcpy(head.state,start, sizeof(head.state));
	head.dis=0;
	queue<node> q;
	ifavl(head.state,9);
	q.push(head);
	while(!q.empty())
	{
		head = q.front();
		if(memcmp(head.state,goal,sizeof(goal)) == 0)
		return head.dis;
		q.pop();
		int zero=0;//2 8 3 1 0 4 7 6 5
		while(head.state[zero]!=0)
		{
			zero++;
		}
		int x = zero%3;
		int y = zero/3;
		for(int i =0; i<4; i++)
		{
			int newx = x+dir[i][0];
			int newy = y+dir[i][1];
			int newz = newy*3 + newx;
			if(newx >=0 && newx < 3 && newy >=0 && newy < 3)
			{
				node newnode;
				memcpy(&newnode,&head,sizeof(node));
				swap (newnode.state[zero],newnode.state[newz]);
				newnode.dis++;
				if(ifavl(newnode.state,9))
				q.push(newnode); 
				
			}
		}
	}
	return -1;
}
int main(int argc, char** argv) {
	char s[10];
	scanf("%s",s);
	for(int i=0;i<9;i++) start[i] = s[i]-'0';
	int num = bfs();
	if(num!= -1) cout<<num<<endl; 
	return 0;
}
