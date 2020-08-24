// Created by Tanuj Jain
#include<bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;
#define pb push_back
#define mp make_pair
typedef long long ll;
typedef pair<int,int> pii;
template<class T> using oset=tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
const int INF = 0x3f3f3f3f;
int knight_moves[8][2]={{-2,-1},{-1,-2},{1,-2},{2,-1},{-2,1},{-1,2},{1,2},{2,1}};
int moves[4][2]={{0,1},{0,-1},{1,0},{-1,0}};
const int MAXN=55;
char grid[MAXN][MAXN];
bool vis[MAXN][MAXN];
bool cycle=false;
int row,col;
void dfs(int x, int y, int fromx, int fromy, char col)
{
	if(x<0 ||x>=row || y<0 || y>=col)
		return;
	if(grid[x][y]!=col)
		return;
	if(vis[x][y])
	{
		cycle=true;
		return;
	}
	vis[x][y]=true;
	for(int i=0;i<4;i++)
	{
		int new_x=x+moves[i][0];
		int new_y=y+moves[i][1];
		if(new_x== fromx && new_y==fromy)
			continue;
		dfs(new_x,new_y,x,y, col);
	}
}

int main()
{
	ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

	#ifndef ONLINE_JUDGE
	freopen("inputf.in","r",stdin);
	freopen("outputf.in","w",stdout);
	#endif

	
	cin>>row>>col;
	for(int i=0;i<row;i++)
	{
		string st1;
		cin>>st1;
		for(int j=0;j<col;j++)
			grid[i][j]=st1[j];
	}
	
	for(int i=0;i<row;i++)
		for(int j=0;j<col;j++)
			if(!vis[i][j])
				dfs(i,j,-1,-1, grid[i][j]);
	if(cycle)
		cout<<"Yes";
	else
		cout<<"No";

}