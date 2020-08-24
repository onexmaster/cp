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

	int n,m;
	cin>>n>>m;
	vector<int>v(n);
	for(int i=0;i<n;i++)
		cin>>v[i];
	int suffix[n]={};
	unordered_set<int>st;
	suffix[n-1]=1;
	st.insert(v[n-1]);
	for(int i=n-2;i>=0;i--)
	{
		suffix[i]=suffix[i+1];
		if(st.find(v[i])==st.end())
		{
			suffix[i]++;
			st.insert(v[i]);
		}
	}
	for(int i=0;i<n;i++)
		cout<<suffix[i]<<" ";
	cout<<endl;
	while(m--)
	{
		int x;
		cin>>x;
		cout<<suffix[x-1]<<endl;

	}
	
}	