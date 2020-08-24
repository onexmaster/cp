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

	int t_w,n;
	while(cin>>t_w>>n){
		if(t_w==0 && n==0)
			return 0;
	vector<int>cost(n), fun(n);
	for(int i=0;i<n;i++)
		cin>>cost[i]>>fun[i];
	vector<vector<int>>dp(n+1,vector<int>(t_w+1));
	for(int i=0;i<=n;i++)
	{
		for(int j=0;j<=t_w;j++)
		{


			if(i==0||j==0)
				dp[i][j]=0;
			else if(cost[i-1]<=j)
			{
				dp[i][j]=max(dp[i-1][j],dp[i-1][j-cost[i-1]]+fun[i-1]);
			}
			else
				dp[i][j]=dp[i-1][j];
		}
	}
	// for(int i=0;i<=n;i++)
	// {
	// 	for(int j=0;j<=t_w;j++)
	// 		cout<<dp[i][j]<<" ";
	// 	cout<<endl;
	// }
	int ans=INT_MAX;
	for(int i=0;i<=t_w;i++)
		if(dp[n][i]==dp[n][t_w])
			ans=min(ans,i);

	cout<<ans<<" "<<dp[n][t_w]<<endl;
}

}
