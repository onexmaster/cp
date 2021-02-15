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
const int MOD=1e9+7;
ll binpow(ll a, ll b, ll m)
{
	//calulates a(^b)mod m
	 a%= m;
    long long res = 1;
    while (b > 0) {
        if (b & 1)
            res = res * a % m;
        a = a * a % m;
        b >>= 1;
    }
    return res;


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

	int n,q;
	cin>>n>>q;
	string st;
	cin>>st;
	vector<int>prefix_zeros(n,0);
	if(st[0]=='0')
		prefix_zeros[0]=1;
	for(int i=1;i<n;i++)
	{
		if(st[i]=='0')
			prefix_zeros[i]=prefix_zeros[i-1]+1;
		else
			prefix_zeros[i]=prefix_zeros[i-1];
	}
	while(q--)
	{
		ll start,end;
		cin>>start>>end;
		start--;
		end--;
		//need power under mod
		ll ans=binpow(2,end-start+1,MOD);
		//remove the number of zeros
		int ze=prefix_zeros[end]-(start==0?0:prefix_zeros[start-1]);
		ll ans2=binpow(2,ze,MOD);
		//the whole segment can be zero
		cout<<(ans-ans2+MOD)%MOD<<endl;
	}


}