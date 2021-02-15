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

	//corner case
	//if the string is empty
	//if(st.size()==0)
	//return 0;
	//if(k>st.size())
	//return 0;
	string st;
	cin>>st;
	//cout<<st<<endl;
	int k;
	cin>>k;
	//cout<<k<<endl;
	unordered_set<string>ans;
	std::vector<string> v;
	vector<int>freq(26,0);
	for(int i=0;i<k;i++)
		freq[st[i]-'a']++;
	int l=0;
	int r=k;
	int n=st.size();
	while(r<n)
	{
		//count the unqiue elements
		int count=0;
		for(int i=0;i<26;i++)
			if(freq[i]>0)
				count++;
		if(count==k)
		{
			string temp=st.substr(l,k);
			if(ans.find(temp)==ans.end())
			{
				v.pb(temp);
				ans.insert(temp);
			}
			//ans.insert(st.substr(l,k));
		}
		freq[st[l]-'a']--;
		l++;
		freq[st[r]-'a']++;
		r++;
	}
	int count=0;
	for(int i=0;i<26;i++)
		if(freq[i]>0)
			count++;
	if(count==k)
	{
		string temp=st.substr(l,r);
			if(ans.find(temp)==ans.end())
			{
				v.pb(temp);
				ans.insert(temp);
			}
	}
	for(auto it:v)
		cout<<it<<endl;
	return 0;

}