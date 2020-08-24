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
unordered_map<ll,vector<pair<ll,ll>>>ada;
int n,fuel_cap,src,dest;
unordered_map<ll,ll>parent;
unordered_map<ll,ll>cost;
unordered_set<ll>vis;
ll modified_bfs()
{
	//cost,city,fuel_state
	deque<pair<ll,pair<ll,ll>>>q;
	q.push_front({0,{src,fuel_cap}});
	//vis.insert(src);
	while(!q.empty())
	{
		ll curr_cost=q.front().first;
		ll curr_city=q.front().second.first;
		ll curr_fuel=q.front().second.second;
		q.pop_front();
		cout<<curr_city<<endl;
		if(curr_city==dest)
			return curr_cost;
		vis.insert(curr_city);
		for(auto edges:ada[curr_city])
		{
			//without refuling and i still i have fuel left
			if(edges.second==0 && curr_fuel>=1 && vis.find(edges.first)==vis.end())
			{
				q.push_front({curr_cost,{edges.first,curr_fuel-1}});
			}
			else if( vis.find(edges.first)==vis.end())
			{
				q.push_back({curr_cost+edges.second,{edges.first,fuel_cap}});
			}
		}
	}
	return -1;
}
void print_graph()
{
	for(auto it :ada)
	{
		cout<<it.first<<" ";
		for(auto it1:it.second)
			cout<<it1.first<<" "<<it1.second<<" ";
		cout<<endl;
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
		cin>>n>>fuel_cap>>src>>dest;
		for(int i=1;i<=n;i++)
		{
			ll par,fuel;
			cin>>par>>fuel;
			parent[i]=par;
			cost[i]=fuel;
		}
		//buil graph;
		for(int i=1;i<=n;i++)
		{
			int v=parent[i];
			int u=i;
			if(cost[u]!=0)
			{
				ada[u].pb({v,cost[u]});
				ada[u].pb({v,0});
				if(cost[v]!=0)
				{
					ada[v].pb({u,cost[v]});
					ada[v].pb({u,0});
				}
				else
					ada[v].pb({u,0});
			}	
			else
			{
				ada[u].pb({v,0});
				if(cost[v]!=0)
				{
					ada[v].pb({u,cost[v]});
					ada[v].pb({u,0});
				}
				else
					ada[v].pb({u,0});
			}
			
		}
		//print_graph();
		cout<<modified_bfs();
	}

	
}