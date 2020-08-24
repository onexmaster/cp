// Created by Tanuj Jain
//answer = ( shortest path from 1 to 2 + shortest path from 1 to 3 + shortest path from 1 to 4 )
 //             +
 //             ( shortest path from 2 to 1 + shortest path from 3 to 1 + shortest path from 4 to 1 )
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

const int MAXN=1e6+5;
int dist[MAXN];
int P;
int Q;

void dijkstras(int source, map<int,vector<pii>>adaj)
{
	for(int i=1;i<=P;i++)
		dist[i]=1e9+5;
	dist[source]=0;
	priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>>pq;
	pq.push({0,source});
	while(!pq.empty())
	{
		int curr=pq.top().second;
		int cost=pq.top().first;
		pq.pop();
		for(auto edges : adaj[curr])
		{
			if(dist[edges.first]> cost+edges.second)
			{
				dist[edges.first]=cost+edges.second;
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
		cin>>P>>Q;
		map<int,vector<pii>>ada;
		map<int,vector<pii>>ada_rev;
		for(int i=0;i<Q;i++)
		{
			int x,y,cost;
			cin>>x>>y>>cost;
			ada[x].pb({y,cost});
			ada_rev[y].pb({x,cost});
		}
		int ans=0;
		dijkstras(1,ada);
		for(int i=1;i<=P;i++)
			ans+=dist[i];
		dijkstras(1,ada_rev);
		for(int i=1;i<=P;i++)
			ans+=dist[i];
		cout<<ans<<endl;
	}
	
}