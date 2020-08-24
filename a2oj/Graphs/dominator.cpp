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
const int MAXN=105;
unordered_map<int,vector<int>>ada;
map<int,set<int>>par;
bool vis[MAXN];
void dfs(int src, int parent)
{
	vis[src]=true;
	par[src].insert(parent);
	for(auto edges:ada[src])
		if(!vis[edges])
			dfs(edges,src);
	vis[src]=false;

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
		int n;
		cin>>n;
		for(int i=0;i<n;i++)
		{
			for(int j=0;j<n;j++)
			{
				int x;
				cin>>x;
				if(x==1)
				{
					ada[i].pb(j);
				}
			}
		}
		dfs(0,-1);
		for(int i=0;i<n;i++)
		{
			cout<<i<<" "<<par[i].size()<<endl;
		}
		cout<<endl;
		par.clear();
		ada.clear();
	}
	
}