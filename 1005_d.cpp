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
string st;
const int N=2e5+6;
int memo[N][3];
int solve(int idx, int mod)
{
	if(idx==st.length())
		return 0;
	if(memo[idx][mod]!=-1)
		return memo[idx][mod];
	int curr_mod=(st[idx]-'0')%3;
	int ans=0;
	//if adding the new mod plus the old mod is divisble by 3 becomes divisble by 3 then break here
	//the new mod becomes 0
	if((mod+curr_mod)%3==0)
		ans=1+solve(idx+1,0);
	else
		//if it still not divisible
		//i have two options 
		//1-Not break here and pass the curr_mod
		//2-Break here and then the new mod becomes 0
		//take the max of both
		ans=max(solve(idx+1,(mod+curr_mod)%3),solve(idx+1,0));
	return memo[idx][mod]=ans;


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
	cin>>st;
	memset(memo,-1,sizeof(memo));
	cout<<solve(0,0);
	

}