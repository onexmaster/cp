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
set<int>st;
ll found;
int looking;
map<int,ll>dp;
ll solve(int prev,set<int>st)
{
    if(prev==looking)
        return 1;

    if(dp.count(prev)>0)
        return dp[prev];
    //check the transitions states
    ll ways=0;
    if(st.find(prev+1)!=st.end())
    {
        ways+=solve(prev+1,st);
    }
    if(st.find(prev+2)!=st.end())
    {
        ways+=solve(prev+2,st);
    }
    if(st.find(prev+3)!=st.end())
    {
        ways+=solve(prev+3,st);
    } 
    return dp[prev]=ways;
}
int main()
{
        FIO;
    #ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    #endif
    vector<ll>temp;
    ll x;
    while(cin>>x)
    {
        temp.pb(x);
    }
    sort(temp.begin(),temp.end());
    vector<int>init(4,0);
    int prev=0;
    for(int i=0;i<temp.size();i++)
    {
        if(temp[i]-prev==0)
        {
            init[0]++;
            prev=temp[i];
        }
        else if(temp[i]-prev==1)
        {
            init[1]++;
            prev=temp[i];
        }
        else if(temp[i]-prev==2)
        {
            init[2]++;
            prev=temp[i];
        }
        else if(temp[i]-prev==3)
        {
            init[3]++;
            prev=temp[i];
        }
        else 
        {
            break;
        }

    }
    found=0;
    looking=temp[temp.size()-1]+3;
    temp.pb(looking);
    set<int>st(temp.begin(),temp.end());
    solve(0,st);
   cout<<dp[0];


return 0;
}