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

ll recursive(ll n, unordered_map<ll,ll>&memo)
{
	if(n<12)
		return n;
	if(memo.find(n)!=memo.end())
		return memo[n];
	//find the ans by dividing it in coins
	ll temp1=recursive(n/2,memo);
	ll temp2=recursive(n/3,memo);
	ll temp3=recursive(n/4,memo);
	return memo[n]=temp1+temp2+temp3;
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

	ll n;
	while(cin>>n)
	{
		unordered_map<ll,ll>memo;
		ll ans=recursive(n,memo);
		cout<<max(ans,n)<<endl;
	}
	
}