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
	for(int i=0;i<t;i++)
		cin>>v[i];
	int mx=v[0];
	int mn=v[0];
	int ama=0;
	for(int i=1;i<t;i++)
	{
		if(v[i]>mx)
		{
			mx=v[i];
			ama++;
		}
		else if(v[i]<mn)
		{
			mn=v[i];
			ama++;
		}
	}
	cout<<ama;
	
}