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
		string s,t;
		cin>>s>>t;
		vector<int>global_freq(26,0);
		unordered_map<int,vector<int>>pos;
		for(int i=0;i<s.size();i++)
		{
			global_freq[s[i]-'a']++;
			pos[s[i]-'a'].pb(i);
		}
		int count=0;
		int i=0;
		vector<int>local_freq=global_freq;
		bool global_ok=true;
		int prv_pos=-1;
		while(i<int(t.size()))
		{
			//cout<<i<<" "<<prv_pos<<endl;
			if(global_freq[t[i]-'a']==0)
			{
				global_ok=false;
				break;
			}
			else if(local_freq[t[i]-'a']>0)
			{
				if(prv_pos==-1)
				{
					local_freq[t[i]-'a']--;
					vector<int>position=pos[t[i]-'a'];
					prv_pos=position[0];
					i++;
				}
				else
				{
					//check if this char come after the previous pos, if yes then we can use it
					//vector<int>position=pos[t[i]-'a'];
					bool ok=false;
					//this is causing tle,maybe
					//replcae this with upper_bound
					//for(int j=0;j<position.size();j++)
					//{
					int temp=lower_bound(pos[t[i]-'a'].begin(),pos[t[i]-'a'].end(),prv_pos+1)-pos[t[i]-'a'].begin();
					//cout<<prv_pos<<" "<<t[i]<<" "<<position[temp]<<endl;
						if(temp<int(pos[t[i]-'a'].size()) && pos[t[i]-'a'][temp]>prv_pos)
						{
							prv_pos=pos[t[i]-'a'][temp];
							ok=true;
							local_freq[t[i]-'a']--;
							i++;
							//break;
						}
				//}
					//if we do not find any index where the next element is present, then we need to search a new subsequnce
					if(!ok)
					{
						local_freq=global_freq;
						prv_pos=-1;
						count++;
					}
				}
			}
			else
			{
				local_freq=global_freq;
				prv_pos=-1;
				count++;
			}
		}
		if(!global_ok)
			cout<<-1<<endl;
		else
			cout<<count+1<<endl;
	}

}