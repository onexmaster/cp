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
struct custom_hash {
    static uint64_t splitmix64(uint64_t x) {
        // http://xorshift.di.unimi.it/splitmix64.c
        x += 0x9e3779b97f4a7c15;
        x = (x ^ (x >> 30)) * 0xbf58476d1ce4e5b9;
        x = (x ^ (x >> 27)) * 0x94d049bb133111eb;
        return x ^ (x >> 31);
    }

    size_t operator()(uint64_t x) const {
        static const uint64_t FIXED_RANDOM = chrono::steady_clock::now().time_since_epoch().count();
        return splitmix64(x + FIXED_RANDOM);
    }
};
const int MAXN=2e5+5;
vector<int>ada[MAXN];
bool vis[MAXN];
int det[MAXN];
int depth[MAXN];
int sz[MAXN];
int cmp(int a,int b){return a>b;}
int dfs(int src, int par)
{
	depth[src]=depth[par]+1;
	sz[src]=1;
	for(auto edges:ada[src])
	{
		if(edges==par)
			continue;
		sz[src]+=dfs(edges,src);
	}
	det[src]=sz[src]-depth[src];
	return sz[src];
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

	int n,k;
	cin>>n>>k;
	for(int i=0;i<n-1;i++)
	{
		int u,v;
		cin>>u>>v;
		ada[u].pb(v);
		ada[v].pb(u);
	}
	dfs(1,0);
	//sort(det,det+n);
	//reverse(det,det+n);
	ll ans=0;
	std::nth_element(det+1,det+n-k,det+n+1,cmp);
	//for(int i=1;i<=n;i++)
	//	cout<<det[i]<<" ";
	//cout<<endl;
	for(int i=1;i<=n-k;i++)
		ans+=det[i];
	cout<<ans;
	



}