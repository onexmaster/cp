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
		int n;
		cin>>n;
		vector<int>v(n+1);
		map<int,int>cnt;
		for(int i=1;i<=n;i++)
		{
			cin>>v[i];
			cnt[v[i]]++;
		}
		set<int>full(v.begin()+1,v.end());
		set<int>curr_set;
		vector<pii>ans;
		int res=0;
		for(int i=1;i<n;i++)
		{
			int cur_ele=v[i];
			curr_set.insert(cur_ele);
			--cnt[cur_ele];
			if(cnt[cur_ele]==0)
			{
				cnt.erase(cur_ele);
				full.erase(cur_ele);
			}
			//print the sets 
			// cout<<"Iter:"<<i<<endl;
			// for(auto it:curr_set)
			// 	cout<<it<<" ";
			// cout<<endl;
			// for(auto it:full)
			// 	cout<<it<<" ";
			// cout<<endl;
			// cout<<"CURR SET"<<endl;
			// cout<<*curr_set.rbegin()<<endl;
			// cout<<"FULL SET"<<endl;
			// cout<< full.size()<<" " <<*full.begin()<<" "<<*full.end()<<endl;
			if(curr_set.size()==i && *curr_set.begin()==1 && *curr_set.rbegin()==i 
				&& full.size()==n-curr_set.size() && *full.begin()==1 && *full.rbegin()==n-curr_set.size())
			{
				res++;
				ans.pb({i,n-i});
			}
		}
		cout<<res<<endl;
		for(int i=0;i<ans.size();i++)
			cout<<ans[i].first<<" "<<ans[i].second<<endl;
	}

}