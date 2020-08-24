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
	vector<int>v(t);
	for(int i=0;i<t;i++)
		cin>>v[i];
	string st;
	cin>>st;
	vector<int>temp=v;
	sort(temp.begin(),temp.end());
	bool ok=true;
	// for(int i=0;i<st.size();i++)
	// {
	// 	if(st[i]=='0' && v[i]!=temp[i])
	// 		ok=false;
	// }
	//build a new vector with sorted elements
	vector<int>temp1;
	for(int i=0;i<st.size();i++)
	{
		if(st[i]=='0')
			temp1.pb(v[i]);
		else
		{
			set<int>temp2;
			while(st[i]=='1')
			{
				temp2.insert(v[i]);
				temp2.insert(v[i+1]);
				i++;
			}
			//sort(temp2.begin(),temp2.end());
			for(auto x:temp2)
				temp1.pb(x);
		}

	}
	if(st[st.size()-1]=='0')
		temp1.pb(v[v.size()-1]);
	if(is_sorted(temp1.begin(),temp1.end()))
		cout<<"YES";
	else
		cout<<"NO";
	// 	ok=false;
	// if(!ok)
	// 	cout<<"NO";
	// else
	// 	cout<<"YES";
	

}