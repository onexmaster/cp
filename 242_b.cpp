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
	//set<pair<int,int>,int>st;
	int l=INT_MAX;
	int r=-1;
	vector<pair<int,int>>v;
	for(int i=0;i<t;i++)
	{
		int a,b;
		cin>>a>>b;
		l=min(l,a);
		r=max(r,b);
		v.pb({a,b});
		//st.insert{a,b};
	}
	for(int i=0;i<t;i++)
	{
		if(v[i].first==l && v[i].second==r)
		{
			cout<<i+1;
			return 0;
		}
	}
	cout<<-1;
	return 0;
	
}