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
const int mxN=2e5;
int n;
ll a[mxN];
 //run kadanes algorithm
//if we add a new elem and the sum is <0 it means we are breaking the subarray here
ll mss(vector<ll> a) {
	ll ans=0, msf=0;
	for(ll b : a) {
		msf=max(msf+b, 0ll);
		ans=max(msf, ans);
	}
	return ans;
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
		cin >> n;
		ll s=0;
		//we can always get the answer which is at even pos
		for(int i=0; i<n; ++i) {
			cin >> a[i];
			if(i&1^1)
				s+=a[i];
		}
		vector<ll> b1, b2;
		//if we switch the 0th pos with 1 pos and so on..
		//run kadanes on it and find the answer of maximum subarray sum
		for(int i=0; i+1<n; i+=2)
			b1.push_back(a[i+1]-a[i]);
		//if we switch the 1st pos with the 2nd pos..3rd with 4 and so on
		//run kadanes and find the answer of max sub sum
		for(int i=1; i+1<n; i+=2)
			b2.push_back(a[i]-a[i+1]);
		//take the max of both
		cout << s+max({0ll, mss(b1), mss(b2)}) << "\n";
	}

}