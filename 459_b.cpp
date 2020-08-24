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

	ll t;
	cin>>t;
	vector<ll>v(t);
	for(int i=0;i<t;i++)
		cin>>v[i];
	sort(v.begin(),v.end());
	unordered_map<ll,ll>mp;
	for(int i=0;i<t;i++)
		mp[v[i]]++;
	if(mp.size()==1)
		cout<<0<<" "<<t*(t-1)/2;
	else
	{
		cout<<v.back()-v[0]<<" ";
		cout<<mp[v.back()]*mp[v[0]];	
	}
	
	
}