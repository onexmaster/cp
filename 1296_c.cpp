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
		string st;
		cin>>st;
		bool ok=false;
		if(!ok)
		{

		pair<int,int>curr={0,0};
		map<pair<int,int>,int>vis;
		vis[curr]=0;
		//bool ok=false;
		int global_start=0;
		int global_end=0;
		int dist=INT_MAX;
		int l=-1;
		int r=n;
		for(int i=0;i<n;i++)
		{
			if(st[i]=='L')
				curr.first--;
			if(st[i]=='R')
				curr.first++;
			if(st[i]=='U')
				curr.second++;
			if(st[i]=='D')
				curr.second--;
			if(vis.count(curr))
			{
				
				if(i-vis[curr]<r-l+1)
				{
					l=vis[curr];
					r=i;
					ok=true;
				}
			}
			vis[curr]=i+1;  

		}
		if(ok)
		cout<<l+1<<" "<<r+1<<endl;
	}
	

		if(!ok)
			cout<<-1<<endl;
	}

}