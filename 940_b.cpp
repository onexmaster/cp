//Does not work
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
ll n,k,a,b;
int cost;
map<ll,ll>memo;
ll recursive(ll n)
{
	cout<<n<<endl;
	if(n==1)
		return 0;
	//if i have already been here
	if(memo.count(n)!=0)
		return memo[n];
	ll temp1=0;
	if(n%k==0)
			temp1=recursive(n/k)+b;
	ll temp2=0;
		temp2=recursive(n-1)+a;
	//cout<<n<<" "<<temp1<<" "<<temp2<<endl;
	cost+=temp1==0?temp2:min(temp1,temp2);
	return memo[n]=temp1==0?temp2:min(temp1,temp2);


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

	
	cin>>n>>k>>a>>b;
	// dp[0]=0;
	// dp[1]=0;
	// for(int i=1;i<=n;i++)
	// {
	// 	dp[i]=min(dp[i],dp[i-1]+a);
	// 	if(i*k<=n)
	// 	{
	// 		dp[i*k]=min(dp[i*k],dp[i]+b);
	// 	}
		
	// }
	//for(int i=0;i<=n;i++)
	//	cout<<dp[i]<<" ";
	cost=0;
	cout<<recursive(n);
	
}