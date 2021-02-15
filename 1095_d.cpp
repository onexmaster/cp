// Created by Tanuj Jain
#include<bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;
#define pb push_back
#define mp make_pair
#define forn(i,n) forr(i,0,n)
#define forr(i,x,n) for(int i=(x); i<int(n); i++)
typedef long long ll;
typedef pair<int,int> pii;
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
/*
If the I kid remembers kids A and B in front of him, that means I is before A and B, so we draw two directed edges I->A, I->B.

There is an order to be decided between A and B that we don't know of yet, so we also draw a pointed line A---B between them.

When all the lines have been drawn, we iterate over each directed edge U->V, and if there was a pointed line U---V, then i assume the order U->V is indeed correct, so we add this directed edge U->V to an answer graph G. Note that there might be multiple solutions, so U->V and V->U might end up existing at the same time.

When we finished generating this answer graph G, visit all the nodes, starting from 0 and going to a any non-visited neighbor that we can go to through an edge
*/
const ll MAXN = 2 * 1e5 + 5;
ll N;
vector<int> G[MAXN];
set<int> D[MAXN], F[MAXN];
int main()
{
	ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

	#ifndef ONLINE_JUDGE
	freopen("inputf.in","r",stdin);
	freopen("outputf.in","w",stdout);
	#endif

	cin >> N;
    int u, v;
    forn(i,N){
        cin >> u >> v; u--, v--;
        D[i].insert(u); D[i].insert(v);
        F[u].insert(v); F[v].insert(u);
    }
    forn(i,N) for(auto &v : D[i]) if(F[i].count(v)) G[i].pb(v);
    vector<int> vis(N,0);
    u = 0;
    forn(i,N){
        cout << u+1 << ' ';
        vis[u] = 1;
        for(auto &x : G[u]) if(!vis[x]){ u = x; break; }
    }
 
    return 0;

}