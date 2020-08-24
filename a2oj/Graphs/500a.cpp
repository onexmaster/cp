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
const int MAXN=3e4+5;
bool vis[MAXN];
vector<int>ada[MAXN];
void dfs(int src)
{
	vis[src]=true;
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

	int n,m;
	cin>>n>>m;
	for(int i=0;i<n-1;i++)
	{
		int x;
		cin>>x;
		ada[i+1].pb(i+1+x);
	}
	dfs(1);
	if(!vis[m])
		cout<<"NO";
	else
		cout<<"YES";
	
}