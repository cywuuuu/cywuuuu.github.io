# LCA倍增

fa[i] [j] 代表 i号节点向上2^j^

```c++
#include <iostream>
#include <stdio.h>
#include <vector>
#define MAXN 500010

using namespace std;

int n , m , s , fa[ MAXN ][ 22 ] , dep[ MAXN ] , vis[ MAXN ];
vector < int > edge[ MAXN ];

void dfs( int x )
{
	vis[x] = 1;
	for( int i = 0 ; i < edge[x].size() ; i++ )
		if( !vis[ edge[x][i] ] )
		{
			dep[ edge[x][i] ] = dep[x] + 1;
			fa[ edge[x][i] ][0] = x;
			dfs( edge[x][i] );
		}
}

int main()
{
	cin >> n >> m >> s;
	for( int i = 1 ; i < n ; i++ )
	{
		int x , y;
		cin >> x >> y;
		edge[x].push_back( y );
		edge[y].push_back( x );
	}
	dfs( s );//标记dep
   // 2^j^
    //fa[i][j] 代表 i号节点向上2^j的父亲
	for( int j = 1 ; j < 20 ; j++ )
		for( int i = 1 ; i <= n ; i++ )
			fa[i][j] = fa[ fa[i][j - 1] ][j - 1];
	while( m-- )
	{
		int x , y;
		cin >> x >> y;
		if( dep[x] > dep[y] ) swap( x , y );
		int t = dep[y] - dep[x];
		for( int i = 19 ; i >= 0 ; i-- )
			if( ( t & ( 1 << i ) ) )
				y = fa[y][i];
		for( int i = 19 ; i >= 0 ; i-- )
			if( fa[x][i] != fa[y][i] )
				x = fa[x][i] , y = fa[y][i];
		if( x != y ) cout << fa[x][0] << endl;
		else cout << x << endl;
	}
	return 0;
}
```

# 树上dp

```c++
#include <iostream>
#include <stdio.h>
#include <vector>
#define MAXN 500010

using namespace std;

int n , m , s , fa[ MAXN ][ 22 ] , dep[ MAXN ] , vis[ MAXN ];
vector < int > edge[ MAXN ];

void dfs( int x )
{
	vis[x] = 1;
	for( int i = 0 ; i < edge[x].size() ; i++ )
		if( !vis[ edge[x][i] ] )
		{
			dep[ edge[x][i] ] = dep[x] + 1;
			fa[ edge[x][i] ][0] = x;
			dfs( edge[x][i] );
		}
}

int main()
{
	cin >> n >> m >> s;
	for( int i = 1 ; i < n ; i++ )
	{
		int x , y;
		cin >> x >> y;
		edge[x].push_back( y );
		edge[y].push_back( x );
	}
	dfs( s );
	for( int j = 1 ; j < 20 ; j++ )
		for( int i = 1 ; i <= n ; i++ )
			fa[i][j] = fa[ fa[i][j - 1] ][j - 1];
	while( m-- )
	{
		int x , y;
		cin >> x >> y;
		if( dep[x] > dep[y] ) swap( x , y );
		int t = dep[y] - dep[x];
		for( int i = 19 ; i >= 0 ; i-- )
			if( ( t & ( 1 << i ) ) )
				y = fa[y][i];
		for( int i = 19 ; i >= 0 ; i-- )
			if( fa[x][i] != fa[y][i] )
				x = fa[x][i] , y = fa[y][i];
		if( x != y ) cout << fa[x][0] << endl;
		else cout << x << endl;
	}
	return 0;
}
```

