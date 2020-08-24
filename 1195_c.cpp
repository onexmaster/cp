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
	vector<ll>t1(t),t2(t);
	for(int i=0;i<t;i++)
		cin>>t1[i];
	for(int i=0;i<t;i++)
		cin>>t2[i];
	ll dp[3][t];
	dp[0][0]=0;
	dp[1][0]=t1[0];
	dp[2][0]=t2[0];
	ll ans=max(t1[0],t2[0]);
	for(int i=1;i<t;i++)
	{
		dp[0][i]=max(dp[0][i-1],max(dp[1][i-1],dp[2][i-1]));
		dp[1][i]=max(dp[0][i-1],dp[2][i-1])+t1[i];
		dp[2][i]=max(dp[0][i-1],dp[1][i-1])+t2[i];

	}
	cout<<max(dp[0][t-1],max(dp[1][t-1],dp[2][t-1]));
	
}