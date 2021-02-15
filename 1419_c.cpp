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
		int n,x;
		cin>>n>>x;
		std::vector<int>v(n);
		int same=0;
		int delta=0;
		for(int i=0;i<n;i++)
		{
			cin>>v[i];
			if(v[i]==x)
				same++;
			delta+=(x-v[i]);
		}
		//if all the values are same the anaswer is 0
		if(same==n)
		{
			cout<<0<<endl;
		}
		else
		{
			//if we have a single value which is same as killjoys value then in the next
			//move we can change all the account values to an average value of the account
			//and infect all of them
			//or if the delta needed to bring all the account to killjoys value is 0 we can bring
			//all the account to killjoys value hence the answer is 1
			if(same>=1 || delta==0)
				cout<<1<<endl;
			else
				//we cal always use 2 moves and bring all the acoount to same value
				//in first move take any account and infect it by making its value to killjoys value
				//in the next move use the previous infected account and its value and change all the values
				//to their avg value thereby affecting all the accounts in the second move
				cout<<2<<endl;
		}



	}

}