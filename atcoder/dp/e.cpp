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

const int MAXV = 1e5 + 10;
const int MAXN = 1e3 + 10;
const ll INF = 1e13;

ll bottom_up(vector<ll>&weights, vector<ll>&values, int total_capacity)
{
	int n=weights.size();
	//make a dp table where we map item on rows and value on columns since teh weights can be very large
	int total_values=0;
	for(int i=0;i<n;i++)
		total_values+=values[i];
	vector<vector<ll>>dp(n+1,vector<ll>(total_values+1,INF));
	dp[0][0]=0;
	ll ans=0;
	for(int i=1;i<=n;i++)
	{
		for(int j=0;j<=total_values;j++)
		{
			if(j-values[i-1]>=0)
			{
				//take the min weight obtained by using this item and not using this item
				dp[i][j]=min(dp[i-1][j], weights[i-1] + dp[i-1][j-values[i-1]]);
			}
			else
				dp[i][j]=dp[i-1][j];
		}
	}
	//iterate over the last row and find the maximum value we can get 
	for(ll i=0;i<=total_values;i++)
	{
		if(dp[n][i]<=total_capacity)
			ans=max(ans,i);
	}
	//for(int i=0;i<=n;i++)
	//{
	//	for(int j=0;j<=total_values;j++)
	//		cout<<dp[i][j]<<" ";
	//	cout<<endl;
	//}
	return ans;
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

	int n,w;
	cin>>n>>w;
	vector<ll>weights(n),values(n);
	for(int i=0;i<n;i++)
		cin>>weights[i]>>values[i];
	//for(int i=0;i<n;i++)
	//	cout<<weights[i]<<" "<<values[i]<<endl;

	cout<<bottom_up(weights,values,w);
	
}