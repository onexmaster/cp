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
const int Mod=1e9+7;
ll f(ll n) {
	return n/3;
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

	 int n,l,r;
	cin>>n>>l>>r;

	//for numbers divisble by 3
	ll n0 = f(r) - f(l - 1);
	ll n1 = f(r + 2) - f(l - 1 + 2);
	ll n2 = f(r + 1) - f(l - 1 + 1);

	//number of elements that are divisible by 3;
	vector<vector<ll> > dp(n,vector<ll>(3,0));
    dp[0][0] = n0, dp[0][1] = n1, dp[0][2] = n2;
 
    for(int i = 1 ; i < n ; i++)
    {
        dp[i][0] = ((dp[i-1][0]*n0)%Mod + (dp[i-1][1]*n2)%Mod + (dp[i-1][2]*n1)%Mod)%Mod;
        dp[i][1] = ((dp[i-1][1]*n0)%Mod + (dp[i-1][2]*n2)%Mod + (dp[i-1][0]*n1)%Mod)%Mod;
        dp[i][2] = ((dp[i-1][2]*n0)%Mod + (dp[i-1][0]*n2)%Mod + (dp[i-1][1]*n1)%Mod)%Mod;
    }

	cout<<dp[n-1][0];
}