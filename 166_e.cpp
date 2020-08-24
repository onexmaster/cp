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

ll mod=1000000007LL;
int dp[10000001][4];
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
	dp[1][0]=dp[1][1]=dp[1][2]=1;
	dp[1][3]=0;
	for(int i=2;i<=t;i++)
	{
		dp[i][0]=(ll(dp[i-1][1])+ll(dp[i-1][2])+ll(dp[i-1][3]))%mod;
		dp[i][1]=(ll(dp[i-1][0])+ll(dp[i-1][2])+ll(dp[i-1][3]))%mod;
		dp[i][2]=(ll(dp[i-1][0])+ll(dp[i-1][1])+ll(dp[i-1][3]))%mod;
		dp[i][3]=(ll(dp[i-1][0])+ll(dp[i-1][1])+ll(dp[i-1][2]))%mod;
	}
	//for(int i=0;i<=t;i++)
	//{
	//	for(int j=0;j<4;j++)
	//		cout<<dp[i][j]<<" ";
	//	cout<<endl;
	//}

	cout<<dp[t][3];
}