// Created by Tanuj Jain
#include<bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;
#define pb push_back
#define mp make_pair
# define M_PI           3.14159265358979323846  /* pi */
#define OJ \
    freopen("input.txt", "r", stdin); \
    freopen("output.txt", "w", stdout);
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
set<pii>cmp;
int n,m;
char grid[15][15];
void dfs(int x, int y)
{
    cmp.insert({x,y});
    for(int i=0;i<4;i++)
    {
        int newx=x+moves[i][0];
        int newy=y+moves[i][1];
        if(newx>=0 && newx<n && newy>=0 && newy<m && cmp.find({newx,newy})==cmp.end() && grid[newx][newy]=='_' || grid[newx][newy]=='P')
            dfs(newx,newy);
    }
}
int main()
{
FIO;
int t;
cin>>t;

while(t--)
{
    for(int i=0;i<15;i++)
    {
        for(int j=0;j<15;j++)
        grid[i][j]='_';
    }
    cin>>n>>m;
    int px,py,cx,cy;
    for(int i=0;i<n;i++)
    {
        string temp;
        cin>>temp;
        for(int j=0;j<temp.size();j++)
        {
            grid[i][j]=temp[j];
            if(grid[i][j]=='P')
                px=i,py=j;
            else if(grid[i][j]=='C')
                cx=i,cy=j;
        }
    }
    cmp.clear();
        dfs(cx,cy);
        if(cmp.find({px,py})!=cmp.end())
            cout<<"yes"<<endl;
        else
        {
            cout<<"no"<<endl;
        }
   

}
getchar();
return 0;
}