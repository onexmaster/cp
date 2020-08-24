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
	vector<int>v(t);
	bool isodd=false;
	int sum=0;
	int min_odd=INT_MAX;
	for(int i=0;i<t;i++)
		cin>>v[i];
	for(int i=0;i<t;i++)
	{
		if(v[i]>0)
			sum+=v[i];
		if(v[i]&1)
		{
			isodd=true;
			min_odd=min(min_odd,abs(v[i]));

		}
	}
	if(sum&1)
		cout<<sum;
	else
		cout<<sum-min_odd;
	
}