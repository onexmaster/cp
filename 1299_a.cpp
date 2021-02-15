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

	ll n;
	cin >> n;
	ll ar[n];
	for (ll i = 0; i < n; i++)
		cin >> ar[i];
 
	if (n == 1)
	{cout << ar[0]; return 0;}
 
	ll pos = 0;
	ll pre[n];
	ll suff[n];
 
	pre[0] = ~ar[0];
	for (ll i = 1; i < n; i++)
	{
		pre[i] = (~ar[i] & pre[i - 1]);
	}
	suff[n - 1] = ~ar[n - 1];
	for (ll i = n - 2; i >= 0; i--)
	{
		suff[i] = (~ar[i] & suff[i + 1]);
	}
	ll maxi = ar[0] & suff[1];
	for (ll i = 1; i < n - 1; i++)
	{
 
		ll val = (pre[i - 1] & suff[i + 1])& ar[i];
		if (val >= maxi)
		{	maxi = val;
			pos = i;
		}
	}
	cout << endl;
	if ((pre[n - 2]&ar[n - 1]) > maxi)
		pos = n - 1;
 
	swap(ar[0], ar[pos]);
 
	for (ll i = 0; i < n; i++)
		cout << ar[i] << " ";
	cout << endl;
 
	return 0;
 

}