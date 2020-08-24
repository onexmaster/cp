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
const int MAXN=1e4+5;
const int INF = 0x3f3f3f3f;
vector<int>dist1(MAXN,INF);
vector<int>dist2(MAXN,INF);
unordered_map<int,vector<pair<int,int>>>ada,ada_rev;
void dijkstra(int src, int dest)
{
	priority_queue<pii, vector<pii>, greater<pii>>pq;
	pq.push({0,src});
	dist1[src]=0;
	dist2[dest]=0;
	while(!pq.empty())
	{
		int curr_cost=pq.top().first;
		int curr=pq.top().second;
		pq.pop();
		for(auto edges:ada[curr])
		{
			if(dist1[edges.first]>curr_cost+edges.second)
			{
				dist1[edges.first]=curr_cost+edges.second;
				pq.push({dist1[edges.first],edges.first});
			}
		}
	}

	pq.push({0,dest});
	while(!pq.empty())
	{
		int curr_cost=pq.top().first;
		int curr=pq.top().second;
		pq.pop();
		for(auto edges:ada_rev[curr])
		{
			if(dist2[edges.first]>curr_cost+edges.second)
			{
				dist2[edges.first]=curr_cost+edges.second;
				pq.push({dist2[edges.first],edges.first});
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
		dist1=vector<int>(MAXN,INF);
		dist2=vector<int>(MAXN,INF);
		
		int n,m,k,s,t;
		cin>>n>>m>>k>>s>>t;
		while(m--)
		{
			int src,dest,cost;
			cin>>src>>dest>>cost;
			ada[src].pb({dest,cost});
			ada_rev[dest].pb({src,cost});
		}
		dijkstra(s,t);
		int ans=dist1[t];
		while(k--)
		{
			//these are two way roads
			int src,dest,cost;
			cin>>src>>dest>>cost;
			ans=min(ans,dist1[src]+cost+dist2[dest]);
			ans=min(ans,dist1[dest]+cost+dist2[src]);
		}
		// for(int i=1;i<t;i++)
		// 	cout<<dist1[i]<<" ";
		// cout<<endl;
		// for(int i=1;i<t;i++)
		// 	cout<<dist2[i]<<" ";
		if(ans==INF)
			cout<<-1<<endl;
		else
			cout<<ans<<endl;
		ada.clear();
		ada_rev.clear();


	}
	
}