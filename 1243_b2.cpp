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
		string s,t;
		cin>>s>>t;
		int num[26]={0};
		for(int i=0;i<n;i++)
		{
			num[s[i]-'a']++;
			num[t[i]-'a']++;
		}
		bool ok=true;
		for(int i=0;i<26;i++)
			if(num[i]%2==1)
			{
				ok=false;
				break;
			}
		if(!ok)
			cout<<"NO"<<endl;
		else
		{
			cout<<"YES"<<endl;
			vector<pii>ans;
			for(int i=0;i<n;i++)
			{
				if(s[i]==t[i])
					continue;
				else
				{
					//fix this kind of mismatch ss
											
											   //hh
					bool ok1=false;
					for(int j=i+1;j<n;j++)
					{
						if(s[j]==s[i])
						{
							ok1=true;
							swap(t[i],s[j]);
							ans.pb({j+1,i+1});
							break;
						}
					}
					if(!ok1)
					{
						//for the other type of mismatch we need 2 steps
						for(int j=i+1;j<n;j++)
						{
							if(t[j]==s[i])
							{
								swap(s[j],t[j]);
								ans.pb({j+1,j+1});
								swap(t[i],s[j]);
								ans.pb({j+1,i+1});
								break;
							}
						}
					}
				}
			}
			cout<<ans.size()<<endl;
			//cout<<s<<" "<<t<<endl;
			for(int i=0;i<ans.size();i++)
			{
				cout<<ans[i].first<<" "<<ans[i].second<<endl;
			}
		}
	}

}