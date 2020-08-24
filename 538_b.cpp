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

void generate(int x, vector<int>&a)
{
	if(x>1100000)
		return;
	a.pb(x);
	if(x!=0)
		generate(x*10,a);
	generate(x*10+1,a);
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
	vector<int>a;
	generate(0,a);
	int take[t+1]={};
	int dp[t+1]={};
	dp[0]=0;
	for(int i=1;i<=t;i++)
	{
		dp[i]=1100001;
		for(int j=0;j<a.size();j++)
		{
			if(a[j]<=i)
			{
				if(dp[i]>dp[i-a[j]]+1)
				{
					dp[i]=dp[i-a[j]]+1;
					take[i]=j;
				}
			}
		}
	}
	cout<<dp[t]<<endl;
	int x=t;
	while(x!=0)
	{
		cout<<a[take[x]]<<" ";
		x-=a[take[x]];
	}
	
}