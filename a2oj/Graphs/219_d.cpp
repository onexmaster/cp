// Created by Tanuj Jain
#include<bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;
#define pb push_back
#define mp make_pair
typedef long long ll;
typedef pair<int,int> pii;
template<class T> using oset=tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
const int INF = 0x3f3f3f3f;
int knight_moves[8][2]={{-2,-1},{-1,-2},{1,-2},{2,-1},{-2,1},{-1,2},{1,2},{2,1}};
int moves[4][2]={{0,1},{0,-1},{1,0},{-1,0}};
const int maxn  =   200005;

int f[maxn],g[maxn],n;
vector<pair<int,int> > adj[maxn];
 
inline void calc(int u,int fa)
{
    for (int i=0;i<adj[u].size();++i){
        int v=adj[u][i].first,cost=adj[u][i].second;
        if (v==fa) continue;
        g[v]=g[u]-cost+(1-cost);
        calc(v,u);
    }
}
 
inline void dfs(int u,int fa)
{
    f[u]=0;
    for (int i=0;i<adj[u].size();++i){
        int v=adj[u][i].first,cost=adj[u][i].second;
        if (v==fa) continue;
//printf("%d %d\n",u,v);
        dfs(v,u);
        f[u]+=f[v]+cost;
    }
}
 
int main()
{
	ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

	#ifndef ONLINE_JUDGE
	freopen("inputf.in","r",stdin);
	freopen("outputf.in","w",stdout);
	#endif
    scanf("%d",&n);
    for (int i=1;i<n;++i){
        int a,b;
        scanf("%d%d",&a,&b);
        --a;--b;
        adj[a].push_back(make_pair(b,0));
        adj[b].push_back(make_pair(a,1));
    }
    
    dfs(0,-1);
    // for(int i=0;i<n;i++)
    // 	cout<<f[i]<<" ";
    g[0]=f[0];
    cout<<endl;
    calc(0,-1);
    // for(int i=0;i<n;i++)
    // 	cout<<g[i]<<" ";
    int ans=*min_element(g,g+n);
    printf("%d\n",ans);
    for (int i=0;i<n;++i)
    if (g[i]==ans){
        printf("%d ",i+1);
    }
    
    return 0;
}
	