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

	ll n,k;
	cin>>n>>k;
	vector<ll>v(n);
	for(int i=0;i<n;i++)
		cin>>v[i];
	
	ll slow=0;
	ll fast=0;
	set<ll>st;
	vector<int>vis;
	vis.pb(0);
	do{
		slow=v[slow]-1;
			vis.pb(slow);
			st.insert(slow);
		fast=v[v[fast]-1]-1;
			vis.pb(fast);
			st.insert(fast);
		//st.insert(fast);
	}
	while(slow!=fast);

	for(int i=0;i<vis.size();i++)
		cout<<vis[i];

	ll rem=k%(vis.size());
	//set<ll>::iterator itr=st.begin();
	//advance(itr,rem);
	cout<<vis[rem]+1<<endl;
}