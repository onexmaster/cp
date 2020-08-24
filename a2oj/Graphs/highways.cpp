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
const int MAXN=1e5+5;
int dijktras(map<int,vector<pii>>&ada, int source, int dest)
{
	//bool vis[MAX]={false};
	int dist[MAXN];
	//reset the dist to inf value
	for(int i=0;i<MAXN;i++)
		dist[i]=1e7;

	priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>> >pq;
	dist[source]=0;
	//vis[source]=true;
	pq.push({0,source});
	while(!pq.empty())
	{
		int curr=pq.top().second;
		int cost=pq.top().first;
		pq.pop();
		if(curr==dest)
			break;
		for(auto edges: ada[curr])
		{
			if(dist[edges.first]>cost+edges.second)
			{
				dist[edges.first]=cost+edges.second;
				pq.push({dist[edges.first],edges.first});
			}
		}
	}
	return dist[dest];
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
		int a,b,s,d;
		cin>>a>>b>>s>>d;
		map<int,vector<pii>>ada;
		for(int i=0;i<b;i++)
		{
			int x,y,cost;
			cin>>x>>y>>cost;
			ada[x].pb({y,cost});
			ada[y].pb({x,cost});
		}
		int ans=dijktras(ada, s, d);
		if(ans==1e7)
			cout<<"NONE"<<endl;
		else
			cout<<ans<<endl;
	}
	
}