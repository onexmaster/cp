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

	string s,t;
	cin>>s>>t;
	int s0=0,s1=0,t0=0,t1=0;
	for(int i=0;i<s.size();i++)
		if(s[i]=='1')
			s1++;
		else
			s0++;
	for(int i=0;i<t.size();i++)
		if(t[i]=='1')
			t1++;
		else
			t0++;
		//cout<<s1<<" "<<s0<<" "<<t1<<" "<<t0<<endl;
		if(t1>s1 || t0>s0)
		{
			cout<<s;
			return 0;
		}
		else
		{
			int x;
			if(t1!=0 && s1!=0)
			x=min(s1/t1, s0/t0);
			else if(t1==0)
				x=s0/t0;
			else if(t0==0)
				x=s1/t1;
			cout<<x<<endl;
			string ans=t;
			int i=1;
			while(i<x)
				ans+=t,i++;
			//cout<<ans<<endl;
			int rem1=s1-x*t1;
			int rem0=s0-x*t0;
			for(int j=0;j<rem1;j++)
				ans+="1";
			for(int j=0;j<rem0;j++)
				ans+="0";
			cout<<ans;
			return 0;


		}

}