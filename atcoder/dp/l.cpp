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

ll dp[3005][3005];
bool vis[3005][3005];
int N;
ll values[3005];

ll recursive(int start, int end)
{
	//cout<<start<<" "<<end<<endl;
	//base case
	if(start==end)
		return dp[start][end]=values[start];
	if(end==start+1)
		return dp[start][end]=max(values[end],values[start]);
	if(vis[start][end])
		return dp[start][end];
	//mark it as visited and find the value
	vis[start][end]=true;
	//I have 2 options choose the starting or to choose from the end
	//If i choose the starting value, then the next value i can get is 
	return dp[start][end]=max(values[start]+ min(recursive(start+2,end),recursive(start+1,end-1)),
								values[end]+ min(recursive(start+1,end-1),recursive(start,end-2)));
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

	cin>>N;
	ll sum=0;
	for(int i=1;i<=N;i++)
	{
		cin>>values[i];
		sum+=values[i];
	}
	ll x=recursive(1,N);
	ll y=sum-x;
	//cout<<x<<" "<<y<<" "<<sum<<endl;
	cout<<x-y;
	
}