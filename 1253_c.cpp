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

	
    int n, m; cin>>n>>m; 
    vector<ll> a(n), dp(n); 
    for(int i = 0;i < n; ++i)cin>>a[i]; 
    sort(a.begin(),a.end()); 
    long long sum = 0; 
    for(int i = 0;i < n; ++i){
        dp[i] += a[i]; 
        if(i - m >= 0)dp[i] += dp[i - m]; 
        sum += dp[i]; 
        cout<<sum<<" "; 
    }
    cout<<"\n"; 
 
    return 0;
	
}