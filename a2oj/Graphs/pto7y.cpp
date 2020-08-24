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
const int MAXN=1e4+5;
//vector<int>ada[MAXN];
vector<int>ada[MAXN];
bool vis[MAXN];
//vector<int>parent(MAXN,-1);
void dfs(int curr)
{
	vis[curr]=true;
	//cout<<curr<<endl;
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

	int n,m;
	cin>>n>>m;
	if(n-1!=m)
	{
		cout<<"NO"<<endl;
		return 0;
	}
	for(int i=0;i<m;i++)
	{
		int x,y;
		cin>>x>>y;
		ada[x].pb(y);
		ada[y].pb(x);
	}
	dfs(1);
	for(int i=1;i<=n;i++)
	{
		//cout<<vis[i]<<" ";
		 if(!vis[i])
		 {
		 	cout<<"NO"<<endl;
		 	return 0;
		 }
	}
		cout<<"YES"<<endl;
		return 0;

	
}