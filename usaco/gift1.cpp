/* Use the slash-star style comments or the system won't see your
   identification information */
/*
ID: onexmas1
TASK: gift1
LANG: C++                 
*/
/* LANG can be C++11 or C++14 for those more recent releases */
// Created by Tanuj Jain
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
    freopen("gift1.in","r",stdin);
    freopen("gift1.out","w",stdout);
    #endif
    int n;
    cin>>n;
    vector<string>names;
    map<string,int>mp;
    for(int i=0;i<n;i++)
    {
        string x;
        cin>>x;
        names.pb(x);
        mp[x]=0;
    }
    string giver;
    while(cin>>giver)
    {
        ll amount,m;
        cin>>amount>>m;
        ll quo;
        ll rem;
        if(amount>0 && m>0)
        {
            quo=amount/m;
            rem=amount%m;
        }
         else if(amount==0)
         {
            quo=0;
            rem=0;
         }
        else
        {
            amount=0;
            rem=amount;
        }
        mp[giver]-=amount;
        mp[giver]+=rem;
        while(m--)
        {
            string rec;
            cin>>rec;
            mp[rec]+=quo;
        }
    }
    for(int i=0;i<n;i++)
    cout<<names[i]<<" "<<mp[names[i]]<<endl;

return 0;
}