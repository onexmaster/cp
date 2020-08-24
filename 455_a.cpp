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

ll dp[1000005][2];
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
	vector<ll>v(t);
	map<ll,ll>m;
	ll mn=1e5+7;;
	ll mx=-1;
	for(int i=0;i<t;i++)
	{
		cin>>v[i];
		mn=min(mn,v[i]);
		mx=max(mx,v[i]);
	}
	for(int i=0;i<t;i++)
		m[v[i]]++;
	//for(auto it:m)
	//	it.s=it.first*it.second;
	//for(auto it:m)
	//	cout<<it.first<<" "<<it.second<<endl;
	//set<int>st(v.begin(),v.end());
	if(mn==1)
		dp[1][0]=m[1];
	for(int i=2;i<=mx;i++)
	{
		dp[i][0]=dp[i-1][1]+m[i]*(ll)i;
		dp[i][1]=max(dp[i-1][0],dp[i-1][1]);
	}
	//for(int i=0;i<=mx;i++)
	//	cout<<i<<" "<<dp[i][0]<<" "<<dp[i][1]<<endl;
	cout<<max(dp[mx][0],dp[mx][1]);






	
}
