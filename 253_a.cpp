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

	//n- boys
	//m- girls
	int n,m;
	cin>>n>>m;
	string ans;
	if(n>m)
	{	
			while(n && m)
			{
				ans.append("BG");
				n--;
				m--;	
			}
			while(n)
			{
				ans.append("B");
				n--;
			}
	}
	else
	{
		while(m && n)
			{
				ans.append("GB");
				n--;
				m--;	
			}
			while(m)
			{
				ans.append("G");
				m--;
			}
	}
	cout<<ans<<endl;
	return 0;
}