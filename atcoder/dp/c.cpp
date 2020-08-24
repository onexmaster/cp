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
int recursion(vector<vector<int>>&v, int curr, int pre_col)
{
	if(curr==v.size())
		return 0;
	int ans=0;
	for(int i=0;i<3;i++)
	{
		if(pre_col==i)
			continue;
		ans=max(ans,v[curr][i]+recursion(v,curr+1,i));
	}
	return ans;
		
}
int bottom_up(vector<vector<int>>&v)
{
	int rows=v.size();
	int dp[rows][3];
	dp[0][0]=v[0][0];
	dp[0][1]=v[0][1];
	dp[0][2]=v[0][2];
	for(int i=1;i<rows;i++)
	{
		dp[i][0]=max(dp[i-1][1],dp[i-1][2])+v[i][0];
		dp[i][1]=max(dp[i-1][0],dp[i-1][2])+v[i][1];
		dp[i][2]=max(dp[i-1][0],dp[i-1][1])+v[i][2];
	}
	return (max(dp[rows-1][0],max(dp[rows-1][1],dp[rows-1][2])));
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
	vector<vector<int>>v(t,vector<int>(3,0));
	for(int i=0;i<t;i++)
		for(int j=0;j<3;j++)
			cin>>v[i][j];
		//cout<<bottom_up(v);
		cout<<recursion(v,0,-1);
	
	
}