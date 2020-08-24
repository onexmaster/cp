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

const int MAXN = 410;
const ll INF = 1e14;

ll dp[MAXN][MAXN],V[MAXN],pref[MAXN];
int N;

ll calc(ll a,ll b){
	if(a > b) return INF;
	return pref[b] - pref[a-1];
}

ll solve(int start,int end){
	//cout<<start<<" "<<end<<endl;
	if(dp[start][end] != -1) return dp[start][end];
	if(start == end) return dp[start][end] = 0;
	if(start + 1 == end) return dp[start][end] = V[start] + V[end];

	ll best = INF;

	for(int i = start;i<end;i++){
		ll cand = solve(start,i) + solve(i+1,end) + calc(start,end);
		best = min(best,cand);
	}

	return dp[start][end] = best;

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

	memset(dp,-1,sizeof(dp));

	cin >> N;
	for(int i = 1;i<=N;i++) cin >> V[i];

	for(int i = 1;i<=N;i++) pref[i] = pref[i-1] + V[i];

	cout << solve(1,N) << endl;

}