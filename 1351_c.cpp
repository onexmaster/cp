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
		string st1;
		cin>>st1;
		set<pair<pii,pii>>used;
		ll ans=0;
		ll x1=0,y1=0;
		for(int i=0;i<st1.size();i++)
		{
			ll x2=x1,y2=y1;
			if(st1[i]=='N')
				y2++;
			else if(st1[i]=='S')
				y2--;
			else if(st1[i]=='E')
				x2++;
			else
				x2--;
			if(used.find({{x1,y1},{x2,y2}})!=used.end())
				ans+=1;
			else
			{
				ans+=5;
				used.insert({{x1,y1},{x2,y2}});
				used.insert({{x2,y2},{x1,y1}});
			}
			x1=x2;
			y1=y2;
		}
		cout<<ans<<endl;
	}


}