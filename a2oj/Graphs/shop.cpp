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
int moves[4][2]={{0,1},{0,-1},{1,0},{-1,0}};
int main()
{
	ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

	#ifndef ONLINE_JUDGE
	freopen("inputf.in","r",stdin);
	freopen("outputf.in","w",stdout);
	#endif

	int col,row;
	while(cin>>col>>row)
	{
		if(row==0 && col==0)
			return 0;
		else
		{
			int grid[row][col];
			pair<int,int>start;
			pair<int,int>end;
			int  dist[row][col];
			memset(dist,1e4,sizeof(dist));
			for(int i=0;i<row;i++)
			{
				for(int j=0;j<col;j++)
				{
					char x;
					cin>>x;
					//cout<<x<<" ";
					if(x=='S')
					{
						start.first=i;
						start.second=j;
						grid[i][j]=0;
					}
					else if(x=='D')
					{
						end.first=i;
						end.second=j;
						grid[i][j]=0;
					}
					else if(x=='X')
					{
						grid[i][j]=1e4;
					}
					else
					{
						grid[i][j]=(x-'0');
					}
				}
			}
			dist[start.first][start.second]=0;
			//Print Grid 
			// for(int i=0;i<row;i++)
			// {
			// 	for(int j=0;j<col;j++)
			// 		cout<<grid[i][j]<<" ";
			// 	cout<<endl;
			// }
			priority_queue<pair<int,pair<int,int>>, vector<pair<int,pair<int,int>>>, greater<pair<int,pair<int,int>>>>pq;
			pq.push({0,start});
			//vis[start.first][start.second]=true;
			while(!pq.empty())
			{
				int curr_cost=pq.top().first;
				int curr_x=pq.top().second.first;
				int curr_y=pq.top().second.second;
				pq.pop();
				//if(curr_x==end.first && curr_y==end.second)
				//	break;
				for(int i=0;i<4;i++)
				{
					int new_x=curr_x+moves[i][0];
					int new_y=curr_y+moves[i][1];
					if(new_x>=0 && new_x<row && new_y>=0 && new_y<col  &&  dist[new_x][new_y]>curr_cost+grid[new_x][new_y])
					{
						dist[new_x][new_y]=curr_cost+grid[new_x][new_y];
						pq.push({dist[new_x][new_y],{new_x,new_y}});
					}
				}

			}
			// for(int i=0;i<row;i++)
			// {
			// 	for(int j=0;j<col;j++)
			// 		cout<<dist[i][j]<<" ";
			// 	cout<<endl;
			// }
			cout<<dist[end.first][end.second]<<endl;

		}
	}
	
}