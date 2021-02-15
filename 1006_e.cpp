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
    freopen("inputf.in", "r", stdin); \
    freopen("outputf.in", "w", stdout);
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
//Adding the edges costs MLE: since we are using n^2 space, therefore need some smarter way 
//Rather than storing the vector of edges visited, just save time when each node was visited 
//So for each node save the component size(vector size of previous method) and time for each node
//so if 3 was visited first at 3, then its children are visited at 4,5,6,..etc
const int MAXN=2e5+5;
vector<int>ada[MAXN];
int sz[MAXN];//stors the size of subtree 
int intime[MAXN];//stores at which time which node was visited
int pos[MAXN];//stoes the time at which the node was visited
bool vis[MAXN];
int curr_time=1;

int dfs(int src)
{
    vis[src]=true;
    intime[curr_time]=src;
    pos[src]=curr_time;
    curr_time++;
    for(auto edges:ada[src])
    sz[src]+=dfs(edges);
    sz[src]++;
    return sz[src];

}
int main()
{
    OJ;
FIO;

    int n,q;
    cin>>n>>q;
    for(int i=1;i<=n-1;i++)
    {
        int x;
        cin>>x;
        ada[x].pb(i+1);
    }
    memset(vis,false,sizeof(vis));
    dfs(1);
    while(q--)
    {
        int u,k;
        cin>>u>>k;
        if(k>sz[u])
            cout<<-1<<endl;
        else
            cout<<intime[pos[u]+k-1]<<endl;        
    }

    
return 0;
}