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
	while(t--)
	{
		ll n;
		cin>>n;
		vector<ll>v(n);
		for(ll i=0;i<n;i++)
			cin>>v[i];
		ll sum=0;
		ll mx=-1e18;
		for(ll i=0;i<n;i++)
		{
			if(i==0)
			{
				mx=max(mx,v[i]);
				continue;
			}
			if(v[i]*v[i-1]>0)
			{
				mx=max(mx,v[i]);
				continue;
			}
			sum+=mx;
			mx=v[i];
		}
		cout<<sum+mx<<endl;
	}
	
}