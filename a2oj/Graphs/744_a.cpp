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
const int MAXN=1e3+5;
vector<int>ada[MAXN];
bool vis[MAXN];
int no_count;
void dfs(int src)
{
	vis[src]=true;
	no_count++;
	for(auto edges:ada[src])
		if(!vis[edges])
			dfs(edges);
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

	int n,m,k;
	cin>>n>>m>>k;
	vector<int>gov;
	for(int i=0;i<k;i++)
	{
		int x;
		cin>>x;
		gov.pb(x);
	}
	for(int i=0;i<m;i++)
	{
		int u,v;
		cin>>u>>v;
		ada[u].pb(v);
		ada[v].pb(u);
	}
	memset(vis,false,sizeof(vis));
	vector<int>comps;
	for(int i=0;i<gov.size();i++)
	{
		no_count=0;
		dfs(gov[i]);
		comps.pb(no_count);
	}
	sort(comps.begin(),comps.end());


	ll ans=0;
	ll here;
	int taken=0;
	for(int i=0;i<comps.size();i++)
	{
		taken+=comps[i];
	}
	//this stores all the nodes which can used to make the connection at the ed of the vector
	//a.k.a The largest component + the unsed nodes(non-special nodes)
	comps[comps.size()-1]+=n-taken;


	//for all the connected components calculate the max edges which we can add
	for(int i=0;i<comps.size();i++)
	{
		here=1ll*comps[i]*(comps[i]-1)/2;
		ans+=here;
	}
	//subtract the already present edges.
	cout<<ans-m<<endl;
	
}