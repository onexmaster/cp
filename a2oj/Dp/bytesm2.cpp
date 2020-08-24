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
		int row,col;
		cin>>row>>col;
		int grid[row][col];
		for(int i=0;i<row;i++)
			for(int j=0;j<col;j++)
				cin>>grid[i][j];
		int dp[row][col]={};
		for(int i=0;i<col;i++)
			dp[0][i]=grid[0][i];
		for(int i=1;i<row;i++)
		{
			for(int j=0;j<col;j++)
			{
				if(j==0)
				{
					dp[i][j]=max(dp[i-1][j],dp[i-1][j+1])+grid[i][j];
				}
				else if(j==col-1)
				{
					dp[i][j]=max(dp[i-1][j-1],dp[i-1][j])+grid[i][j];
				}
				else
					dp[i][j]=max(dp[i-1][j-1],max(dp[i-1][j],dp[i-1][j+1]))+grid[i][j];
			}
		}
		int ans=0;
		for(int i=0;i<col;i++)
			ans=max(ans,dp[row-1][i]);
		cout<<ans<<endl;

	}
	
}