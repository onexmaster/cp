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
		ll n,a,b;
		cin>>n>>a>>b;
		string S;
		cin>>S;
		ll dp[n+1][2]={};
		dp[0][0]=b;
		dp[0][1]=1e15;
		for(int i=1;i<=n;i++)
		{
			if(S[i-1]=='1')
			{
				dp[i][0]=1e15;
				dp[i][1] = min(dp[i-1][0]+2*a+2*b, dp[i-1][1]+2*b+a);
			}
			else
			{
				dp[i][0] = min(dp[i-1][0]+a+b, dp[i-1][1]+2*a+2*b);
                dp[i][1] = min(dp[i-1][0]+2*(a+b), dp[i-1][1]+2*b+a);
				
			}
		}
		cout<<dp[n][0]<<endl;
	}
	
}