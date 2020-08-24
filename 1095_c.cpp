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

	int n,k;
	cin>>n>>k;
	int no_of_ones=__builtin_popcount(n);
	multiset<int>no;
	if(no_of_ones>k)
	{
		cout<<"NO";
		return 0;
	}
	else
	{
		
		int pos=0;
		while(n>0)
		{
			if(n&1)
			{
				no.insert(pow(2,pos));
				n>>=1;
				pos++;
			}
			else
			{
				n>>=1;
				pos++;
			}
		}
	}
	bool ok=false;
	if(no_of_ones==k)
		ok=true;
	while(*no.rbegin()!=1)
	{
		if(no.size()==k)
		{
			ok=true;
			break;
		}
		int ele=*no.rbegin();
		no.erase(no.find(ele));
		no.insert(ele/2);
		no.insert(ele/2);
	}
	if(no.size()==k)
		ok=true;
	if(ok)
	{
		cout<<"YES"<<endl;
		for(auto it:no)
			cout<<it<<" ";
	}
	else
		cout<<"NO";

}