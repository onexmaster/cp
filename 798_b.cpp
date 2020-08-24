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
	int global_min=INT_MAX;
	vector<string>v(t);
	for(int i=0;i<t;i++)
		cin>>v[i];
	/*
	vector<int> freq(26);
	for(string st:v)
	{
		for(char c :st)
			freq[c-'a']++;
	}
	for(int i=0;i<26;i++)
	{
		if(freq[i]>0 && freq[i]%t!=0)
		{
			cout<<-1;
			return 0;
		}
	}
	*/
	for(int i=0;i<t;i++)
	{
		int local_count=0;
		for(int j=0;j<t;j++)
		{
			if(i!=j)
				local_count+=(v[j]+v[j]).find(v[i]);
		}
		global_min=min(local_count,global_min);
	}
	global_min<0? cout<<-1:cout<<global_min;
}