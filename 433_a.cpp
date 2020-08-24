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

	ll n,i,m[10000],a[10000];
	cin>>n;
 
	for(i=0;i<n;i++){
		cin>>a[i];
		m[a[i]]++;
	}
	if(m[100]%2==1){
		cout<<"NO";
		return 0;
	}
	if(m[200]%2==1 and m[100]<2){
		cout<<"NO";
		return 0;
	}
	cout<<"YES";
	return 0;
	
}