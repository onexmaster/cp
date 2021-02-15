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
const int N = 1e5 + 10;

int n, color, ans, mx, f[N], cnt[N];
int main()
{
	ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

	#ifndef ONLINE_JUDGE
	freopen("inputf.in","r",stdin);
	freopen("outputf.in","w",stdout);
	#endif

	scanf("%d", &n);
	for (int i = 1; i <= n; i++)
    {
        scanf("%d", &color);
        cnt[f[color]]--;
        f[color]++;
        cnt[f[color]]++;
        mx = max(mx, f[color]);
        bool ok = false;
        if (cnt[1] == i) // every color has occurence of 1
            ok = true;
        else if (cnt[i] == 1) // only one color has the maximum occurence and the occurence is i
            ok = true;
        else if (cnt[1] == 1 && cnt[mx] * mx == i - 1) // one color has occurence of 1 and other colors have the same occurence
            ok = true;
        else if (cnt[mx - 1] * (mx - 1) == i - mx && cnt[mx] == 1) // one color has the occurence 1 more than any other color
            ok = true;
        if (ok)
            ans = i;
    }
    printf("%d", ans);
	return 0;
}