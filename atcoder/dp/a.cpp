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

int recursive_min_cost(vector<int>&v,int end,int &ans)
{
	//cout<<"call:"<<end<<endl;
	if(end==0)
		return 0;
	if(end<0)
		return 1e6;
	//find left child ans
	//int ans=0;
	int left_child=recursive_min_cost(v,end-1,ans);
	int right_child=recursive_min_cost(v,end-2,ans);
	//find the current answer
	ans=min(left_child+abs(v[end]-v[end-1]),right_child+abs(v[end]-v[end-2]));
	//cout<<ans<<endl;
	return ans;

}
int top_down(vector<int>&v,int end, int &ans, unordered_map<int,int>&memo)
{
	//cout<<end<<endl;
	if(end==0)
		return 0;
	if(end<0)
		return 1e6;
	//find left child ans
	//int ans=0;
	if(memo.find(end)==memo.end())
	{
		int left_child=top_down(v,end-1,ans,memo);
		int right_child=top_down(v,end-2,ans,memo);
		//find the current answer
		ans=min(left_child+abs(v[end]-v[end-1]),right_child+abs(v[end]-v[end-2]));
		memo[end]=ans;
		//cout<<ans<<endl;
		return ans;
	}
	else
		return memo[end];
	
}
int bottom_up(vector<int>&v)
{
	int n=v.size();
	vector<int>dp(n+1,1e6);
	dp[0]=0;
	dp[1]=abs(v[1]-v[0]);
	for(int i=2;i<n;i++)
	{
		dp[i]=min(dp[i-1]+abs(v[i]-v[i-1]),dp[i-2]+abs(v[i]-v[i-2]));
	}
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

	int t;
	cin>>t;
	vector<int>v(t); 
	for(int i=0;i<t;i++)
		cin>>v[i];
	//int ans=0;
	//recursive_min_cost(v,t-1,ans);

	//top down dp with memoization
	//unordered_map<int,int>memo;
	//top_down(v,t-1,ans,memo);
	//for(auto it:memo)
	//	cout<<it.first<<" "<<it.second<<endl;
	//cout<<ans;


	//bottom up dp
	cout<<bottom_up(v)<<endl;
	
}