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
struct custom_hash {
    static uint64_t splitmix64(uint64_t x) {
        // http://xorshift.di.unimi.it/splitmix64.c
        x += 0x9e3779b97f4a7c15;
        x = (x ^ (x >> 30)) * 0xbf58476d1ce4e5b9;
        x = (x ^ (x >> 27)) * 0x94d049bb133111eb;
        return x ^ (x >> 31);
    }

    size_t operator()(uint64_t x) const {
        static const uint64_t FIXED_RANDOM = chrono::steady_clock::now().time_since_epoch().count();
        return splitmix64(x + FIXED_RANDOM);
    }
};
const int MAXN=55;
int n;
char grid[MAXN][MAXN];
bool vis_s[MAXN][MAXN];
bool vis_e[MAXN][MAXN];
void bfs_s(int x,int y)
{
	memset(vis_s,false,sizeof(vis_s));
	queue<pii>q;
	q.push({x,y});
	vis_s[x][y]=true;
	while(!q.empty())
	{
		int curr_x=q.front().first;
		int curr_y=q.front().second;
		q.pop();
		//cout<<curr_x<<curr_y<<endl;
		for(int i=0;i<4;i++)
		{
			int new_x=curr_x+moves[i][0];
			int new_y=curr_y+moves[i][1];
			if(new_x>0 && new_x<=n && new_y>0 &&new_y<=n &&grid[new_x][new_y]=='0' && !vis_s[new_x][new_y])
			{
				vis_s[new_x][new_y]=true;
				q.push({new_x,new_y});

			}
		}
	}
}
void bfs_e(int x,int y)
{
	memset(vis_e,false,sizeof(vis_e));
	queue<pii>q;
	q.push({x,y});
	vis_e[x][y]=true;
	while(!q.empty())
	{
		int curr_x=q.front().first;
		int curr_y=q.front().second;
		q.pop();
		//cout<<curr_x<<curr_y<<endl;
		for(int i=0;i<4;i++)
		{
			int new_x=curr_x+moves[i][0];
			int new_y=curr_y+moves[i][1];
			if(new_x>0 && new_x<=n && new_y>0 &&new_y<=n &&grid[new_x][new_y]=='0' && !vis_e[new_x][new_y])
			{
				vis_e[new_x][new_y]=true;
				q.push({new_x,new_y});

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

	cin>>n;
	int sx,sy,ex,ey;
	cin>>sx>>sy>>ex>>ey;
	for(int i=1;i<=n;i++)
	{
		string temp;
		cin>>temp;
		for(int j=0;j<temp.size();j++)
			grid[i][j+1]=temp[j];
	}
	bfs_s(sx,sy);
	if(vis_s[ex][ey])
	{
		cout<<0;
		return 0;
	}
	//find the cells which can be vis from end state 
	bfs_e(ex,ey);
	vector<pii>neigh;
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=n;j++)
			if(vis_e[i][j])
				neigh.pb({i,j});
	}
	neigh.pb({ex,ey});
	ll ans=INT_MAX;
	//connect the points which are reachable from start and reacheble from end via a tunnel
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=n;j++)
		{
			if(vis_s[i][j])
			{
				for(int k=0;k<neigh.size();k++)
				{
					ll dist=(i-neigh[k].first)*(i-neigh[k].first)+(j-neigh[k].second)*(j-neigh[k].second);
					ans=min(ans,dist);
				}
			}
		}
	}
	cout<<ans;



}