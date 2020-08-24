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
const int MAXN=105;
int grid[MAXN][MAXN];
set<pair<int,int>>vis;
bool is_present[MAXN];
int t;
void dfs(int x, int y, int no)
{
	//cout<<x<<" "<<y<<" "<<no<<endl;
	grid[x][y]=-1;
	vis.insert({x,y});
	for(int i=0;i<4;i++)
	{
		int new_x=x+moves[i][0];
		int new_y=y+moves[i][1];
		if(new_x>=1 && new_x<=t && new_y>=1 && new_y<=t && grid[new_x][new_y]==no)
			dfs(new_x,new_y,no);
	}
}
int main()
{

	#ifndef ONLINE_JUDGE
	freopen("inputf.in","r",stdin);
	freopen("outputf.in","w",stdout);
	#endif

	while(cin>>t)
	{
		if(t==0)
			return 0;
		memset(grid,0,sizeof(grid));
		memset(is_present,false,sizeof(is_present));
		for(int i=0;i<t-1;i++)
		{
			for(int j=0;j<t;j++)
			{
				int x,y;
				cin>>x>>y;
				grid[x][y]=i+1;
				if(j+1==t)
					while((getchar())!='\n');
			}
		}
		// for(int i=1;i<=t;i++)
		// {
		// 	for(int j=1;j<=t;j++)
		// 		cout<<grid[i][j]<<" ";
		// 	cout<<endl;
		// }
		for(int i=1;i<=t;i++)
		{
			for(int j=1;j<=t;j++)
			{
				int curr=grid[i][j];
				if(curr!=-1 && !is_present[curr])
				{
					dfs(i,j,curr);
					is_present[curr]=true;
				}
			}
		}
		// for(int i=1;i<=t;i++)
		// {
		// 	for(int j=1;j<=t;j++)
		// 		cout<<grid[i][j]<<" ";
		// 	cout<<endl;
		// }
		//cout<<vis.size()<<endl;
		if(vis.size()==t*t)
			cout<<"good"<<endl;
		else
			cout<<"wrong"<<endl;
		vis.clear();

	}

	
}