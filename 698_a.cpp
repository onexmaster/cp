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

int dp[105][3];
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
	for(int i=1;i<=t;i++)
	{
		dp[i][0]=max(dp[i-1][0],max(dp[i-1][1],dp[i-1][2]));
		if(v[i-1]==1 || v[i-1]==3)
			dp[i][1]=max(dp[i-1][0],dp[i-1][2])+1;
		if(v[i-1]==2 || v[i-1]==3)
			dp[i][2]=max(dp[i-1][0],dp[i-1][1])+1;
	}
	//for(int i=0;i<=t;i++)
	//{
	//	for(int j=0;j<3;j++)
	//		cout<<dp[i][j]<<" ";
	//	cout<<endl;
	//}
	int ans=max(dp[t][0],max(dp[t][1],dp[t][2]));
	cout<<t-ans;






	
}