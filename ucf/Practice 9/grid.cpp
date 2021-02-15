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
      
    // #ifndef ONLINE_JUDGE
    // freopen("input.txt","r",stdin);
    // freopen("output.txt","w",stdout);
    // #endif
    int n,m;
    cin>>n>>m;
    int grid[n][m];
    for(int i=0;i<n;i++)
    {
        string s;
        cin>>s;
        for(int j=0;j<s.size();j++)
        {
            grid[i][j]=s[j]-'0';
        }
    }
    map<pii,vector<pii>>ada;
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++){
        int k=grid[i][j];
        if(grid[i][j]==0)
        continue;
        int currx=i;
        int curry=j;
        //go k steps down
        int new_x=currx+k;
        int new_y=curry;
        if(new_x>=0 && new_x<n && new_y>=0 && new_y<m)
        ada[{currx,curry}].pb({new_x,new_y});
        //go k steps right
        new_x=currx;
        new_y=curry+k;
        if(new_x>=0 && new_x<n && new_y>=0 && new_y<m)
        ada[{currx,curry}].pb({new_x,new_y});
        //go k steps up
         new_x=currx-k;
         new_y=curry;
        if(new_x>=0 && new_x<n && new_y>=0 && new_y<m)
        ada[{currx,curry}].pb({new_x,new_y});
        //go k steps left
         new_x=currx;
         new_y=curry-k;
        if(new_x>=0 && new_x<n && new_y>=0 && new_y<m)
        ada[{currx,curry}].pb({new_x,new_y});
        }
    }
    //run bfs
    set<pair<int,int>>vis;
    vector<vector<int>>dist(n,vector<int>(m,INF));
    queue<pair<int,int>>q;
    q.push({0,0});
    dist[0][0]=0;
    while(!q.empty())
    {
        int curr_x=q.front().first;
        int curr_y=q.front().second;
        q.pop();
        for(auto edges:ada[{curr_x,curr_y}])
        {
           if(vis.count({edges})==0)
           {
               q.push(edges);
               dist[edges.first][edges.second]=dist[curr_x][curr_y]+1;
               vis.insert(edges);
           } 
        }

    }
    int ans=dist[n-1][m-1];
    if(ans==INF)
    cout<<"-1";
    else 
    cout<<ans;
    
return 0;
}