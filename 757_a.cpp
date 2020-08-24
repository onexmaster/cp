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

int main()
{
	ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

	#ifndef ONLINE_JUDGE
	freopen("inputf.in","r",stdin);
	freopen("outputf.in","w",stdout);
	#endif

	string st;
	cin>>st;
	unordered_map<char,int>freq;
	for(char c :st)
		freq[c]++;
	string temp="Bulbasr";
	int count=1e9;
	for(char c:temp)
	{
		if(c=='a' || c=='u')
			count=min(count,freq[c]/2);
		else
			count=min(count,freq[c]);
	}
	cout<<count;
}