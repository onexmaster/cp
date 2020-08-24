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
const int MAXN=1e3+5;
int grid[MAXN][MAXN];
int dist[MAXN][MAXN];
int row;
int col;
int moves[4][2]={{0,1},{0,-1},{1,0},{-1,0}};
void dijkstra()
{
	memset(dist,1e6,sizeof(dist));
	priority_queue<pair<int,pii>, vector<pair<int,pii>>, greater<pair<int,pii>>>pq;
	pq.push({grid[0][0],{0,0}});
	dist[0][0]=grid[0][0];
	while(!pq.empty())
	{
		int curr_cost=pq.top().first;
		int curr_x=pq.top().second.first;
		int curr_y=pq.top().second.second;
		pq.pop();
		for(int i=0;i<4;i++)
		{
			int new_x=curr_x+moves[i][0];
			int new_y=curr_y+moves[i][1];
			if(new_x>=0 && new_x<row && new_y>=0 && new_y<col && dist[new_x][new_y]>curr_cost+grid[new_x][new_y])
			{
				dist[new_x][new_y]=curr_cost+grid[new_x][new_y];
				pq.push({dist[new_x][new_y],{new_x,new_y}});
			}
		}

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

	int t;
	cin>>t;
	while(t--)
	{
		memset(grid,0,sizeof(grid));
		cin>>row>>col;
		for(int i=0;i<row;i++)
			for(int j=0;j<col;j++)
				cin>>grid[i][j];
		dijkstra();
		cout<<dist[--row][--col]<<endl;

	}
}