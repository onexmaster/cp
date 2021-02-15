// Created by Tanuj Jain
#include<bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;
#define pb push_back
#define mp make_pair
#define F first
#define S second
typedef long long ll;
typedef int ii;
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
ll W(int x1, int y1, int x2, int y2) {
    ll tot = (x2-x1+1)*1LL*(y2-y1+1);
    if (tot % 2 == 1 and (x1+y1) % 2 == 0) return tot / 2 + 1;
    return tot / 2;
}
 
ll B(int x1, int y1, int x2, int y2) {
    ll tot = (x2-x1+1)*1LL*(y2-y1+1);
    return tot - W(x1, y1, x2, y2);
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

	int t;
	cin>>t;
	while(t--)
	{

 		int n, m; cin >> n >> m;
        int x1, y1, x2, y2; cin >> x1 >> y1 >> x2 >> y2;
        int x3, y3, x4, y4; cin >> x3 >> y3 >> x4 >> y4;
        ll w = W(1, 1, m, n) + B(x1, y1, x2, y2) - W(x3, y3, x4, y4);
 
        pair<ii, ii> ints(ii(max(x1, x3), max(y1, y3)), ii(min(x2, x4), min(y2, y4)));
 
        if (ints.S.F >= ints.F.F and ints.S.S >= ints.F.S) {
            w -= B(ints.F.F, ints.F.S, ints.S.F, ints.S.S);
        }
 
        cout << w << " " << n*1LL*m - w << "\n";

   }
    return 0;
}