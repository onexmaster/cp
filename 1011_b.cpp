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


	int n,m;
	cin>>n>>m;
	map<int,int>mp;
	vector<int>v(m);
	for(int i=0;i<m;i++)
	{
		cin>>v[i];
	}
	for(int i=0;i<m;i++)
		mp[v[i]]++;
	if(n>m)
	{
		cout<<0;
		return 0;
	}
	int l=1;
	int h=m;
	int u=0;
	while(l<=h)
	{
		int m=(l+h)/2;
		int c=0;
		for(auto it:mp)
		{	 
			c+=it.second/m;
		}
		if(c>=n)
		{
			u=m;
			l=m+1;
		}
		else
		{
			h=m-1;
		}       
	}
	 cout<<u;
}