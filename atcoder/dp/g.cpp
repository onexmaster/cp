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

const int nax=1e5+10;
//This is like a 2d vector 
vector<int>edges[nax];
//find the max distance from ecah vertex this acts our dp array 
int dist[nax];
//visited array
bool visited[nax];

int dfs(int a)
{
	//if the vertex is visited then return thr max distance 
	if(visited[a])
		return dist[a];

	//mark a as visited 
	visited[a]=true;
	//visit the edges
	int ans=0;
	for(int b: edges[a])
	{
		//find the max distance from each child node and update the answer
			ans=max(ans,dfs(b)+1);
	}
	return dist[a]=ans;

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
	for(int i=1;i<=m;i++)
	{
		int a,b;
		cin>>a>>b;
		edges[a].pb(b);
	}
	//run dfs from each edge and fill the distance value
	int ans=0;
	for(int i=1;i<=n;i++)
			ans=max(ans,dfs(i));
	//find the answer
	cout<<ans;
}