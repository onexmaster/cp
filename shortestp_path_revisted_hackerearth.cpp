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
struct custom_hash {
    static uint64_t splitmix64(uint64_t x) {
        // http://xorshift.di.unimi.it/splitmix64.c
        x += 0x9e3779b97f4a7c15;
        x = (x ^ (x >> 30)) * 0xbf58476d1ce4e5b9;
        x = (x ^ (x >> 27)) * 0x94d049bb133111eb;
        return x ^ (x >> 31);
    }

    size_t operator()(uint64_t x) const {
        static const uint64_t FIXED_RANDOM = chrono::steady_clock::now().time_since_epoch().count();
        return splitmix64(x + FIXED_RANDOM);
    }
};
const int MAXN=1e5+5;
unordered_map<int,vector<pii>>ada;
ll dist[MAXN][20];
int n,m,k;
void dijktars()
{
	for(int i=0;i<MAXN;i++)
		for(int j=0;j<20;j++)
			dist[i][j]=LLONG_MAX;
		//dist,vertex,k
	priority_queue<pair<int,pair<int,int>>,vector<pair<int,pair<int,int>>>, greater<pair<int,pair<int,int>>>>pq;
	pq.push({0,{1,0}});
	dist[1][0]=0;
	while(!pq.empty())
	{
		int curr_node=pq.top().second.first;
		int curr_cost=pq.top().first;
		int curr_k=pq.top().second.second;
		pq.pop();
		//cout<<curr_node<<endl;
		for(auto edges:ada[curr_node])
		{
			//if use wildacrd here
			if(curr_k<=k)
			{
				if(dist[edges.first][curr_k+1]>curr_cost)
				{
					
					dist[edges.first][curr_k+1]=curr_cost;
					pq.push({curr_cost,{edges.first,curr_k+1}});
				}
			}
			//if i cannot use wildcard or i dont use wildcared here
			if(dist[edges.first][curr_k]>edges.second+curr_cost)
			{
				dist[edges.first][curr_k]=edges.second+curr_cost;
				pq.push({dist[edges.first][curr_k],{edges.first,curr_k}});
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


	cin>>n>>m>>k;
	while(m--)
	{
		int u,v;
		ll cost;
		cin>>u>>v>>cost;
		ada[u].pb({v,cost});
		ada[v].pb({u,cost});
	}
	dijktars();
	for(int i=1;i<=n;i++)
	{
		ll ans=LLONG_MAX;
		for(int j=0;j<=k;j++)
			ans=min(ans,dist[i][j]);
		cout<<ans<<" ";
	}

}