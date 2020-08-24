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
int dijkstras(int start, int end, unordered_map<int,vector<pair<int,int>>>&ada)
{
	int dist[MAXN];
	memset(dist,200005,sizeof(dist));
	dist[start]=0;
	priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>>pq;
	pq.push({0,start});
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
	return dist[end];
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
		unordered_map<string,int>city;
		int n;
		cin>>n;
		int x=1;
		unordered_map<int,vector<pair<int,int>>>ada;
		while(x<=n)
		{
			string name;
			cin>>name;
			city[name]=x;
			int m;
			cin>>m;
			while(m--)
			{
				int a,cost;
				cin>>a>>cost;
				ada[x].pb({a,cost});
			}
			x++;
		}
		int test_cases;
		cin>>test_cases;
		while(test_cases--)
		{
			string start,end;
			cin>>start>>end;
			cout<<dijkstras(city[start],city[end], ada)<<endl;
		}

	}
	
}