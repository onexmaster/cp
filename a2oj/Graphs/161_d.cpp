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
struct HASH{
  size_t operator()(const pair<int,int>&x)const{
    return hash<long long>()(((long long)x.first)^(((long long)x.second)<<32));
  }
};
unordered_set<pair<int,int>,HASH>found;
unordered_map<int,int>dist;
vector<int>ada[MAXN];
int n,k;
void bfs(int src)
{
	dist.clear();
	queue<int>q;
	q.push(src);
	dist[src]=0;
	while(!q.empty())
	{
		int curr=q.front();
		q.pop();
		if(dist[curr]>k)
			return;
		if(dist[curr]==k && found.find({curr,src})==found.end())
			found.insert({src,curr});

		for(auto edges:ada[curr])
		{
			if(dist.count(edges)==0)
			{
				q.push(edges);
				dist[edges]=dist[curr]+1;
			}
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


	cin>>n>>k;
	for(int i=0;i<n-1;i++)
	{
		int u,v;
		cin>>u>>v;
		ada[u].pb(v);
		ada[v].pb(u);
	}
	for(int i=1;i<=n;i++)
		bfs(i);
	// for(auto it:found)
	// {
	// 	cout<<it.first<<" "<<it.second<<endl;
	// }
	cout<<found.size();
}