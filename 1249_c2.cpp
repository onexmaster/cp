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
	while(t--)
	{
		ll n;
		cin>>n;
		ll cnum=1;
		ll cm=1;;
		while(cnum<n)
		{
			//3 9 27...
			cm*=3;
			cnum+=cm;
		}
		while(cm>=1)
		{
			if(cnum-cm>=n)
				cnum-=cm;
			//27,9,3,...
			cm/=3;
		}
		cout<<cnum<<endl;
	}
}