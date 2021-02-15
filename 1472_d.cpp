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
        for(int i=0;i<n;i++)
            cin>>v[i];
        vector<ll>even,odd;
        for(int i=0;i<n;i++)
            if(v[i]%2==0)
                even.pb(v[i]);
            else 
                odd.pb(v[i]);
            sort(even.rbegin(),even.rend());
            sort(odd.rbegin(),odd.rend());
        ll alice=0,bob=0;
        int i=0;
        int j=0;
        int x=even.size();
        int y=odd.size();
        int turn=0;
        //0 means alice 
        //1 means bob
        while(i<x && j<y)
        {
            if(turn==0)
            {
                if(even[i]>=odd[j])
                    alice+=even[i],i++;
                else 
                    j++;
                turn=1;
            }
            else
            {
                if(odd[j]>=even[i])
                    bob+=odd[j],j++;
                else 
                    i++;
                turn=0;
            }
        }
        while(i<x)
        {
            if(turn==0)
            {
                alice+=even[i];
                i++;
                turn=1;
            } 
           else
           {
               i++;
               turn=0;
           }
           
        }
          while(j<y)
        {
            if(turn==1)
            {
                bob+=odd[j];
                j++;
                turn=0;
            } 
           else
           {
               j++;
               turn=1;
           }
           
        }
        if(alice>bob)
        {
            cout<<"Alice"<<endl;
        }
        else if(bob>alice)
        {
            cout<<"Bob"<<endl;
        }
        else
        {
            cout<<"Tie"<<endl;
        }
        

    }

return 0;
}