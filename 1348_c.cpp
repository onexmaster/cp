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
void solve()
{
		int n,k;
		cin>>n>>k;
		string st;
		cin>>st;
		sort(st.begin(),st.end());
		//case 1 if kth element is not same as the first one 
		//it means kth element is the answer and all the remaining chars are appended to 
		//the first char 
		//aabbc and k=3;
		//st[0]=0 and st[k]=b
		//hence we have the 3 strings as 
		//abbc      a         b->this is lexo smallest
		if(st[0]!=st[k-1])
		{
			cout<<st[k-1];
			cout<<endl;
			return;
		}
		else 
		{
			cout<<st[0];
			if(st[k]!=st[n-1])
				for(int i=k;i<n;i++)
					cout<<st[i];
			else
				for(int i=0;i<(n-k+k-1)/k;i++)
					cout<<st[n-1];

		}
		cout<<endl;

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
		solve();
	}

}