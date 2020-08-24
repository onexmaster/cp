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
unordered_map<ll,vector<pair<ll,pair<ll,ll>>>>ada;
//dp[total_cost][vertex]=total_length
const int MAXN=1e5+5;
ll dp[MAXN][200];
void dijktras()
{
	ll coins,n,m;
	cin>>coins>>n>>m;
		while(m--)
		{
			ll u,v,l,t;
			cin>>u>>v>>l>>t;
			ada[u].pb({v,{l,t}});
		}
	for (ll i = 0; i <= 100001; i++)
        for (ll j = 0; j <= 200; j++)
            dp[i][j] = INT_MAX;
	ll ans=INT_MAX;
	//length,vertex,total_cost;
	priority_queue<pair<ll,pair<ll,ll>>, vector<pair<ll,pair<ll,ll>>>, greater<pair<ll,pair<ll,ll>>>>pq;
	pq.push({0,{1LL,0}});
	//to travel to 1 total_length is 0 and total cost is 0;
	dp[0][1]=0;
	while(!pq.empty())
	{
		ll curr_length=pq.top().first;
		ll curr_vertex=pq.top().second.first;
		ll curr_cost=pq.top().second.second;
		pq.pop();
		//cout<<curr_vertex<<" "<<curr_cost<<" "<<curr_length<<endl;
		//cout<<curr_vertex<<endl;
		//if we spent more money than we had
		if(curr_cost>coins)
			continue;
		if(n==curr_vertex && curr_cost<=coins)
		{
				//cout<<curr_vertex<<" "<<curr_cost<<" "<<curr_length<<endl; 
				ans=min(ans,curr_length);
				dp[curr_cost][curr_vertex]=curr_length;
		}
		
		//relax the edges
		for(auto edges:ada[curr_vertex])
		{
			ll new_cost=edges.second.second;
			ll new_length=edges.second.first;


			//edges.first -> to_vertex;
			//edges.first.first->length
			//edges.second.second->toll_cost;
			if(dp[curr_cost+new_cost][edges.first]>curr_length+new_length)
			{
				dp[curr_cost+new_cost][edges.first]=curr_length+new_length;
				pq.push({dp[curr_cost+new_cost][edges.first],{edges.first,curr_cost+new_cost}});
			}
		}
	}
	if(ans==INT_MAX)
			cout<<-1<<endl;
	else
		cout<<ans<<endl;

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
		dijktras();
		ada.clear();

	}
	
}