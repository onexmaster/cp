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
const int MAXN=1e5+5;
unordered_map<int,vector<int>>ada;
int dist[MAXN];
int src,dest;
void bfs()
{
	queue<int>q;
	q.push(src);
	dist[src]=0;
	while(!q.empty())
	{
		int curr=q.front();
		q.pop();
		if(curr==dest)
			return;
		for(auto edges:ada[curr])
		{
			if(dist[edges]>dist[curr]+1)
			{
				q.push(edges);
				dist[edges]=dist[curr]+1;
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
		int n;
		cin>>n;
		while(n--)
		{
			int u,p;
			cin>>u>>p;
			for(int i=0;i<p;i++)
			{
				int v;
				cin>>v;
				ada[u].pb(v);
				ada[v].pb(u);
			}
		}
		cin>>src>>dest;
		memset(dist,INF,sizeof(dist));
		bfs();
		cout<<src<<" "<<dest<<" "<<dist[dest]-1<<endl;
		if(t)
			cout<<endl;
		ada.clear();
	}
	
}