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
		ll l,r,m;
		cin>>l>>r>>m;
		ll max_poss=r-l; 
		ll min_poss=l-r;
		//cout<<min_poss<<" "<<max_poss<<endl;
		for(int i=l;i<=r;i++)
		{
			ll rem=m%i;
			ll quo=m/i;
			//cout<<i<<" "<<quo<<" "<<rem<<endl;
			if(rem==0)
			{
				cout<<i<<" "<<l<<" "<<l<<endl;
				break;
			}
			else
			{
				//make it reach the next quotient
				ll poss_1=(quo+1)*i;
				ll req=poss_1-m;
				if(req>=min_poss && req<=max_poss)
				{
					cout<<i<<" "<<r-req<<" "<<r<<endl;
					break;
				}
				ll poss_2=(quo-1)*i;
				req=m-poss_2;
				if(req>=min_poss && req<=max_poss)
				{
					cout<<i<<" "<<r<<" "<<r-req<<endl;
					break;
				}
				ll poss_3=(quo)*i;
				req=m-poss_3;
				if(req>=min_poss && req<=max_poss)
				{
					cout<<i<<" "<<r<<" "<<r-req<<endl;
					break;
				}

			}
		}
	}

}