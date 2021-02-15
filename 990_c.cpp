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
int get_bal(string s)
{
	int bal=0;
	for(int i=0;i<s.size();i++)
	{
		if(s[i]=='(')
			bal++;
		else
			bal--;
		if(bal<0)
			return -1;
	}
	return bal;
}
string rev(string s)
{
	string rev=s;
	reverse(rev.begin(),rev.end());
	for(int i=0;i<rev.size();i++)
		if(rev[i]=='(')
			rev[i]=')';
		else
			rev[i]='(';
	return rev;
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
	vector<string>v(t);
	for(int i=0;i<t;i++)
		cin>>v[i];
	map<int,int>cnt;
	for(int i=0;i<t;i++)
	{
		int bal=get_bal(v[i]);
		if(bal!=-1)
			cnt[bal]++;
	}
	ll ans=0;
	for(int i=0;i<t;i++)
	{
		v[i]=rev(v[i]);
		int bal=get_bal(v[i]);
		if(bal!=-1)
			ans+=cnt[bal];
	}
	cout<<ans<<endl;
}