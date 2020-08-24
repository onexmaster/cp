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
ll recurisve(vector<vector<ll>>&v , ll capacity ,ll no_of_items)
{
	//base case
	//if no capacity or no more items to check
	
	if(no_of_items==0 || capacity==0LL)
		return 0LL;
	//If the weight of my current item is more than the capacity then i cannot select this
	if(v[no_of_items-1][0]>capacity)
		return (recurisve(v,capacity,no_of_items-1LL));
	else
	{
		//i have two options 
		//1 choose this item and recurse on remaning items
		ll left_child=v[no_of_items-1][1]+recurisve(v,capacity-v[no_of_items-1][0],no_of_items-1LL);
		//2 do not choose this item and find the remaning items
		ll right_child=recurisve(v,capacity,no_of_items-1LL);
		ll ans=max(left_child,right_child);
		return ans;
	}
	
}

//bottom up
ll bottom_up(vector<vector<ll>>&v, int capacity)
{
	ll dp[v.size()+1][capacity+1]={};
	for(int i=1;i<=v.size();i++)
	{
		for(int j=1;j<=capacity;j++)
		{
			if(v[i-1][0]<=j)
			{
				//dp is max of taking that item or excluding that item
				dp[i][j]=max(v[i-1][1]+dp[i-1][j-v[i-1][0]], dp[i-1][j]);
			}
			else
				dp[i][j]=dp[i-1][j];
		}
	}
	return dp[v.size()][capacity];

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

	ll n,w;
	cin>>n>>w;
	vector<vector<ll>>v(n,vector<ll>(2));
	for(int i=0;i<n;i++)
		for(int j=0;j<2;j++)
			cin>>v[i][j];
	//cout<<recurisve(v,w,n);
		cout<<bottom_up(v,w);


	
}