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

const int MAXN = 3002;

double dp[MAXN][MAXN];
double prob[MAXN];
//bool vis[MAXN][MAXN];
/*
double recursive(int N, int heads)
{
	//base case
	if(N<heads)
		return 0.0;
	if(N==0)
		return (heads==0);

	if(vis[N][heads])
		return dp[N][heads];
	else
	{
		//mark the node as visited
		vis[N][heads]=true;
		//find the left and right child values and save it in dp table
		//if i toss the nthe coin i can get a head and a tail
		//if i get a head then i need the ansewer for n-1 and heads-1 
		//if i get a tailt thena i need the answer for n-1 and heads
		return dp[N][heads]=(prob[N]*(recursive(N-1,heads-1))+ (1.0-prob[N])*(recursive(N-1,heads)));
	}
}
*/
void bottomup(int &N)
{
	//double dp1[MAXN][MAXN]={};
	dp[0][0]=1.0;
	//fill the first colum
	//for(int i=1;i<=N;i++)
	//	dp[i][0]=1.0-prob[i];
	
	for(int coin=1;coin<=N;coin++)
	{
		for(int heads=0;heads<=coin;heads++)
		{
			if(heads==0)
				dp[coin][heads]=dp[coin-1][heads]*(1.0-prob[coin]);
			else
				dp[coin][heads]=((prob[coin]*dp[coin-1][heads-1])+(1.0-prob[coin])*(dp[coin-1][heads]));
		}
	}
	for(int i=0;i<=N;i++)
	{
		for(int j=0;j<=N;j++)
			cout<<dp[i][j]<<" ";
		cout<<endl;
	}
	double ans = 0.0; 
  
    // When the number of heads is greater than (n+1)/2 
    // it means that heads are greater than tails as 
    // no of tails + no of heads is equal to n for 
    // any permuation of heads and tails 
    for (int i = (N + 1) / 2; i <= N; i += 1) 
        ans += dp[N][i]; 
  
    cout<<fixed<<setprecision(9)<<ans; 
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

	int N;
	cin>>N;
	for(int i=1;i<=N;i++)
		cin>>prob[i];
	//double ans=0;
	//for(int heads=0;heads<=N;heads++)
	//{
	//	int tails=N-heads;
	//	if(heads>tails)
	//	{
	//		ans+=recursive(N,heads);
	//	}
	//}
	//cout<<fixed<<setprecision(9)<<ans;
	bottomup(N);
	
}