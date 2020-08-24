// Created by Tanuj Jain
#include<bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;
#define pb push_back
#define mp make_pair
typedef long long ll;
typedef pair<ll,ll> pii;
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

	ll a,b;
	cin>>a>>b;
	vector<ll>v1(a);
	for(ll i=0;i<a;i++)
		cin>>v1[i];
	vector<vector<ll>>v2;
	for(ll i=0;i<b;i++)
	{
		vector<ll>temp;
		for(ll j=0;j<2;j++)
		{
			ll x;
			cin>>x;
			temp.pb(x);
		}
		v2.pb(temp);
	}
	
	sort(v2.begin(),v2.end());
	//find prefix sum array
	vector<ll>prefix(b);
	prefix[0]=v2[0][1];
	for(ll i=1;i<b;i++)
	{
		prefix[i]=prefix[i-1]+v2[i][1];
	}
	//for(ll i=0;i<b;i++)
	//	cout<<prefix[i]<<" ";
	//cout<<endl;
	//seperate the bases
	vector<ll>bases;
	for(ll i=0;i<b;i++)
		bases.pb(v2[i][0]);

	//for(ll i=0;i<b;i++)
	//	cout<<bases[i]<<" ";
	
	for(ll i=0;i<a;i++)
	{
		ll ind=upper_bound(bases.begin(),bases.end(),v1[i])-bases.begin()-1;
		if(ind>=0)
			cout<<prefix[ind]<<" ";
		else
			cout<<0<<" ";
	}

	
}