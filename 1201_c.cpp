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

	ll n,k;
	cin>>n>>k;
	vector<ll>v(n);
	for(int i=0;i<n;i++)
		cin>>v[i];
	sort(v.begin(),v.end());
	ll l=v[n/2];
	ll h=v[n/2]+k;
	int u=-1;

	while(l<=h)
	{
		ll m=l+(h-l)/2;
		ll c=0;
		for(int i=n/2;i<n;i++)
		{
			c+=max(0LL,m-v[i]);
		}
		//cout<<m<<" "<<c<<endl;
		if(c>k)
			h=m-1;
		else
		{
			u=m;
			l=m+1;
		}
	}
	cout<<u;
}