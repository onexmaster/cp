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
ll dp[200001];
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
	while(t--)
	{
		ll n,p,k;
		cin>>n>>p>>k;
		vector<ll>v(n+1);
		for(int i=1;i<=n;i++)
			cin>>v[i];
		sort(v.begin(),v.end());
		ll ans=0;
		for(int i=1;i<=n;i++)
		{	
			if(i<k)
			{
				dp[i]=dp[i-1]+v[i];
			}
			else
				dp[i]=min(dp[i-1]+v[i], dp[i-k]+v[i]);
	}
	for(int i=1;i<=n;i++)
		if(dp[i]<=p)
			ans=i;
	cout<<ans<<endl;
	
}
}