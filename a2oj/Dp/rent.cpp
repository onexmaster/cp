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

int bottomup(vector<pair<int,pair<int,int>>>&time)
{
	int n=time.size();
	int dp[n+2];
	memset(dp,0,sizeof(dp));
	dp[0]=time[0].second.second;
	for(int i=1;i<n;i++)
	{
		dp[i]=time[i].second.second;
		for(int j=0;j<i;j++)
		{
			if(time[i].second.first>=time[j].first)
				dp[i]=max(dp[i],(time[i].second.second+dp[j]));
		}
	}
	return *max_element(dp,dp+n);
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
	while(t--)
	{
		vector<pair<int,pair<int,int>>>time;
		//time-0 is end time 
		//time-1 is start time
		//time-2 is the profit
		int n,st,d,c,e;
		cin>>n;
		while(n--)
		{
			cin>>st>>d>>c;
			e=st+d;
			time.pb({e,{st,c}});
		}
		sort(time.begin(),time.end());
		cout<<bottomup(time)<<endl;

	}
	
	return 0;
}