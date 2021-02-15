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
int moves[8][2]={{0,1},{0,-1},{1,0},{-1,0},{1,1},{-1,-1},{1,-1},{-1,1}};
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
    int n,m,b;
    cin>>m>>n>>b;
    vector<vector<long double>>grid(n+2,vector<long double>(m+2,0.0));
    for(int i=1;i<=n;i++)
        for(int j=1;j<=m;j++)
        cin>>grid[i][j];
    for(int k=0;k<b;k++)
    {
       
        vector<vector<long double>>temp(n+2,vector<long double>(m+2,0.0));
                //fill the remaning ele
        for(int i=1;i<=n;i++)
        {
            for(int j=1;j<=m;j++)
            temp[i][j]=grid[i][j];
        }
        //fill the top row
        for(int i=1;i<=m;i++)
            temp[0][i]=grid[n][i];
        //fill the bottom row
        for(int i=1;i<=m;i++)
            temp[n+1][i]=grid[1][i];
        //fill the left col from the temp matrix
        for(int i=0;i<=n+1;i++)
            temp[i][0]=temp[i][m];
            
        //fill the right col
        for(int i=0;i<=n+1;i++)
            temp[i][m+1]=temp[i][1];

        // //print the grid
        // for(int i=0;i<=n+1;i++)
        // {
        //     for(int j=0;j<=m+1;j++)
        //     cout<<temp[i][j]<<" ";
        //     cout<<endl;
        // }
        

        //do the average
        for(int i=1;i<=n;i++)
        {
            for(int j=1;j<=m;j++)
            {
                long double curr_val=temp[i][j];
                int curr_x=i;
                int curr_y=j;
                for(int a=0;a<8;a++)
                {
                    int new_x=curr_x+moves[a][0];
                    int new_y=curr_y+moves[a][1];
                    curr_val+=temp[new_x][new_y];
                }
                grid[i][j]=curr_val;
            }
        }
        // //print the grid
        // for(int i=0;i<=n+1;i++)
        // {
        //     for(int j=0;j<=m+1;j++)
        //     cout<<grid[i][j]<<" ";
        //     cout<<endl;
        // }
    }
    set<long double>st;
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=m;j++)
        st.insert(grid[i][j]);
    }
    cout<<int(st.size())<<endl;

return 0;
}