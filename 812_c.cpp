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

	ll n,t_s;
	cin>>n>>t_s;
	vector<ll>v(n);
	for(int i=0;i<n;i++)
		cin>>v[i];
	ll l=0;
	ll h=n;
	ll u=-1;
	ll mo=0;
	while(l<=h)
	{
		ll m=l+(h-l)/2;
		vector<ll>temp=v;
		for(int i=0;i<n;i++)
			temp[i]=temp[i]+((i+1)*m);
		ll sum=0;
		sort(temp.begin(),temp.end());
		for(int i=0;i<m;i++)
		{
			
				sum+=temp[i];
		}

		if(sum<=t_s)
		{
			u=m;
			l=m+1;
			mo=sum;
		}
		else
		{
			h=m-1;
		}

	}
	cout<<u<<" "<<mo;	
}