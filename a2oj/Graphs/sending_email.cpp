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
const int MAXN= 20005;
const int INF = 0x3f3f3f3f;
map<int,vector<pair<int,int>>>ada;
int dist[MAXN];
int n;
int m;
int source;
int dest;
void dijkstras(int source)
{
	memset(dist,INF,sizeof(dist));
	priority_queue<pii, vector<pii>, greater<pii>>pq;
	pq.push({0,source});
	dist[source]=0;
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
	int temp=1;
	while(t--)
	{
		cin>>n>>m>>source>>dest;
		while(m--)
		{
			int x,y,cost;
			cin>>x>>y>>cost;
			ada[x].pb({y,cost});;
			ada[y].pb({x,cost});
		}
		dijkstras(source);
		if(dist[dest]!=INF)
			cout<<"Case #"<<temp<<": "<<dist[dest]<<endl;
		else
			cout<<"Case #"<<temp<<": "<<"unreachable"<<endl;
		ada.clear();
		temp++;

	}
	
}