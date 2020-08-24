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


int testnum;
int l,r;
ll sum;
vector<ll> lucky;
 
void preprocess()
{
 
}
 
ll ovlap(ll a,ll b,ll c,ll d)
{
	if(c>b || d<a) return 0;
	ll lo = max(a,c);
	ll hi = min(b,d);
	return hi-lo+1;
}
 
void gen(ll cur)
{
	//cout<<cur<<endl;
	if(cur > 1e10) return;
	lucky.pb(cur);
	gen(cur*10+4);
	gen(cur*10+7);
}
 
void solve()
{
	sum=0;
	gen(0);
	sort(lucky.begin(),lucky.end());
	
	for(int i=0;i+1<lucky.size();i++)
		sum += ovlap(l,r,lucky[i]+1,lucky[i+1]) * lucky[i+1];
	cout<<sum<<endl;
}
 
bool input()
{
	
	cin>>l>>r;
	return true;
}
 
 
int main()
{
	preprocess();
	int T=1;
	for(testnum=1;testnum<=T;testnum++)
	{
		if(!input()) break;
		solve();
	}
}