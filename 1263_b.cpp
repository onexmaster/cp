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
		vector<string>strings;
		unordered_set<string>taken;
		vector<pair<string,string>>res;
		//map<int,string>mps;
		int dups;
		while(n--)
		{
			string st1;
			cin>>st1;
			//strings.pb(st1);
			if(taken.count(st1)==0)
			{
				taken.insert(st1);
				res.pb({st1,st1});
			}
			else
			{
				dups++;
				res.pb({st1,""});
				//dups.pb(st1);
			}
		}
		if(dups==0)
		{
			cout<<0<<endl;
			for(auto it:res)
				cout<<it.first<<endl;
			continue;
		}
		int ans=0;
		for(int i=0;i<res.size();i++)
		{
			if(res[i].second=="")
			{
				string temp=res[i].first;
				bool ok=false;
				for(int k=0;k<4;k++)
				{
					for(int j='0';j<='9';j++)
					{
							temp[k]=j;
							if(taken.find(temp)==taken.end())
							{
								ans++;
								res[i].second.append(temp);
								taken.insert(res[i].second);
								ok=true;
								break;

							}
							
					}
					if(ok)
						break;
				}
					//char curr_char=it[idx];
						
			
			}

		}
		cout<<ans<<endl;
		for(auto it:res)
			cout<<it.second<<endl;


	}

}