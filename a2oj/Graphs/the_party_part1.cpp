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
unordered_map<int,vector<int>>ada;
int dist[MAXN];
bool vis[MAXN];
void bfs()
{
	queue<int>q;
	q.push(0);
	dist[0]=0;
	vis[0]=true;
	while(!q.empty())
	{
		int curr=q.front();
		q.pop();
		for(auto v:ada[curr])
		{
			if(!vis[v])
			{
				q.push(v);
				vis[v]=true;
				dist[v]=dist[curr]+1;
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
		int n,m;
		cin>>n>>m;
		while(m--)
		{
			int u,v;
			cin>>u>>v;
			ada[u].pb(v);
			ada[v].pb(u);
		}
		memset(vis,false,sizeof(vis));
		memset(dist,INF,sizeof(dist));
		bfs();
		for(int i=1;i<n;i++)
			cout<<dist[i]<<endl;
		if(t>=1)
			cout<<endl;
		ada.clear();
	}
	
}