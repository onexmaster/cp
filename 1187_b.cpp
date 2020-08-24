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

	int t;
	cin>>t;
	string st;
	cin>>st;

	vector<vector<int>>pos(30);
	for(int i=0;i<t;i++)
	{
		pos[st[i]-'a'].push_back(i);
	}
	
	
	int x;
	cin>>x;
	while(x--)
	{
		int c2[26]={};
		string st2;
		cin>>st2;
		//unordered_map<char,int>mp2;
		for(int i=0;i<st2.size();i++)
			c2[st2[i]-'a']++;
		int mx=0;
		for(int i=0;i<26;i++)
		{
			if(c2[i])
				mx=max(mx,pos[i][c2[i]-1]);
		}
		cout<<mx+1<<endl;
	}
}