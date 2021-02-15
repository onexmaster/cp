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
    
    int N; cin >> N;
    map<int, int> mp;
	array<int, 9> cnt; cnt.fill(0);
	while (N--) {
		int a; cin >> a;
		int& v = mp[a];
		cnt[min(v, 8)]--;
		v++;
		cnt[min(v, 8)]++;
	}
	int Q;cin >> Q;
	while (Q--) {
		char c; cin >> c; int a; cin >> a;
		int& v = mp[a];
		cnt[min(v, 8)]--;
		if (c == '+') v++;
		else if (c == '-') v--;
		else assert(false);
		cnt[min(v, 8)]++;
 
		bool res = (cnt[4]+cnt[5]+cnt[6]+cnt[7]+cnt[8] >= 1 && cnt[2]+cnt[3]+2*cnt[4]+2*cnt[5]+3*cnt[6]+3*cnt[7]+4*cnt[8] >= 4);
		cout << (res ? "YES" : "NO") << '\n';
	}
 
	return 0;

    

return 0;
}