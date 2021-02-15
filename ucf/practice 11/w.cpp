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
    int n;
    cin>>n;
    char grid[n][n];
    for(int i=0;i<n;i++)
    {
        string st;
        cin>>st;
        for(int j=0;j<n;j++)
        {
            grid[i][j]=st[j];
        }
    }
        map<int,int>row,col;
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(grid[i][j]=='B')
                    row[i]++,col[j]++;
                else 
                    row[i]--,col[j]--;
            }
        }
        bool ok=true;
        for(auto it:row)
        {
            if(it.second!=0)
                ok=false;
        }
        for(auto it:col)
        {
            if(it.second!=0)
                ok=false;
        }
        //  if(!ok)
        // cout<<0;
        // else 
        // cout<<1;
        //check for incosistecny in rows
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<=n-3;j++)
            {
                if(grid[i][j]=='W' && grid[i][j+1]=='W' && grid[i][j+2]=='W')
                    ok=false;
                else if(grid[i][j]=='B' && grid[i][j+1]=='B' && grid[i][j+2]=='B')
                    ok=false;
            }
        }
        //check in cols
        for(int i=0;i<=n-3;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(grid[i][j]=='W' && grid[i+1][j]=='W' && grid[i+2][j]=='W')
                    ok=false;
                else if(grid[i][j]=='B' && grid[i+1][j]=='B' && grid[i+2][j]=='B')
                    ok=false;
            }
        }
        if(!ok)
        cout<<0;
        else 
        cout<<1;
return 0;
}