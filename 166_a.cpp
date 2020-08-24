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

	int t,k;
	cin>>t>>k;
	vector<vector<int>>v;
	for(int i=0;i<t;i++)
	{
		vector<int>temp1;
		for(int i=0;i<2;i++)
		{
			int x;
			cin>>x;
			temp1.push_back(x);
		}
		v.push_back(temp1);
	}
	 map<pii,int>mp1;
	for(int i=0;i<t;i++)
	{
		mp1[mp(v[i][0],v[i][1])]++;
	}
	sort(v.begin(),v.end(),[](auto a, auto b)
	{
		if(a[0]>b[0])
			return 1;
		else if(a[0]<b[0])
			return 0;
		else
		{
			if(a[1]<b[1])
				return 1;
			else
				return 0;
		}
	});
	//for(int i=0;i<t;i++)
	//{
	//	cout<<v[i][0]<<" "<<v[i][1]<<endl;
	//}
	int a=v[k-1][0];
	int b=v[k-1][1];
	cout<<mp1[mp(a,b)]<<endl;

	
}