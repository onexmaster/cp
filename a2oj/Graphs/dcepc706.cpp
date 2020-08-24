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
//char grid[MAXN][MAXN];
map<pair<int,int>,int>dist1,dist2,dist3;
//vis holds unpassable points;
set<pair<int,int>>vis;
int row,col;
void bfs1(int x, int y)
{
	queue<pii>q;
	q.push({x,y});
	dist1[{x,y}]=0;
	while(!q.empty())
	{
		int curr_x=q.front().first;
		int curr_y=q.front().second;
		q.pop();
		for(int i=0;i<4;i++)
		{
			int new_x=curr_x+moves[i][0];
			int new_y=curr_y+moves[i][1];
			//points just outise the grid are pasable
			if(new_x>=-1 && new_x<=row && new_y>=-1 && new_y<=col && vis.find({new_x,new_y})==vis.end())
			{
				if(dist1.count({new_x,new_y})==0)
				{
					dist1[{new_x,new_y}]=dist1[{curr_x,curr_y}]+1;
					q.push({new_x,new_y});
				}
					
			}
		}
	}
}
void bfs2(int x, int y)
{
	queue<pii>q;
	q.push({x,y});
	dist2[{x,y}]=0;
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
			//points just outise the grid are pasable
			if(new_x>=-1 && new_x<=row && new_y>=-1 && new_y<=col && vis.find({new_x,new_y})==vis.end())
			{
				if(dist2.count({new_x,new_y})==0)
				{
					dist2[{new_x,new_y}]=dist2[{curr_x,curr_y}]+1;
					q.push({new_x,new_y});
				}
					
			}
		}
	}
}
void bfs3(int x, int y)
{
	queue<pii>q;
	q.push({x,y});
	dist3[{x,y}]=0;
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
			//points just outise the grid are pasable
			if(new_x>=-1 && new_x<=row && new_y>=-1 && new_y<=col && vis.find({new_x,new_y})==vis.end())
			{
				if(dist3.count({new_x,new_y})==0)
				{
					dist3[{new_x,new_y}]=dist3[{curr_x,curr_y}]+1;
					q.push({new_x,new_y});
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
		int sx1,sy1,sx2,sy2,sx3,sy3;
		cin>>row>>col;
		for(int i=0;i<row;i++)
		{
			string st1;
			cin>>st1;
			for(int j=0;j<st1.size();j++)
			{
				if(st1[j]=='1')
				{
					sx1=i;
					sy1=j;
				}

				else if(st1[j]=='2')
				{
					sx2=i;
					sy2=j;
				}

				else if(st1[j]=='3')
				{
					sx3=i;
					sy3=j;
				}
				else if(st1[j]=='#')
					vis.insert({i,j});
			}

		}
		bfs1(sx1,sy1);
		bfs2(sx2,sy2);
		bfs3(sx3,sy3);
		int ans=INT_MAX;
		for(int i=-1;i<=row;i++)
		{
			for(int j=-1;j<=col;j++)
			{
				if(dist1.count({i,j})!=0)
				{
					int temp=max(dist1[{i,j}],max(dist2[{i,j}],dist3[{i,j}]));
					ans=min(ans,temp);
				}
				
			}
		}
		cout<<ans<<endl;
		dist1.clear();
		dist2.clear();
		dist3.clear();
		vis.clear();
		

	}
	
}