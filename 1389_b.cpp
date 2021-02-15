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
const int MAXN=1e5+5;
int arr[MAXN];
int dp[MAXN][6][2];
int n,k,z;

int solve(int index,int max_left_allowed, int can_move_left, int total_moves_left)
{
	if(total_moves_left==0)
		return arr[index];
	if(dp[index][max_left_allowed][can_move_left]!=-1)
		return dp[index][max_left_allowed][can_move_left];
	int best=0;
	//if we can go left
	if(index>0 && max_left_allowed>0 && can_move_left==1)
	{
		best=max(best,arr[index]+solve(index-1,max_left_allowed-1,0,total_moves_left-1));
	}
	//we can always go right
	best=max(best,arr[index]+solve(index+1,max_left_allowed,1,total_moves_left-1));
	return dp[index][max_left_allowed][can_move_left]=best;
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
		cin>>n>>k>>z;
		memset(arr,0,sizeof(arr));
		for(int i=0;i<n;i++)
		{
			for(int j=0;j<6;j++)
			{
				for(int k=0;k<2;k++)
					dp[i][j][k]=-1;
			}
		}
		for(int i=0;i<n;i++)
			cin>>arr[i];
		//index,max_left_allowed,can_move_left,total_moves_left)
		cout<<solve(0,z,0,k)<<endl;
	}

}