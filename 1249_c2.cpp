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
	vector<ll>arr(51);
	arr[0]=1;
	for(int i=1;i<51;i++)
	{
		arr[i]=arr[i-1]*3;
	}
	vector<int>prefix(51);
	prefix[0]
	int t;
	cin>>t;
	while(t--)
	{
		ll x;
		cin>>x;
		if(binary_search(arr.begin(),arr.end(),x))
		{

			ll pos=upper_bound(arr.begin(),arr.end(),x)-arr.begin()-1; 
			cout<<arr[pos]<<endl;
		}
		else
		{
			ll pos=upper_bound(arr.begin(),arr.end(),x)-arr.begin();
			cout<<arr[pos]<<endl;
		}

	}
	
}