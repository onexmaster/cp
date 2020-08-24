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

ll bottomup(vector<ll>&v,vector<ll>&dp)
{
			for(int i=0;i<v.size();i++)
			{
				if(i==0)
					dp[i]=v[i];
				else if(i==1)
					dp[i]=max(dp[i-1],v[i]);
				else
					dp[i]=max(dp[i-1], dp[i-2]+v[i]);
			}
			return dp[v.size()-1];
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

	ll M,N;
	while(cin>>M>>N)
	{
		if(M==0 && N==0)
			return 0;
		else
		 {
			
			vector<ll>temp(N);
			vector<ll>dp(N);
			for(int i=0;i<M;i++)
			{
				vector<ll>grid(N);
				for(int j=0;j<N;j++)
					cin>>grid[j];
				dp.clear();
				temp[i]=bottomup(grid, dp);
			}
			dp.clear();
			cout<<bottomup(temp,dp)<<endl;

		}
	}
	
}