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
const int MAXN=1e2+5;
vector<int>ada[MAXN];
bool vis[MAXN];
void dfs(int curr)
{
	//cout<<curr<<endl;
	vis[curr]=true;
	for(auto edges:ada[curr])
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

	//chintu is a tree with one extra edge 
	//a tree is connected and has n-1 edges 
	//but here we need to check if the tree is connected or and not and it should have n=m edges
	int n,m;
	cin>>n>>m;
	if(n!=m)
	{
		cout<<"NO";
		return 0;
	}
	while(m--)
	{
		int u,v;
		cin>>u>>v;
		ada[u].pb(v);
		ada[v].pb(u);
	}
	memset(vis,false,sizeof(vis));
	dfs(1);
	bool ok=true;
	for(int i=1;i<=n;i++)
	{
		if(!vis[i])
		{
			//cout<<i<<" "<<"here"<<endl;
			ok=false;
		}
	}
	if(ok==false)
		cout<<"NO";
	else
		cout<<"FHTAGN!";
}