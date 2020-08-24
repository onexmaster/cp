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
bool vis[MAXN];
unordered_map<int,vector<int>>ada;
int fall;
void dfs(int src)
{
	fall++;
	vis[src]=true;
	for(auto v:ada[src])
	{
		if(!vis[v])
			dfs(v);
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
		memset(vis,false,sizeof(vis));
		int n,m,l;
		cin>>n>>m>>l;
		while(m--)
		{
			int u,v;
			cin>>u>>v;
			ada[u].pb(v);
		}
		int total_count=0;
		while(l--)
		{
			int src;
			cin>>src;
			if(!vis[src])
			{
				fall=0;
				dfs(src);
				total_count+=fall;
			}
			
		}
		cout<<total_count<<endl;
		ada.clear();
	}
	
}