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
int main()
{
	ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

	#ifndef ONLINE_JUDGE
	freopen("inputf.in","r",stdin);
	freopen("outputf.in","w",stdout);
	#endif

	
	int n;
	cin >> n;
 
	string s;
	cin >> s;
 	//only 2 possible coloring can be obtained
 	//rbrbrbrbr or brbrbrbrbr
 	//find the answer to get both the colouring and take the min of those two
	int r = 0, b = 0;
	for(int i=0;i<s.size();i++){
		if(i%2==0)
			r += (s[i] != 'r');
		else
			b += (s[i] != 'b');
	}
	//ans for each coloring if max of r and b coz
	//min(r,b) can be swapped and the remaining have to colored 
	//so the remaining numebers are max(a,b)-min(a,b)
	//hene the total is min(a,b)+max(a,b)-min(a,b) which is max(a,b);
 
	int ans = max(r, b);
 
	r = 0, b = 0;
	for(int i=0;i<s.size();i++){
		if(i%2)
			r += (s[i] != 'r');
		else
			b += (s[i] != 'b');
	}
	ans = min(ans, max(r, b));
 
	cout << ans << endl;
	return 0;

}