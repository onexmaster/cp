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
const int MAXN=255;
int grid[MAXN][MAXN];
map<int,int>m1;
int area;
int row,col;
void dfs(int x, int y)
{
	area++;
	grid[x][y]=0;
	for(int i=0;i<4;i++)
	{
		int x0=x+moves[i][0];
		int y0=y+moves[i][1];
		if(x0>=0 && x0<row && y0>=0 && y0<col && grid[x0][y0]==1)
			dfs(x0,y0);
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
		m1.clear();
		for(int i=0;i<row;i++)
			for(int j=0;j<col;j++)
				cin>>grid[i][j];
			int count=0;
		for(int i=0;i<row;i++)
		{
			for(int j=0;j<col;j++)
			{
				area=0;
				if(grid[i][j]==1)
				{
					dfs(i,j);
					count++;
					m1[area]++;
				}
			}
		}
		cout<<count<<endl;
		for(auto it:m1)
			cout<<it.first<<" "<<it.second<<endl;
			
	}	
	
}