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
	map<string,set<string>>final;
	map<string,set<string>>suffixes;
	map<string,set<string>>temp_name;
	while(t--)
	{
		string name;
		cin>>name;
		int n;
		cin>>n;
		//vector<string>numbers;
		while(n--)
		{
			string no;
			cin>>no;
			temp_name[name].insert(no);
		}
	}
	
	//map<string,vector<string>>temp2;
	for(auto it:temp_name)
	{
		vector<string>numbers;
		for(auto names:it.second)
			numbers.pb(names);
		

		sort(numbers.begin(),numbers.end(),[](string a, string b){
			return a.size()>b.size();
		});
		for(string no:numbers)
		{
			if(final.count(it.first)==0)
			{
				final[it.first].insert(no);
				for(int i=0;i<no.size();i++)
				{
					string temp=no.substr(i,no.size()-i+1);
					suffixes[it.first].insert(temp);
				}
			}
			else
			{
				if(suffixes[it.first].find(no)==suffixes[it.first].end())
				{
					final[it.first].insert(no);
					for(int i=0;i<no.size();i++)
					{
						string temp=no.substr(i,no.size()-i+1);
						suffixes[it.first].insert(temp);
					}

				}
			}
		}
		
	}
	cout<<final.size()<<endl;
	for(auto it:final)
	{
		cout<<it.first<<" "<<it.second.size()<<" ";
		for(auto nos:it.second)
			cout<<nos<<" ";
		cout<<endl;
	}

}