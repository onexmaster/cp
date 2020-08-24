//BITMASK + BFS
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
const int MAXN=55;
int grid[MAXN][MAXN];
bool vis[MAXN][MAXN];
int row,col;
bool vis_boss[11];
int sx,sy,ex,ey;
void bfs()
{
	//if the boss of the starting index has not been told sorry yet then we can do bfs hence return
	if(!vis_boss[grid[sx][sy]])
		return;
	queue<pii>q;
	q.push({sx,sy});
	vis[sx][sy]=true;
	while(!q.empty())
	{
		int curr_x=q.front().first;
		int curr_y=q.front().second;
		q.pop();
		//cout<<curr_x<<" "<<curr_y<<endl;
		if(curr_x==ex && curr_y==ey)
			return;
		for(int i=0;i<4;i++)
		{
			int new_x=curr_x+moves[i][0];
			int new_y=curr_y+moves[i][1];
			if(new_x>=0 && new_x<row && new_y>=0 && new_y<col && !vis[new_x][new_y])
			{
				int new_boss=grid[new_x][new_y];
				if(vis_boss[new_boss])
				{
					q.push({new_x,new_y});
					vis[new_x][new_y]=true;
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
		memset(grid,-1,sizeof(grid));
		//memset(dist,INF,sizeof(dist));
		cin>>row;
		col=row;
		for(int i=0;i<row;i++)
			for(int j=0;j<col;j++)
				cin>>grid[i][j];
		
		cin>>sx>>sy>>ex>>ey;
		int sol=10;
		//int ans=INT_MAX;
		//Lets create a mask for all the bosses and then only say sorry to such bosses
		//whose mask value is 1 and then find if dest is reachable or not
		int y;
		for(int i=1;i<=1024;i++)
		{
			//count the number of 1s in y
			y=0;
			for(int j=0;(1<<j)<=1024;j++)
			{
				if(i&(1<<j))
				{
					vis_boss[j]=true;
					y++;
				}
				else 
					vis_boss[j]=false;
			}
			if(y<sol)
			{
				memset(vis,false,sizeof(vis));
				bfs();
				if(vis[ex][ey])
				{
					sol=y;
					//cout<<sol<<endl;
				}
			}

		}
		cout<<sol<<endl;
	}
	
}