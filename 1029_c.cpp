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
int main()
{
	ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

	#ifndef ONLINE_JUDGE
	freopen("inputf.in","r",stdin);
	freopen("outputf.in","w",stdout);
	#endif

	int n;
	cin>>n;
	vector<pii>v(n);
	for(int i=0;i<n;i++)
		cin>>v[i].first>>v[i].second;
	//stores the prefix and suffix intersection
	vector<pii>prefix(n),suffix(n);
	prefix[0].first=v[0].first;
	prefix[0].second=v[0].second;
	for(int i=1;i<n;i++)
	{
		prefix[i].first=max(prefix[i-1].first,v[i].first);
		prefix[i].second=min(prefix[i-1].second,v[i].second);
	}
	suffix[n-1].first=v[n-1].first;
	suffix[n-1].second=v[n-1].second;
	for(int i=n-2;~i;i--)
	{
		suffix[i].first=max(suffix[i+1].first,v[i].first);
		suffix[i].second=min(suffix[i+1].second,v[i].second);
	}
	int ans=0;
	//to skip the first segment the answer is in suffix[1];
	ans=max(ans,suffix[1].second-suffix[1].first);
	//to skip the last segment the answer is in prefix[n-1];
	ans=max(ans,prefix[n-2].second-prefix[n-2].first);
	//for the rest the answer is in prefix[i-1] and suffix[i+1]
	for(int i=1;i<n-1;i++)
	{
		ans=max(ans,min(prefix[i-1].second,suffix[i+1].second) - max(prefix[i-1].first,suffix[i+1].first));
	}
	cout<<ans;
	return 0;
}