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

const int MAXN=105;
int grid[MAXN][MAXN];
int moves[4][4]={{-1,0},{1,0},{0,-1},{0,1}};
int row;
int col;
void dijkstras(vector<vector<int>>&dist)
{
	//bool vis[MAXN][MAXN]={false};
	for(int i=0;i<row;i++)
		for(int j=0;j<col;j++)
			dist[i][j]=1000000000;
	
	priority_queue<pair<int,pair<int,int>>,vector<pair<int,pair<int,int>>>, greater<pair<int,pair<int,int>>>>pq;
	pq.push({grid[0][0],{0,0}});
	dist[0][0]=grid[0][0];
	//vis[0][0]=true;
	while(!pq.empty())
	{
		int curr_cost=pq.top().first;
		int curr_x=pq.top().second.first;
		int curr_y=pq.top().second.second;
		//cout<<curr_x<<" "<<curr_y<<endl;
		pq.pop();
		for(int i=0;i<4;i++)
		{
			int new_x=curr_x+moves[i][0];
			int new_y=curr_y+moves[i][1];
			if(new_x>=0 && new_x<row && new_y>=0 && new_y<col && dist[new_x][new_y]> dist[curr_x][curr_y]+grid[new_x][new_y])
			{
				dist[new_x][new_y]=curr_cost+grid[new_x][new_y];
				pq.push({dist[new_x][new_y],{new_x,new_y}});
				//vis[curr_x][curr_y]=true;
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
		cin>>row>>col;
		for(int i=0;i<row;i++)
			for(int j=0;j<col;j++)
				cin>>grid[i][j];

		vector<vector<int>>dist(MAXN,vector<int>(MAXN,0));


		int dest_x,dest_y,T;
		cin>>dest_x>>dest_y>>T;
		dijkstras(dist);
		int total_time=dist[dest_x-1][dest_y-1];
		if(total_time<=T)
		{
			cout<<"YES"<<endl;
			cout<<T-total_time<<endl;
		}
		else
		{
			cout<<"NO"<<endl;
		}

		 // for(int i=0;i<row;i++)
		 // {
		 // 	for(int j=0;j<col;j++)
		 // 		cout<<dist[i][j]<<" ";
		 // 	cout<<endl;
		 // }

	}
	return 0;
	
}