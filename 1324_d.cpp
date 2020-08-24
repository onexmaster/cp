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
	vector<int>a(t);
	vector<int>b(t);
	for(int i=0;i<t;i++)
		cin>>a[i];
	for(int i=0;i<t;i++)
		cin>>b[i];
	oset<pii> s;
	ll ans=0;
	for(int i=0;i<t;i++)
	{
		ans+=s.order_of_key({a[i]-b[i],0});
		s.insert({b[i]-a[i],i});
	}
	cout<<ans; 
	
}