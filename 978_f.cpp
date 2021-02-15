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
int res[MAXN];
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
	vector<pii>v(n);
	map<int,int>freq;
	for(int i=0;i<n;i++)
	{
		cin>>v[i].first;
		v[i].second=i;
		freq[v[i].first]++;
	}
	vector<pii>temp(n);
	temp=v;
	for(int i=0;i<k;i++)
	{
		int u,v;
		cin>>u>>v;
		u--;
		v--;
		ada[u].pb(v);
		ada[v].pb(u);
	}
	sort(v.begin(),v.end(),greater<pii>());
	for(int i=0;i<n;i++)
	{
		int curr=v[i].first;
		int ans=n-i-1;
		int idx=v[i].second;
		
		if(freq[curr]>1)
		{
			ans-=(freq[curr]-1);
		}
		//cout<<curr<<" "<<ans<<" "<<idx<<endl;
		//remove all the pairs than have a quarell with the current idx;
		for(auto quarell:ada[idx])
		{
			//cout<<quarell<<" "<<temp[quarell].first<<endl;
			if(temp[quarell].first<curr)
			{
				//cout<<"HERE"<<endl;
				ans--;
			}
		}
		--freq[curr];
		res[idx]=ans;
	}
	for(int i=0;i<n;i++)
		cout<<res[i]<<" ";





}