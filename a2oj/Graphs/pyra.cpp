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
unordered_map<int,vector<int>>ada;
bool vis[MAXN];
int total_vol;
int dfs(int src)
{
	//cout<<src<<endl;
	vis[src]=true;
	//if leaf node 
	if(ada.count(src)==0)
	{
		total_vol++;
		return 1;
	}
	int children_length=0;
	int c=0;
	for(auto edges:ada[src])
	{
		if(!vis[edges])
		{
			children_length+=dfs(edges);
			c++;
		}
			
	}
	int toal_length=children_length+c+1;
	total_vol+=toal_length;
	return toal_length;
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
		int n;
		cin>>n;
		int m=n-1;
		while(m--)
		{
			int u,v;
			cin>>u>>v;
			ada[u].pb(v);
			ada[v].pb(u);
		}
		memset(vis,false,sizeof(vis));
		total_vol=0;
		dfs(0);
		cout<<total_vol<<endl;
		ada.clear();
	}
	
}