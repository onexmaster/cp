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
	int one=0;
	int two=0;
	vector<int>v(t);
	for(int i=0;i<t;i++)
	{
		cin>>v[i];
		if(v[i]==1)
			one++;
		else
			two++;
	}
	if(one==0)
		for(int i=0;i<two;i++)
			cout<<2<<" ";
	else if(two==0)
		for(int i=0;i<one;i++)
			cout<<1<<" ";
	else
	{
		cout<<2<<" "<<1<<" ";
		for(int i=1;i<two;i++)
			cout<<2<<" ";
		for(int i=1;i<one;i++)
			cout<<1<<" ";
	}

	

}