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
vector<int>ada[MAXN];

double dfs(int src,int parent)
{
	double ans=0;
	int c=0;
	for(auto edges:ada[src])
	{
		if(edges==parent)
			continue;
		else
		{
			ans+=(1+dfs(edges,src));
			c++;
		}
	}
	if(c==0)
		return 0;
	return ans/c;	
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
		int u,v;
		cin>>u>>v;
		ada[u].pb(v);
		ada[v].pb(u);
	}
	//ans=0.0;
	//prob[1]=1;
	//cout<<dfs(1,-1);
	// // //cout<<total_nodes<<endl;
	// // for(int i=1;i<=t;i++)
	// // 	cout<<prob[i]<<" ";
	// cout<<endl;
	cout<<setprecision(15)<<fixed<<dfs(1,0)<<endl;
}