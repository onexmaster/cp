//Need to work on this
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
	vector<int>length(n), width(n);
	for(int i=0;i<t;i++)
		cin>>length[i]>>width[i];
	int dp[n][2];
	dp[0][0]=length[0];
	dp[0][1]=widht[1];
	for(int i=1;i<t;i++)
	{
		//if i keep the new box horizontal
		dp[i][0]=max(dp[i-1][0]+abs(width[i-2]-length[i-1])+width[i-1],
			dp[i-1][1]+abs(length[i-1]-length[i-2])+width[i-1]);
		//if i keep the new box vertical
		dp[i][1]=max()
	}
	
}