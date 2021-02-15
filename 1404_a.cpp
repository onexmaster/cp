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

	int t;
	cin>>t;
	while(t--)
	{
		int n,k;
		cin>>n>>k;
		string st;
		cin>>st;
		bool one[k]={false};
		bool zero[k]={false};
		for(int i=0;i<n;i++)
		{
			//every i%k should be one
			if(st[i]=='1')
				one[i%k]=true;
			//every i%k should be 0
			else if(st[i]=='0')
				zero[i%k]=true;
		}
		bool ok=true;
		for(int i=0;i<k;i++)
			//if an index is set it means it has to be one as well as zero which is not possible
			if(one[i] && zero[i])
				ok=false;
		int onecount=0,zerocount=0;
		for(int i=0;i<k;i++)
			if(one[i])
				onecount++;
			else if(zero[i])
				zerocount++;
			//if we have too many ones or too many zeros then not possible
		if(onecount*2>k || zerocount*2>k)
			ok=false;
		if(!ok)
			cout<<"NO"<<endl;
		else
			cout<<"YES"<<endl;
	}

}