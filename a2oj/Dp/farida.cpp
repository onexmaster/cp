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

ll recursive(vector<ll>&v, int pos, vector<bool>&vis, vector<ll>&dp)
{
	if(pos==0)
		return v[0];
	if(pos<0)
		return 0;
	if(vis[pos])
		return dp[pos];
	vis[pos]=true;
	ll temp=max(recursive(v,pos-1,vis,dp), recursive(v,pos-2,vis,dp) +v[pos]);
	return dp[pos]=temp;
}
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
	if(t==0)
	{
		cout<<"Case 1:"<<" "<<0<<endl;
		return 0;
	}
	else{
	int i=1;
	while(t--)
	{
		ll n;
		cin>>n;
		vector<ll>v(n);
		vector<bool>vis(n,false);
		vector<ll>dp(n,0);
		for(int i=0;i<n;i++)
			cin>>v[i];
		cout<<"Case "<<i<<": "<<recursive(v, n-1, vis, dp)<<endl;
		i++;
	}
	}
}