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
const int MAXN=1e4+5;
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
		int curr=pq.top().second;
		pq.pop();
		for(auto edges: ada[curr])
		{
			if(dist[edges.first]>curr_cost+edges.second)
			{
				dist[edges.first]=curr_cost+edges.second;
				pq.push({dist[edges.first],edges.first});
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
		ada.clear();
		int v,e;
		cin>>v>>e;
		while(e--)
		{
			int x,y,cost;
			cin>>x>>y>>cost;
			ada[x].pb({y,cost});
		}
		int src,dest;
		cin>>src>>dest;
		dijkstras(src);
		if(dist[dest]==INF)
			cout<<"NO"<<endl;
		else
			cout<<dist[dest]<<endl;
	}
	
}