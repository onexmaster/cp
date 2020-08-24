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
int n,m;
int is_cat[MAXN];
vector<int> ada[MAXN];
int ans;
void dfs(int curr, int parent, int cats)
{
	//if the current node has a cat
	cats=cats+is_cat[curr];
	//if it does not have a cat then reset the cats
	if(is_cat[curr]==0)
		cats=0;
	//if the cats exceeds m 
	if(cats>m)
		return;
	//if still less than m and then find the value for its children
	int total_children=0;
	for(auto edges:ada[curr])
	{
		if(edges==parent)
			continue;
		total_children++;
		dfs(edges,curr,cats);
	}
	//if it is a leaf node and if cats is less than m then add it in answer
	if(total_children==0)
		ans++;
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

	cin>>n>>m;
	for(int i=0;i<n;i++)
	{
		cin>>is_cat[i];
	}
	for(int i=0;i<n-1;i++)
	{
		int src,dest;
		cin>>src>>dest;
		src--;
		dest--;
		ada[src].pb(dest);
		ada[dest].pb(src);
	}
	ans=0;
	dfs(0,-1,0);
	cout<<ans;
}