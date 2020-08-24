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
	vector<vector<pii>>ada(n+1);
	vector<int>dist(n+1,INT_MAX);
	while(m--)
	{
		int u,v;
		cin>>u>>v;
		if(u==v)
			continue;
		ada[u].pb({v,0});
		ada[v].pb({u,1});
	}
	//dijkstra();
	priority_queue<pii, vector<pii>, greater<pii>>pq;
	pq.push({0,1});
	dist[1]=0;
	while(!pq.empty())
	{
		int curr_cost=pq.top().first;
		int curr=pq.top().second;
		pq.pop();
		for(auto edges:ada[curr])
		{
			if(dist[edges.first]>curr_cost+edges.second)
			{
				dist[edges.first]=curr_cost+edges.second;
				pq.push({dist[edges.first],edges.first});
			}
		}
	}
	if(dist[n]==INT_MAX)
		cout<<-1<<endl;
	else
		cout<<dist[n]<<endl;
	return 0;

	
}