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
const int MAXN=1e5+5;
vector<int>ada[MAXN];
int vis[MAXN];
bool cycle;
vector<int>courses;
void dfs(int src)
{
	//cout<<src<<endl;
	if(vis[src]==0)
	{
		vis[src]=1;
		for(auto edges:ada[src])
			dfs(edges);
		vis[src]=2;
		courses.pb(src);
	}
	else if(vis[src]==1)
		cycle=true;
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
	vector<int>mainc(k);
	for(int i=0;i<k;i++)
		cin>>mainc[i];

	for(int i=0;i<n;i++)
	{
		int x;
		cin>>x;
		int u=i+1;
		while(x--)
		{
			int v;
			cin>>v;
			//cout<<v<<endl;
			ada[u].pb(v);
		}
	}
	cycle=false;
	//run dfs on main first;
	for(int i=0;i<k;i++)
	{
		//cout<<mainc[i]<<" ";
		if(!vis[mainc[i]])
			dfs(mainc[i]);
	}
	if(cycle)
		cout<<-1;
	else
	{
		cout<<courses.size()<<endl;
		for(auto a:courses)
			cout<<a<<" ";
	}
	return 0;
}