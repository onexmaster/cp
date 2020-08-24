//Does not work.

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

	int n,k,m;
	cin>>n>>k>>m;
	vector<string>v(n);
	for(int i=0;i<n;i++)
		cin>>v[i];
	unordered_map<string,int>ma;
	for(int i=0;i<n;i++)
	{
		int x;
		cin>>x;
		ma[v[i]]=x;
	}
	for(int i=0;i<k;i++)
	{
		int x;
		cin>>x;
		int y;
		cin>>y;
		vector<int>temp(y);
		for(int j=0;j<y;j++)
				cin>>temp[j];
		if(x>=2)
		{
			int mn=INT_MAX;
			for(int j=0;j<y;j++)
				mn=min(mn,ma[v[temp[j]-1]]);
			for(int j=0;j<y;j++)
				ma[v[temp[j]-1]]=mn;
		}
	}
	vector<string>v1(m);
	for(int i=0;i<m;i++)
		cin>>v1[i];
	for(int i=0;i<m;i++)
		cout<<v1[i]<<" ";
	int cost=0;
	for(int i=0;i<m;i++)
		cost+=ma[v1[i]];
	cout<<cost;
}