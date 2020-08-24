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
const ll INF = LLONG_MAX;
const int MAXN = 110000;
int knight_moves[8][2]={{-2,-1},{-1,-2},{1,-2},{2,-1},{-2,1},{-1,2},{1,2},{2,1}};
int moves[4][2]={{0,1},{0,-1},{1,0},{-1,0}};
vector<pair<int,int>>ada[MAXN];
int par[MAXN];
int n;
int m;
ll dist[MAXN];
void dijsktra()
{
	memset(par,-1,sizeof(par));
	for(int i=1;i<=n;i++)
		dist[i]=INF;
	priority_queue<pair<ll,int>, vector<pair<ll, int>>, greater<pair<ll,int>>>pq;
	pq.push({0LL,1});
	dist[1]=0;
	while(!pq.empty())
	{
		ll curr_cost=pq.top().first;
		int parent=pq.top().second;
		pq.pop();
		for(auto children: ada[parent])
		{
			if(dist[children.first]>curr_cost+children.second)
			{
				dist[children.first]=curr_cost+children.second;
				pq.push({dist[children.first],children.first});
				par[children.first]=parent;
			}
		}
	}
}
vector<int> get_path()
{
	vector<int>res;
	int temp=n;
	res.pb(n);
	while(temp!=1)
	{
		res.pb(par[temp]);
		temp=par[temp];
	}
	reverse(res.begin(),res.end());
	return res;
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

	cin>>n>>m;
	for(int i=0;i<m;i++)
	{
		int x,y,cost;
		cin>>x>>y>>cost;
		ada[x].pb({y,cost});
		ada[y].pb({x,cost});
	}
	dijsktra();
	vector<int>path;
	if(dist[n]==LLONG_MAX)
	{
		cout<<-1;
	}
	else
		{
			vector<int>path=get_path();
			for(int i=0;i<path.size();i++)
				cout<<path[i]<<" ";
		}
	
}