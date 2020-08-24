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
bool can_get(vector<ll>prefix,ll k, ll sum)
{
	ll left=0;
	ll right=k;
	while(right<prefix.size())
	{
		if(prefix[right]-prefix[left]>sum)
			return false;
		else
		{
			left++;
			right++;
		}

	}
	return true;
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

	ll n,x;
	cin>>n>>x;
	vector<ll>v(n);
	for(ll i=0;i<n;i++)
		cin>>v[i];
	vector<ll>prefix(n+1);
	prefix[0]=0;
	for(ll i=1;i<=n;i++)
		prefix[i]=prefix[i-1]+v[i-1];
	//for(int i=0;i<prefix.size();i++)
	//	cout<<prefix[i]<<" ";
	ll l=0;
	ll h=n;
	ll ans=-1;
	while(l<=h)
	{
		ll mid=l+(h-l)/2;
		//cout<<mid<<endl;
		if(can_get(prefix,mid,x))
		{
			ans=mid;
			l=mid+1;
		}
		else
			h=mid-1;
	}
	cout<<ans;
	
}