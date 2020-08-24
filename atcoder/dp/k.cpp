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

	int n,k;
	cin>>n>>k;
	vector<int>v(n);
	for(int i=0;i<n;i++)
		cin>>v[i];
	vector<bool> dp(k+1);
	for(int stones=0;stones<=k;stones++)
	{
		for(int x : v)
		{
			if(stones>=x && !dp[stones-x])
				dp[stones]=true;
		}
	}
	if(dp[k])
		cout<<"First";
	else if(!dp[k])
		cout<<"Second";
	
}