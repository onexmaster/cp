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

		int n;
		cin>>n;
		vector<int>v(n);
		for(int i=0;i<n;i++)
			cin>>v[i];
		int ans=1;
		int pre_level=0;
		int curr_level=1;
		//need to keep track of number of nodes of previous level
		//if the nodes are in sorted order, then attach all of them to a single node of prv level
		//if we have a node in the prv level, we can attach a the next node there, if not move to next lvl
		for(int i=2;i<n;i++)
		{

			if(v[i]>v[i-1])
			{
				curr_level++;
			}
			else if(pre_level>0)
			{
				pre_level--;
				curr_level++;
			}
			else
			{
				ans++;
				pre_level=curr_level-1;
				curr_level=1;
			}
		}
		cout<<ans<<endl;
	}

}