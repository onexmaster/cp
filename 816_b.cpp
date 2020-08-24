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
const int MAXN=2e5+5;
int freq[MAXN];
int final_freq[MAXN];
int prefix_sum[MAXN];
int prefix_sum_final[MAXN];
int main()
{
	ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

	#ifndef ONLINE_JUDGE
	freopen("inputf.in","r",stdin);
	freopen("outputf.in","w",stdout);
	#endif

	int n,k,l;
	cin>>n>>k>>l;
	memset(final_freq,0,sizeof(final_freq));
	memset(freq,0,sizeof(freq));
	memset(prefix_sum,0,sizeof(prefix_sum));
	memset(prefix_sum_final,0,sizeof(prefix_sum_final));
	while(n--)
	{
		ll u,v;
		cin>>u>>v;
		freq[u]++;
		freq[v+1]--;
	}
	//this stores all the values which are visited again and again
	//like prefix count
	final_freq[0]=freq[0];
	for(int i=1;i<=200005;i++)
		final_freq[i]=final_freq[i-1]+freq[i];
	//set the intital value as 1 if the temp is at least k;
	//else set it to 0;

	for(int i=0;i<200005;i++)
		if(final_freq[i]>=k)
			prefix_sum[i]=1;
	//find the prefix sum
	prefix_sum_final[0]=prefix_sum[0];
	for(int i=1;i<=200005;i++)
		prefix_sum_final[i]=prefix_sum_final[i-1]+prefix_sum[i];
	//answer the queries
	while(l--)
	{
		ll start,end,ans;
		cin>>start>>end;
		ans=0;
		ans=prefix_sum_final[end]-prefix_sum_final[start-1];
		printf("%lld \n",ans);
	}
}