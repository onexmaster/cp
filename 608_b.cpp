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
char a[200005];
char b[200005];
int one[200005];
int zero[200005];
int l1,l2;
ll ans;
int main()
{
	ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

	#ifndef ONLINE_JUDGE
	freopen("inputf.in","r",stdin);
	freopen("outputf.in","w",stdout);
	#endif
	scanf("%s",a+1);
    scanf("%s",b+1);
    
    l1 = strlen(a+1);
    l2 = strlen(b+1);
    
    for(int i = 1; i <= l2; ++i) {
        one[i] = (one[i-1] + (b[i] == '1'));
        zero[i] = (zero[i-1] + (b[i] == '0')); 
    }
    for(int i = 1; i <= l1; ++i){
        int r = l1 - i;
        if(a[i] == '0') ans += (one[l2 - r] - one[i-1]);
        if(a[i] == '1') ans += (zero[l2 - r] - zero[i-1]);
    }
    cout << ans << '\n';
    return 0;
	

}