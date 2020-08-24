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
vector<int>need;
vector<int>have;
ll n,k;
bool is_poss(ll cookies)
{
	ll temp_k=k;
	for(int i=0;i<n;i++)
	{
		//cout<<have[i]<<" "<<cookies*need[i]<<endl;
		if(have[i]<(cookies*need[i]))
		{
			//try to use the magic powder
			if(temp_k==0)
				return false;
			if((cookies*need[i])-have[i]<=temp_k)
			{
				temp_k-=(cookies*need[i]-have[i]);
			}
			else
				return false;
		}
	}
	return true;
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
	for(int i=0;i<n;i++)
	{
		ll x;
		cin>>x;
		need.pb(x);
	}
	for(int i=0;i<n;i++)
	{
		ll x;
		cin>>x;
		have.pb(x);
	}
	ll l=0;
	ll h=10000000000;
	ll ans=0;
	while(l<=h)
	{
		ll mid=l+(h-l)/2;
		if(is_poss(mid))
		{
			ans=mid;
			l=mid+1;
		}
		else
			h=mid-1;
	}
	cout<<ans;

}