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
const int MAXN=1e5+5;
vector<pair<int,bool>>ada[MAXN];
bool mark[MAXN];
vector<int>ans;
bool dfs(int src, int par, bool prob)
{
	bool ret=0;
	for(auto edges:ada[src])
	{
		bool isp=edges.second;
		if(edges.first!=par)
		{
			ret|=dfs(edges.first,src,isp);
		}
	}
	//if a nodes subtree does not have any problem , but the node istelf had a bad edges while comeing 
	//then it must be included in the answer
	if(!ret && prob)
	{
		mark[src]=1;
		ret=1;
	}
	return ret;
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
	for(int i=0;i<t-1;i++)
	{
		int u,v,type;
		cin>>u>>v>>type;
		type--;
		ada[u].pb({v,type});
		ada[v].pb({u,type});
	}
	dfs(1,-1,0);
	int count=0;
	for(int i=1;i<=t;i++)
		if(mark[i])
			count++;
	cout<<count<<endl;
	for(int i=1;i<=t;i++)
		if(mark[i])
			cout<<i<<" ";
	
}