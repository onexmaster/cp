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
	
	int m;
	cin>>m;
	int mx=0;
	vector<int>v(t);
	for(int i=0;i<t;i++)
	{
		cin>>v[i];
		mx=max(mx,v[i]);
	}
	priority_queue<int, vector<int>, greater<int>>pq(v.begin(),v.end());
	int ans2=mx+m;
	while(m>0)
	{
		int x=pq.top();
		pq.pop();
		x++;
		pq.push(x);
		m--;
	}
	while(pq.size()>=1)
	{
		pq.pop();
	}
	cout<<pq.top()<<" "<<ans2<<endl;
}