
#include <iostream>
#include <string.h>
#define ll long long
#define max(x,y) ((x) > (y) ? (x) : (y))
using namespace std;
ll dirx[8] = {1,1,-1,-1,2,2,-2,-2};
ll diry[8] = {2,-2,2,-2,1,-1,1,-1};
ll dp[80][80];
ll vis[80][80];
int main(int argc, char** argv) {
	int m,n;
	int a,b;
	scanf("%d%d%d%d", &n, &m, &a, &b);
	memset(dp,0,sizeof(dp));
	memset(vis,0,sizeof(vis));
	vis[a][b] = 1;
	for(int i = 0; i <= 7; i++)
	{
		if(a+dirx[i] <= n && a+dirx[i] >= 0 && b+diry[i] >= 0&& b + diry[i] <= m)
		vis[a+dirx[i]][b+diry[i]] = 1;
	}	

	for(int i = 0; i <= n; i++)
	{
		if(vis[i][0] == 1) break;
		dp[i][0] = 1;
	}
	for(int i = 0; i <= m; i++)
	{
		if(vis[0][i] == 1) break; 
		dp[0][i] = 1;
	} //如果边上为0 后面边上就一直是0了 
	for(int i = 1; i <= n; i++)
		for(int j = 1; j <= m; j++)
		{
			if(vis[i][j]) dp[i][j] = 0;
			else
			dp[i][j] = dp[i-1][j] + dp [i][j-1];
		
		}
	
	printf("%lld\n",dp[n][m]);
		
	
	return 0;
}/*
#include<iostream>
#include<cstring>
#include<iomanip>
#include<cstdio>
#define MAXN 110
bool b[MAXN][MAXN];
long long a[MAXN][MAXN];
int dx[8]={2,1,-1,-2,-2,-1,1,2};
int dy[8]={1,2,2,1,-1,-2,-2,-1};
int n,m,x,y;
using namespace std;
int main(){
	cin>>n>>m>>x>>y;
	memset(b,0,sizeof(b));
	b[x][y]=1;
	for(int i=0;i<=7;i++){
		 if(x+dx[i]>=0&&x+dx[i]<=n&&y+dy[i]>=0&&y+dy[i]<=m){
		 	b[x+dx[i]][y+dy[i]]=1;
		 }
	}
	int k=0;
	while(!b[k][0]&&k<=n){
		a[k++][0]=1;
	}
	int l=0;
	while(!b[0][l]&&l<=m){
		a[0][l++]=1;
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			if(b[i][j]){
				a[i][j]=0;  //g[i][j]=1
			}
			else{
				a[i][j]=a[i-1][j]+a[i][j-1];  //i>0且j>0且g[i][j]=0
			}
		}
	}
	cout<<a[n][m];
	return 0;
}*/
