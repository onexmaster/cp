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
const int MAXN=205;
char grid[MAXN][MAXN];
int dist[MAXN][MAXN];
bool vis[MAXN][MAXN];
int row,col;
int sx,sy,ex,ey;
int dijktras(int x, int y)
{
	
	memset(vis,false,sizeof vis);
	priority_queue<pair<int,pair<int,int>>, vector<pair<int,pair<int,int>>>, greater<pair<int,pair<int,int>>>>pq;
	pq.push({0,{x,y}});
	while(!pq.empty())
	{
		int curr_cost=pq.top().first;
		int curr_x=pq.top().second.first;
		int curr_y=pq.top().second.second;
		pq.pop();
		if(vis[curr_x][curr_y])
			continue;
		if(curr_x==ex && curr_y==ey)
			return curr_cost;
		vis[curr_x][curr_y]=true;
		for(int i=0;i<4;i++)
		{
			int new_x=curr_x+moves[i][0];
			int new_y=curr_y+moves[i][1];
			if(new_x>=0 && new_x<row && new_y>=0 && new_y<col)
			{
				//if the time needed for new cell to walk is less than time needed to walk on old cell
				//vist the new cell
				if(grid[new_x][new_y]=='#')
				{
					//if cell was blocked before but now it is useable
					if(curr_cost+1>=dist[new_x][new_y])
						pq.push({curr_cost+1,{new_x,new_y}});
					//if still not walkable
					else
						pq.push({dist[new_x][new_y],{new_x,new_y}});
				}
				else
					if(grid[new_x][new_y]=='.')
						pq.push({curr_cost+1,{new_x,new_y}});
				
			}
		}
	}
	return -1;
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

	int t;
	cin>>t;
	while(t--)
	{
		//reset grids
		for(int i=0;i<MAXN;i++)
			for(int j=0;j<MAXN;j++)
				dist[i][j]=INF;
		for(int i=0;i<MAXN;i++)
			for(int j=0;j<MAXN;j++)
				grid[i][j]='x';


		cin>>row>>col;
		for(int i=0;i<row;i++)
		{
			string st1;
			cin>>st1;
			for(int j=0;j<st1.size();j++)
				grid[i][j]=st1[j];
		}
		for(int i=0;i<row;i++)
		{
			for(int j=0;j<col;j++)
				cin>>dist[i][j];
		}
		cin>>sx>>sy>>ex>>ey;
		cout<<dijktras(sx,sy)<<endl;

	}
	
}