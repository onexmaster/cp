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
	int mn=101;
	int min_in,max_in;
	int mx=-1;
	vector<int>v(t);
	for(int i=0;i<t;i++)
	{
		cin>>v[i];
		if(v[i]<=mn)
		{
			mn=v[i];
			min_in=i;
		}
		if(v[i]>mx)
		{
			mx=v[i];
			max_in=i;
		}
	}
	if(min_in>max_in)
		cout<<(t-min_in-1)+(max_in);
	else
		cout<<(t-min_in-1)+(max_in)-1;
	
}