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
int n,r;
int memo[1009][1009];
vector<int>idx;
int solve(int curr, int pos)//pos is the last idx we cant heat
{
	//if all the elemnts are heated then return 0;
	if(pos>n)
		return 0;
	if(curr==int(idx.size()))
	{
		if(pos>n)
			return 0;
		else
			return INF;
	}
	if(memo[curr][pos]!=-1)
		return memo[curr][pos];
	//for the current index find the lowest and the highest index we can heat
	int low=idx[curr]-r+1;
	int high=idx[curr]+r-1;
	//if the lowest point is less than the last idx which we cannot heat
	//it means we can heat the idx pos
	//we have 2 choice 
	if(low<=pos)
	{
		//if we use this heater then the pos which we cannot heat becomes high +1
		int path_1=1+solve(curr+1,high+1);
		//leave the heater
		int path_2=solve(curr+1,pos);
		memo[curr][pos]=min(path_1,path_2);
	}
	else
		memo[curr][pos]=INF;
	return memo[curr][pos];
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

	memset(memo,-1,sizeof(memo));
	cin>>n>>r;
	for(int i=1;i<=n;i++)
	{
		int x;
		cin>>x;
		if(x)
			idx.pb(i);
	}
	//pass the index of the first heater and the first point which we cannot heat
	int ans=solve(0,1);
	if(ans==INF)
		cout<<-1<<endl;
	else
		cout<<ans<<endl;
}