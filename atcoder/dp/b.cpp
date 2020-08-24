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
 int recursion(vector<int>&v, int end, int k)
 {
 	//cout<<end
 	if(end==0)
 		return 0;
 	if(end<0)
 		return 1e6;
 	int ans=1e6;
 	for(int i=1;i<=k;i++)
 	{
 		//find the ans for each child node and take the minimum out of it
 		if(end-i>=0)
 		{
 			int temp=recursion(v,end-i,k);
 			if(temp!=1e6)
 				ans=min(ans,temp+abs(v[end]-v[end-i]));	
 		} 
 		
 	}
 	return ans;
 }
 int recursion_with_memo(vector<int>&v, int end, int &k, unordered_map<int,int>&memo)
 {
 	if(end==0)
 		return 0;
 	//if(end<0)
 	//	return 1e6;
 	int ans=1e9;
 	for(int i=1;i<=k;i++)
 	{
 		if(end-i>=0)
 		{
 			if(memo.find(end-i)==memo.end())
 			{
 				//calu the value
 				int temp=recursion_with_memo(v,end-i,k,memo);
 				//save the value in memo table
 				memo[end-i]=temp;
 				ans=min(ans,temp+abs(v[end]-v[end-i]));
 			}
 			else
 				ans=min(ans,memo[end-i]+abs(v[end]-v[end-i]));

 		}
 	}
 	return ans;

 }
 int bottom_up(vector<int>&v,int k)
 {
 	int n=v.size();
 	vector<int>dp(n,1e9);
 	dp[0]=0;
 	//dp[1]=abs(v[1]-v[0]);
 	for(int i=1;i<n;i++)
 	{
 		for(int j=1;j<=k;j++)
 			if(i-j>=0)
 				dp[i]=min(dp[i],dp[i-j]+abs(v[i]-v[i-j]));
 	}
 	//for(int i=0;i<n;i++)
 	//	cout<<dp[i]<<" ";
 	return dp[n-1];
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

	int t,k;
	cin>>t>>k;
	vector<int>v(t);
	for(int i=0;i<t;i++)
		cin>>v[i];
	//cout<<recursion(v,t-1,k);
	//recursion with memoization 
	unordered_map<int,int>memo;
	//int ans=1e6;
	cout<<recursion_with_memo(v,t-1,k,memo);
	//for(auto it:memo)
	//	cout<<it.first<<" "<<it.second<<endl;
	//cout<<bottom_up(v,k);

	
}