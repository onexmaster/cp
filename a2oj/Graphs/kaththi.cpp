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
const int MAXN=1e3+5;
char grid[MAXN][MAXN];
int dist[MAXN][MAXN];
int row, col;
void modified_bfs()
{
	deque<pii>q;
	q.push_front({0,0});
	dist[0][0]=0;
	while(!q.empty())
	{
		int curr_x=q.front().first;
		int curr_y=q.front().second;
		q.pop_front();
		if(curr_x==row-1 && curr_y==col-1)
				return;
		char curr_char=grid[curr_x][curr_y];
		for(int i=0;i<4;i++)
		{
			int new_x=curr_x+moves[i][0];
			int new_y=curr_y+moves[i][1];
			if(new_x>=0 && new_x<row && new_y>=0 && new_y<col)
			{
				char to_char=grid[new_x][new_y];
				int cost=(to_char==curr_char?0:1);
				if(dist[new_x][new_y]>dist[curr_x][curr_y]+cost)
				{
					dist[new_x][new_y]=dist[curr_x][curr_y]+cost;
					if(cost==0)
						q.push_front({new_x,new_y});
					else
						q.push_back({new_x,new_y});
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
		memset(grid,'1',sizeof(grid));
		memset(dist,INF,sizeof(dist));
		cin>>row>>col;
		for(int i=0;i<row;i++)
		{
			string st1;
			cin>>st1;
			for(int j=0;j<st1.length();j++)
				grid[i][j]=st1[j];
		}
		
		modified_bfs();
		cout<<dist[row-1][col-1]<<endl;

	}

	
}