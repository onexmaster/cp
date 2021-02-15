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
const int MAXN=4000;
int n,m,k;
int memo[MAXN][MAXN];
int arr[MAXN];
int solve(int i, int j ,int pos, int force)
{
	if(pos==m)
		return max(arr[i],arr[j]);
	if(memo[i][j]!=-1)
		return memo[i][j];
	//if i have the option to force
	int ans3;
	if(force)
	{	
		//force the person to take the leftmost index
		int ans1=solve(i+1,j,pos+1,force-1);
		//force the person to take the rightmost value
		int ans2=solve(i,j-1,pos+1,force-1);	
		//this is max becoz the people i can controll i can always get the max value 
		//because i can controll them, i will tell them to the min and max for me
		//hence the min ans is the max value
		ans3=max(ans1,ans2);
	}
	//if i do not have the option to force
	else
	{

		int ans1=solve(i+1,j,pos+1,force);
		int ans2=solve(i,j-1,pos+1,force);
		//but for the people i do not control , i cannot get the max value,
		//i need to consider the min values 
		ans3=min(ans1,ans2);
	}
	return memo[i][j]=ans3;

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
		cin>>n>>m>>k;
		for(int i=1;i<=n;i++)
			for(int j=1;j<=n;j++)
				memo[i][j]=-1;
		for(int i=1;i<=n;i++)
			cin>>arr[i];
		cout<<solve(1,n,1,k)<<endl;
	}

}