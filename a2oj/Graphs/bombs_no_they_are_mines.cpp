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
bool vis[MAXN][MAXN];
int dist[MAXN][MAXN];
int row;
int col;
void bfs(int x, int y)
{
	memset(dist,INF,sizeof(dist));
	queue<pii>q;
	q.push({x,y});
	vis[x][y]=true;
	dist[x][y]=0;
	while(!q.empty())
	{
		int curr_x=q.front().first;
		int curr_y=q.front().second;
		q.pop();
		//cout<<curr_x<<" "<<curr_y<<endl;
		for(int i=0;i<4;i++)
		{
			int new_x=curr_x+moves[i][0];
			int new_y=curr_y+moves[i][1];
			if(new_x>=0 && new_x<row && new_y>=0 && new_y<col && !vis[new_x][new_y])
			{
				dist[new_x][new_y]=dist[curr_x][curr_y]+1;
				q.push({new_x,new_y});
				vis[new_x][new_y]=true;
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

	while(cin>>row>>col)
	{
		if(row==0 && col==0)
			return 0;
		memset(vis,false,sizeof(vis));
		int mines;
		cin>>mines;
		while(mines--)
		{
			int row, number;
			cin>>row>>number;
			while(number--)
			{
				int col;
				cin>>col;
				vis[row][col]=true;
			}
		}
		int x0,y0,x1,y1;
		cin>>x0>>y0>>x1>>y1;
		bfs(x0,y0);
		cout<<dist[x1][y1]<<endl;
	}
	
}