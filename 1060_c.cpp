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
const int INF = 0x3f3f3f3f;
int knight_moves[8][2]={{-2,-1},{-1,-2},{1,-2},{2,-1},{-2,1},{-1,2},{1,2},{2,1}};
int moves[4][2]={{0,1},{0,-1},{1,0},{-1,0}};
struct custom_hash {
    static uint64_t splitmix64(uint64_t x) {
        // http://xorshift.di.unimi.it/splitmix64.c
        x += 0x9e3779b97f4a7c15;
        x = (x ^ (x >> 30)) * 0xbf58476d1ce4e5b9;
        x = (x ^ (x >> 27)) * 0x94d049bb133111eb;
        return x ^ (x >> 31);
    }

    size_t operator()(uint64_t x) const {
        static const uint64_t FIXED_RANDOM = chrono::steady_clock::now().time_since_epoch().count();
        return splitmix64(x + FIXED_RANDOM);
    }
};
int main()
{
	ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

	#ifndef ONLINE_JUDGE
	freopen("inputf.in","r",stdin);
	freopen("outputf.in","w",stdout);
	#endif

	ll n,m,x;
    cin>>n>>m;
    ll a[n+1],b[m+1],p[n+1],q[m+1];
    a[0]=0;
    b[0]=0;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
    }
    for(int i=1;i<=m;i++)
    {
        cin>>b[i];
    }
    cin>>x;
    //find prefix sum in a 
    for(int i=1;i<=n;i++)
    {
        a[i]+=a[i-1];
    }
    //find prefix sum in b
    for(int j=1;j<=m;j++)
    {
        b[j]+=b[j-1];
    }
    //find the min value for each subarray size(1...2..3...n) in a
    for(int i=1;i<=n;i++)
    {
        ll ans=INT_MAX;
        for(int j=0;j<=n-i;j++)
        {
            ans=min(ans,a[j+i]-a[j]);
        }
        p[i]=ans;
    }
    //find the min value for each subarray size in b
    for(int i=1;i<=m;i++)
    {
        ll ans=INT_MAX;
        for(int j=0;j<=m-i;j++)
        {
            ans=min(ans,b[j+i]-b[j]);
        }
        q[i]=ans;
    }
    ll ans=INT_MIN;
 	//try every pair of value 
    for(ll i=1;i<=n;i++)
    {
        for(ll j=1;j<=m;j++)
        {
            if(p[i]*q[j]<=x)
            {
                ans=max(ans,i*j);
            }
        }
    }
    if(ans==INT_MIN)
    {
        cout<<"0\n";
        return 0;
    }
    cout<<ans<<"\n";
}