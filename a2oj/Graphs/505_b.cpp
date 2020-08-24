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
const int MAXN=105;
bool vis[MAXN];
unordered_map<int,vector<pii>>ada;
void bfs(int src, int color)
{
	memset(vis,false,sizeof(vis));
	queue<pii>q;
	q.push({src,color});
	vis[src]=true;
	while(!q.empty())
	{
		int curr=q.front().first;
		int curr_color=q.front().second;
		q.pop();
		for(auto edges:ada[curr])
		{
			int edges_color=edges.second;
			if(edges_color==curr_color && !vis[edges.first])
			{
				q.push({edges.first,edges_color});
				vis[edges.first]=true;
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

	int n,m;
	cin>>n>>m;
	while(m--)
	{
		int u,v,c;
		cin>>u>>v>>c;
		ada[u].pb({v,c});
		ada[v].pb({u,c});
	}
	int q;
	cin>>q;
	while(q--)
	{
		int ans=0;
		int src,dest;
		cin>>src>>dest;
		for(int color=1;color<MAXN;color++)
		{
			bfs(src,color);
			if(vis[dest])
				ans++;
		}
		cout<<ans<<endl;
	}

	
}