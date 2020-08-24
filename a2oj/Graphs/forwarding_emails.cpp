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
const int MAXN=5e4+5;
bool vis[MAXN];
int ada[MAXN];
//dp stores the cycle length of visited nodes
int dp[MAXN];
//we have only 1 children for each node hence ada is a int[]
//regular dfs does not work and results in a tle
int dfs(int src)
{
	cout<<src<<endl;
	vis[src]=true;
	int ans=1;
	int edges=ada[src];
		if(!vis[edges])
			ans=dfs(edges)+1;
		//change it to false coz some other vertex might lead to already visited vertex
	vis[src]=false;
	return dp[src]=ans;
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
	int x=1;
	while(t--)
	{
		memset(vis,false,sizeof(vis));
		memset(dp,0,sizeof(dp));
		memset(ada,0,sizeof(ada));
		int n;
		cin>>n;
		int max_nodes=-1;
		int ans=-1;
		for(int i=0;i<n;i++)
		{
			int u,v;
			cin>>u>>v;
			ada[u]=v;
			//ada[v].pb(u);
		}
		for(int i=1;i<=n;i++)
		{
			if(dp[i]==0)
			{
				dfs(i);
				if(dp[i]>max_nodes)
				{
					max_nodes=dp[i];
					ans=i;
				}
			}

		}
		// for(auto it:dp)
		// 	cout<<it.first<<" "<<it.second<<endl;
		cout<<"Case "<<x<<": "<<ans<<endl;
		x++;
		

	}
	
}