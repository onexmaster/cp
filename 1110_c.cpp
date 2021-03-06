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
set<ll>get_factors(ll n)
{
	set<ll>factors;
	//cout<<n<<endl;
	while(n%2==0)
	{
		n/=2;
		factors.insert(2);
	}
	for(int i=3;i<=sqrt(n);i+=2)
	{
		while(n%i==0)
		{
			n/=i;
			factors.insert(i);
		}
	}
	if(n>2)
		factors.insert(n);
	return factors;
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
		ll n;
		cin>>n;
		string s;
		ll temp=n;
		while(temp>0)
		{
			if(temp&1)
				s+='0';
			else
				s+='1';
			temp>>=1; 
		}
		reverse(s.begin(),s.end());
		ll rev=stoll(s,nullptr,2);
		//cout<<rev<<endl;
		if(rev==0LL)
		{
			//divide by the smallest prime factors of the number
			set<ll>fact=get_factors(n);
			ll ans=n/(*fact.begin());
			cout<<ans<<endl;
		}
		else
			cout<<(n^rev)<<endl;
		
	}

}