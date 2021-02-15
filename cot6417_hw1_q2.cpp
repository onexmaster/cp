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

	string t;
	cin>>t;
	multiset<char>s={'a','a','b'};
	int n=s.size();
	//this multiset is used to record the char in the text
	multiset<char>m;
	//insert the firs n chars in the multiset
	for(int i=0;i<n;i++)
		m.insert(t[i]);
	//count of subtrings which match the crietria
	int count=0;
	int l=0;
	int r=n;
	while(r<int(t.size()))
	{
		//if both the multiset match it means that this substring contains
		//some permutation of s
		if(s==m)
			count++;
		//remove the left most char 
		m.erase(m.lower_bound(t[l]));
		l++;
		//add the new char from the right
		m.insert(t[r]);
		r++;
	}
	//once we are out of the while loop we need to check the last substring 
	if(s==m)
		count++;
	cout<<count;
	return 0;

}