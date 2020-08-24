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
	int i=1;
	ll f[1001];
	ll g[1001];
	ll h[1001];
	f[0]=g[0]=h[0]=1;
	f[1]=h[1]=1;
	g[1]=2;
	for(int i=2;i<1000;i++)
	{
		f[i]=f[i-2]+ f[i-1]+g[i-2]*2 +h[i-2];
		g[i]=f[i]+g[i-1];
		h[i]=f[i]+h[i-2];
	}
	while(t--)
	{
		int x;
		cin>>x;
		cout<<i<<" "<<f[x]<<endl;
		i++;
	}
	
}