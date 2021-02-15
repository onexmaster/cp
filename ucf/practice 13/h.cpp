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
    // #ifndef ONLINE_JUDGE
    // freopen("input.txt","r",stdin);
    // freopen("output.txt","w",stdout);
    // #endif
    ll t;
    set<ll>st;
    set<pair<int,int>>changes;
    map<int,vector<ll>>mapping;
    //for 2 changes
    for(int i=0;i<18;i++)
    {
        for(int j=i+1;j<18;j++)
        {
            changes.insert({i,j});
        }
    }
    
    while(cin>>t)
    {
        if(t==-1)
            break;
        st.insert(t);
    }
    for(auto it:st)
    {
        int t=it;
         bitset<18>b(t);
        for(auto change:changes)
        {
            int first=change.first;
            int second=change.second;
            bitset<18>temp=b;
            temp.flip(first);
            temp.flip(second);
             if(st.find(temp.to_ullong())!=st.end() && temp.to_ullong()>t)
            mapping[t].pb(temp.to_ullong());
        }
        //we can also make 1 change
        for(int i=0;i<18;i++)
        {
            bitset<18>temp=b;
            temp.flip(i);
              if(st.find(temp.to_ullong())!=st.end() && temp.to_ullong()>t)
                mapping[t].pb(temp.to_ullong());
        }
    }
    for(auto it:st)
    {
        if(mapping.find(it)!=mapping.end())
            cout<<it<<":"<<mapping[it].size()<<endl;
        else
        {
             cout<<it<<":"<<0<<endl;
        }
        
    }

return 0;
}