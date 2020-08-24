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
const int MAXN=1e5+5;
vector<int>ada[MAXN];
int dp[MAXN][2];
bool vis[MAXN];
void dfs(int u, int p)
{
	//cosider u in the vertex set
	dp[u][1]=1;
	//do not consider u in vertex set
	dp[u][0]=0;
	//mark this node as visited
	vis[u]=true;
	//for its children 
	for(auto children : ada[u])
	{
		if(!vis[children])
		{
			//get the answer for this children
			dfs(children,u);
			//if i am not considering the curr vertex in the set, then i need the consider the children in the set
			//hence use the value of dp[children][1]
			// 1- means included in the set;
			dp[u][0]+=dp[children][1];
			//if i am considering the curr vertex in the set, then i may or may not need its children in the set
			dp[u][1]+=min(dp[children][0],dp[children][1]);
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

	int t;
	cin>>t;
	for(int i=0;i<t;i++)
	{
		int x,y;
		cin>>x>>y;
		ada[x].pb(y);
		ada[y].pb(x);
	}
	memset(vis,false,sizeof(vis));
	dfs(1,0);
	cout<<min(dp[1][0],dp[1][1]);
	
}