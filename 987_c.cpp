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

	int n;
	cin>>n;
	vector<ll>s(n);
	vector<ll>c(n);
	for(int i=0;i<n;i++)
		cin>>s[i];
	for(int i=0;i<n;i++)
		cin>>c[i];
	ll ans=INT_MAX;
	for(int i=0;i<n;i++)
	{
		ll c1=INT_MAX;
		ll c2 =INT_MAX;
		for(int j=0;j<i;j++)
		{
			if(s[i]>s[j])
			{
				c1=min(c1,c[j]);
			}
		}
		for(int j=i+1;j<n;j++)
		{
			if(s[j]>s[i])
				c2=min(c2,c[j]);
		}
		ans=min(ans,c1+c2+c[i]);
	}
	if(ans==INT_MAX)
		cout<<-1;
	else
		cout<<ans;
	
}