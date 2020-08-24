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
int moves[8][2]={{0,1},{0,-1},{1,0},{-1,0},{1,1},{-1,1},{1,-1},{-1,-1}};
const int MAXN=105;
char grid[MAXN][MAXN];
int dist[MAXN][MAXN];
int max_dist;
int row,col;
void bfs()
{
	memset(dist,INF,sizeof(dist));
	queue<pii>q;
	q.push({0,0});
	dist[0][0]=0;
	while(!q.empty())
	{
		int curr_x=q.front().first;
		int curr_y=q.front().second;
		q.pop();
		//cout<<curr_x<<" "<<curr_y<<endl;
		max_dist=max(max_dist,dist[curr_x][curr_y]);
		for(int i=0;i<8;i++)
		{
			int new_x=curr_x+moves[i][0];
			int new_y=curr_y+moves[i][1];
			if(new_x>=0 && new_x<row && new_y>=0 && new_y<col && grid[new_x][new_y]=='.')
			{
				if(dist[new_x][new_y]>dist[curr_x][curr_y]+1)
				{
					q.push({new_x,new_y});
					dist[new_x][new_y]=dist[curr_x][curr_y]+1;

				}
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
		memset(grid,'@',sizeof(grid));
		cin>>row>>col;
		
		for(int i=0;i<row;i++)
		{
			string st1;
			cin>>st1;
			for(int j=0;j<st1.size();j++)
			{
				grid[i][j]=st1[j];
			}
		}
		//print();
		max_dist=0;
		bfs();
		cout<<max_dist<<endl;


	}
	
}