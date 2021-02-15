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
	if(t<6)
	{
		cout<<-1<<endl;
		for(int i=2;i<=t;i++)
			cout<<1<<" "<<i<<endl;
	}
	else
	{
		//this tree should prodcue wa answer
		//the answer for this tree is 2 but the algo will give answer as 3
		cout<<1<<" "<<2<<endl;
		cout<<1<<" "<<3<<endl;
		cout<<1<<" "<<4<<endl;
		for(int i=5;i<=t;i++)
			cout<<2<<" "<<i<<endl;
		//this tree should give right answer
		//minimum vertex for this kind of tree is 3 and according to the algo the 
		//answer is 3 coz the 2nd level has 2 nodes and the 4 level has 1 node
		cout<<1<<" "<<2<<endl;
		cout<<1<<" "<<3<<endl;
		for(int i=4;i<t;i++)
			cout<<2<<" "<<i<<endl;
		cout<<t-1<<" "<<t<<endl;
	}

}