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
int moves[8][2]={{0,1},{0,-1},{1,0},{-1,0},{1,1},{-1,-1},{-1,1},{1,-1}};
const int MAXN=1e2+5;
char grid[MAXN][MAXN];
int row,col;
void dfs(int x, int y)
{
	grid[x][y]='*';
	for(int i=0;i<8;i++)
	{
		int new_x=x+moves[i][0];
		int new_y=y+moves[i][1];
		if(new_x>=0 && new_x<row && new_y>=0 && new_y<col && grid[new_x][new_y]=='@')
			dfs(new_x,new_y);
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

	
	while(cin>>row>>col)
	{
		if(row==0 && col==0)
			return 0;
		
		for(int i=0;i<row;i++)
			for(int j=0;j<col;j++)
				cin>>grid[i][j];

	int count=0;
	for(int i=0;i<row;i++)
	{
		for(int j=0;j<col;j++)
		{
			if(grid[i][j]=='@')
			{
				//cout<<i<<" "<<j<<endl;
				count++;
				dfs(i,j);
			}
		}
	}
	cout<<count<<endl;
	}
		

	
}