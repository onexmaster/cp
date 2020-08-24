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
	map<pii,int>cnt;
	int ans=0;
	while(t--)
	{
		string st1;
		cin>>st1;
		int counter=0;
		stack<char>st;
		int open=0;
		int close=0;
		for(int i=0;i<st1.size();i++)
		{
			if(st.empty() && st1[i]==')')
				close++;
			else if(st1[i]=='(')
				st.push(st1[i]);
			else if(!st.empty() && st1[i]==')')
				st.pop();
		}
		if(st.size()>0)
			open+=int(st.size());
		cnt[{close,open}]++;
	}
	set<pii>vis;
	for(auto it:cnt)
	{
		//cout<<it.first.first<<" "<<it.first.second<<" "<<it.second<<endl;
		if(it.first.first==0 && it.first.second==0)
			ans+=it.second/2;
		else
		{

			//3,0 can match with 0,3 and 1,2 cannot match with 2,1 coz of we cannot change the ordering 
			if(it.first.first==0 && it.first.second>0 || it.first.first>0 && it.first.second==0)
			{
				if(cnt.count({it.first.second,it.first.first})!=0 && vis.find({it.first.second,it.first.first})==vis.end())
				{
					ans+=min(cnt[{it.first.second,it.first.first}],cnt[{it.first.first,it.first.second}]);
					vis.insert({it.first.first,it.first.second});
				}
			}
			
		}
	}
	cout<<ans;

}