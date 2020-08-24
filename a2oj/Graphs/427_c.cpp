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
const int mod=1e9+7;
const int MAXN=1e5+5;
vector<int>ada[MAXN];
vector<vector<int>>scc;
bool on_stack[MAXN];
int disc_time[MAXN];
int low_link[MAXN];
int foundat=1;
void tarjan(int u)
{
	static stack<int>st;

	low_link[u]=disc_time[u]=foundat++;
	on_stack[u]=true;
	st.push(u);
	for(auto v:ada[u])
	{
		if(disc_time[v]==-1)
		{
			tarjan(v);
			low_link[u]=min(low_link[u],low_link[v]);
		}
		//if back edge
		else if(on_stack[v])
			low_link[u]=min(low_link[u],disc_time[v]);
	}
	//find an scc
	if(disc_time[u]==low_link[u])
	{
		vector<int>temp;
		while(1)
		{
			int curr=st.top();
			st.pop();
			temp.pb(curr);
			on_stack[curr]=false;
			if(curr==u)
				break;
		}
		scc.pb(temp);
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
	int cost[t];
	for(int i=0;i<t;i++)
		cin>>cost[i];
	int m;
	cin>>m;
	while(m--)
	{
		int u,v;
		cin>>u>>v;
		u--;
		v--;
		ada[u].pb(v);
	}
	memset(disc_time,-1,sizeof(disc_time));
	memset(low_link,-1,sizeof(low_link));
	memset(on_stack,false,sizeof(on_stack));
	for(int i=0;i<t;i++)
		if(disc_time[i]==-1)
			tarjan(i);
		//scc now holds all the strongly coneected components
		//to find then min cost-
		//take each component and use the vertex which has the minimum cost
		//cout<<scc.size()<<endl;
		ll min_cost=0;
		ll ways=1;
		for(auto v:scc)
		{
			//maps the minumum cost of that scc and also its freq
			map<ll,ll>freq;
			for(auto nos:v)
			{
				freq[cost[nos]]++;
			}
			auto it=freq.begin();
			min_cost+=it->first;
			ways=ways*(it->second)%mod;
		}

		cout<<min_cost<<" "<<ways<<endl;


	
}