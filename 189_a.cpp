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

	int n,a,b,c;
	int arr[3];
	cin>>n>>arr[0]>>arr[1]>>arr[2];
	vector<long>dp(n+1,INT_MIN);
	dp[0]=0;
	for(int i=1;i<=n;i++)
	{
		for(int j=0;j<3;j++)
		{
			if(i-arr[j]>=0)
				dp[i]=max(dp[i],dp[i-arr[j]]+1);
		}
	}
	cout<<dp[n];
	
}