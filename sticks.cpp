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
//HINT: DP
//https://www.youtube.com/watch?v=kMxYxBdzqEQ
int memo[105][105];
int solve(int start_index, int end_index,vector<int>&v)
{
	if(start_index+1==end_index)
		return 0;
	if(memo[start_index][end_index]!=-1)
		return memo[start_index][end_index];

	int ans=INT_MAX;
	for(int i=start_index+1;i<end_index;i++)
	{
		ans=min(ans,solve(start_index,i,v)+solve(i,end_index,v)+v[end_index]-v[start_index]);
	}
	return memo[start_index][end_index]=ans;
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
		memset(memo,-1,sizeof(memo));
		//best_ans=INT_MAX;
		int length;
		cin>>length;
		int n;
		cin>>n;
		std::vector<int> v(n+2);
		//0 stores 0, N+1 stores full length
		v[0]=0;
		for(int i=1;i<=n;i++)
			cin>>v[i];
		v[n+1]=length;
		//for(int i=0;i<v.size();i++)
		//	cout<<v[i]<<" ";
		cout<<solve(0,n+1,v)<<endl;
	}

}