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
const int MAXN=1e3+5;
int degree[MAXN];
unordered_map<int,vector<int>>ada;
bool vis[MAXN];
//int children[MAXN];
int dfs(int src)
{
	//cout<<src<<endl;
	vis[src]=true;
	bool leaf=true;
	int total_nodes=0;
	for(auto edges:ada[src])
	{
		if(!vis[edges])
		{
			leaf=false;
			total_nodes+=dfs(edges);
		}
	}
	if(leaf)
		return 1;
	return total_nodes+1;
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
	while(t--)
	{
		ada.clear();
		memset(degree,0,sizeof(degree));
		memset(vis,false,sizeof(vis));
		int n,k;
		cin>>n>>k;
		for(int i=0;i<n-1;i++)
		{
			int u,v;
			cin>>u>>v;
			degree[u]++;
			degree[v]++;
			ada[u].pb(v);
			ada[v].pb(u);
		}
		if(degree[k]<=1)
			cout<<"Ayush"<<endl;
		else
		{
			int nodes=dfs(k);
			//cout<<nodes<<endl;
			nodes-=2;
			if(nodes%2==0)
				cout<<"Ayush"<<endl;
			else
				cout<<"Ashish"<<endl;
		}
	}

}