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
 
	int t;
	cin>>t;
	while(t--)
	{
		ll n,k;
		cin>>n>>k;
		vector<ll>v(n);
		for(int i=0;i<n;i++)
			cin>>v[i];
		unordered_set<ll,custom_hash>st;
		//last multiple used by elemt key;
		unordered_map<ll,ll,custom_hash>last_used;
		for(int i=0;i<n;i++)
		{
			ll num=v[i];
			if(num>k && num%k!=0)
			{
				ll j;
				if(last_used.count(num)!=0)
				{
					for(j=last_used[num];j<=LLONG_MAX;j+=k)
					{
						ll diff=j-num;
						if(diff>0 && st.find(diff)==st.end())
						{
							st.insert(diff);
							last_used[num]=j;
							break;
						}
					}
				}
				else
				{
					for(j=k*2;j<=LLONG_MAX;j+=k)
					{
						ll diff=j-num;
						if(diff>0 && st.find(diff)==st.end())
						{
							st.insert(diff);
							last_used[num]=j;
							break;
						}
					}	
				}
				
 
			}
			else if(num<k && num%k!=0)
			{
				ll j;
				if(last_used.count(num)!=0)
				{
					for(j=last_used[num];j<=LLONG_MAX;j+=k)
					{
						ll diff=j-num;
						if(diff>0 && st.find(diff)==st.end())
						{
							st.insert(diff);
							last_used[num]=j;
							break;
						}
					}
				}
				else
				{
					for(j=k*((num/k)+1);j<=LLONG_MAX;j+=k)
					{
						ll diff=j-num;
						if(diff>0 && st.find(diff)==st.end())
						{
							st.insert(diff);
							last_used[num]=j;
							break;
						}
					}	
				}
			}
 
		}
		ll ans=0;
		for(auto it:st)
			ans=max(ans,it);
		if(ans==0)
			cout<<ans<<endl;
		else
			cout<<++ans<<endl;
	}
	
}