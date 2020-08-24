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
	bool vis[3005];
	for(int i=0;i<3005;i++)
		vis[i]=false;
	for(int i=0;i<t;i++)
	{
		int x;
		cin>>x;
		vis[x]=true;
	}
	for(int i=1;i<=3005;i++)
		if(!vis[i])
			{
				cout<<i;
				return 0;
			}
}