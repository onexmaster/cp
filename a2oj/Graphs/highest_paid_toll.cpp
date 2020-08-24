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
unordered_map<int,vector<pair<int,int>>>ada;
unordered_map<int,vector<pair<int,int>>>ada_rev;
int dist1[MAXN];
int dist2[MAXN];
void dijktras1(int src)
{
	priority_queue<pii, vector<pii>, greater<pii>>pq;
	pq.push({0,src});
	dist1[src]=0;
	while(!pq.empty())
	{
		int curr_cost=pq.top().first;
		int curr=pq.top().second;
		pq.pop();
		for(auto edges:ada[curr])
		{
			if(dist1[edges.first]>edges.second+curr_cost)
			{
				dist1[edges.first]=edges.second+curr_cost;
				pq.push({dist1[edges.first],edges.first});
			}
		}
	}
}
void dijktras2(int src)
{
	priority_queue<pii, vector<pii>, greater<pii>>pq;
	pq.push({0,src});
	dist2[src]=0;
	while(!pq.empty())
	{
		int curr_cost=pq.top().first;
		int curr=pq.top().second;
		pq.pop();
		for(auto edges:ada_rev[curr])
		{
			if(dist2[edges.first]>edges.second+curr_cost)
			{
				dist2[edges.first]=edges.second+curr_cost;
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
		ada.clear();
		ada_rev.clear();
		memset(dist1,INF,sizeof(dist1));
		memset(dist2,INF,sizeof(dist2));
		int n,m,src,dest,money;
		cin>>n>>m>>src>>dest>>money;
		while(m--)
		{
			int u,v,c;
			cin>>u>>v>>c;
			ada[u].pb({v,c});
			ada_rev[v].pb({u,c});
		}
		dijktras1(src);
		if(dist1[dest]==INF)
		{
			cout<<-1<<endl;
			continue;
		}
		dijktras2(dest);
		int ans=-1;
		for(int i=1;i<=n;i++)
		{
			if(ada.count(i)!=0)
			{
				for(auto edges:ada[i])
				{
					int cost=dist1[i]+edges.second+dist2[edges.first];
					//If there exists a paht from s->u and a path from v->d , then find the 
					//total cost of the total path i.e from s->u + u->v + v->d and if it is less than
					//total money then take the max od u->v edge from all edges
					if(cost<=money)
					{
						ans=max(ans,edges.second);
					}
				}
			}
		}
		cout<<ans<<endl;
	}
	
}