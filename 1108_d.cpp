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

	int n;
	cin>>n;
	string st;
	cin>>st;
	int dp[n][3]={};
	if(st[0]=='R')
	{
		dp[0][1]=1;
		dp[0][2]=1;
	}
	else if(st[0]=='G')
	{
		dp[0][0]=1;
		dp[0][2]=1;
	}
	else
	{
		dp[0][0]=1;
		dp[0][1]=1;
	}
 	for(int i=1;i<n;i++)
 	{
 		if(st[i]=='R')
 		{
 			dp[i][0]=min(dp[i-1][1],dp[i-1][2]);
 			dp[i][1]=min(dp[i-1][0],dp[i-1][2])+1;
 			dp[i][2]=min(dp[i-1][0],dp[i-1][1])+1;
 		}
 		else if(st[i]=='G')
 		{
 			dp[i][0]=min(dp[i-1][1],dp[i-1][2])+1;
 			dp[i][1]=min(dp[i-1][0],dp[i-1][2]);
 			dp[i][2]=min(dp[i-1][0],dp[i-1][1])+1;
 		}
 		else if(st[i]=='B')
 		{
 			dp[i][0]=min(dp[i-1][1],dp[i-1][2])+1;
 			dp[i][1]=min(dp[i-1][0],dp[i-1][2])+1;
 			dp[i][2]=min(dp[i-1][0],dp[i-1][1]);
 		}
 	}
 	/*
 	for(int i=0;i<n;i++)
 	{
 		cout<<st[i]<<" ";
 		for(int j=0;j<3;j++)
 			cout<<dp[i][j];
 		cout<<endl;
 	}
 	*/
	int ans=min(dp[n-1][0],min(dp[n-1][1],dp[n-1][2]));
	stack<char>stk;
	char c='0';
	if(dp[n-1][0]==ans)
		c='R';
	if(dp[n-1][1]==ans)
		c='G';
	if(dp[n-1][2]==ans)
		c='B';
	stk.push(c);
	for(int i=n-2;i>=0;i--)
	{
		if(stk.top()=='B')
		{
			if(dp[i][0]>dp[i][1])
				stk.push('G');
			else
				stk.push('R');
			continue;
		}
		 else if(stk.top()=='G')
		{
			if(dp[i][0]>dp[i][2])
				stk.push('B');
			else
				stk.push('R');
		}
		  else if(stk.top()=='R')
		{
			if(dp[i][1]>dp[i][2])
				stk.push('B');
			else
				stk.push('G');
		}
	}
	cout<<ans<<endl;
	while(!stk.empty())
	{
		cout<<stk.top();
		stk.pop();
	}
	return 0;
}
