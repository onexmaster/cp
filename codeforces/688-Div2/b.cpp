// Created by Tanuj Jain
#include<bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;
#define pb push_back
#define mp make_pair
# define M_PI           3.14159265358979323846  /* pi */
#define FIO ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll,ll>pll;
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
        FIO;
    #ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    #endif
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        vector<ll>v(n);
        map<ll,vector<int>>occ;
        for(int i=0;i<n;i++)
            cin>>v[i],occ[v[i]].pb(i);
        
        if(occ.size()==1)
            cout<<0<<endl;
        else
        {
        
            //change the max_value;
           ll max_moves=0;
           for(int i=0;i<n-1;i++)
            max_moves+=abs(v[i+1]-v[i]);
        //every number an be changed to its neigbour
        ll ans=LLONG_MAX;
        //change the first number to 2nd
        ans=min(ans,max_moves-abs(v[1]-v[0]));
        //cout<<ans<<endl;
        //change the last nunnber to second last;
        ans=min(ans,max_moves-abs(v[n-1]-v[n-2]));
        for(int i=1;i<n-1;i++)
        {
            ll local1=max_moves;
            ll local2=max_moves;
            //change the number to i+1;
            local1-=abs(v[i+1]-v[i]);
            local1-=abs(v[i-1]-v[i]);
            local1+=abs(v[i+1]-v[i-1]);
            //chancge the number to i-1;
            local2-=abs(v[i]-v[i-1]);
            local2-=abs(v[i+1]-v[i]);
            local2+=abs(v[i+1]-v[i-1]);
            ans=min(ans,min(local1,local2));   
        }
        cout<<ans<<endl;
        
            

        }
    }

return 0;
}