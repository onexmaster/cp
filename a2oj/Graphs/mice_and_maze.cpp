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
unordered_map<int,vector<pii>>ada;
int dist[MAXN];
void dijkstras(int src)
{
	memset(dist,INF,sizeof(dist));
	priority_queue<pii, vector<pii>, greater<pii>>pq;
	pq.push({0,src});
	dist[src]=0;
	while(!pq.empty())
	{
		int curr_cost=pq.top().first;
		int u=pq.top().second;
		pq.pop();
		if(curr_cost!=dist[u])
			continue;
		for(auto edges:ada[u])
		{
			int to=edges.first;
			int cost=edges.second;
			if(dist[to]>curr_cost+cost)
			{
				dist[to]=curr_cost+cost;
				pq.push({dist[to],to});
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
	int n,e,ti,m;
	cin>>t;
	while(t--)
	{
		
		cin>>n>>e>>ti>>m;
		while(m--)
		{
			int u,v,cost;
			cin>>u>>v>>cost;
			ada[v].pb({u,cost});
		}
		dijkstras(e);
		int c=0;
		for(int i=1;i<=n;i++)
			if(dist[i]<=ti)
				c++;
		cout<<c<<endl;
		if(t)
			cout<<endl;
		ada.clear();
	}

	
}