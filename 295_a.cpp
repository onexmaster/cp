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

	int n,m,k;
	cin>>n>>m>>k;
	vector<int>v(n+1);
	unordered_map<int,vector<int>>op;
	for(int i=1;i<=n;i++)
		cin>>v[i];
	for(int i=1;i<=m;i++)
	{
		vector<int>temp(3);
		cin>>temp[0]>>temp[1]>>temp[2];
		op[i]=temp;
	}
	for(int i=0;i<k;i++)
	{
		int start,end;
		cin>>start>>end;
		for(int j=start;j<=end;j++)
		{
			vector<int>temp=op[j];
			int l=temp[0];
			int r=temp[1];
			int val=temp[2];
			cout<<l<<" "<<r<<" "<<val<<endl;
			v[l]+=val;
			if(r<n-1)
				v[r+1]-=val;
		}
	}
	vector<int>res(n);
	res[0]=v[1];
	for(int i=1;i<=n;i++)
		cout<<v[i]<<" ";
	cout<<endl;
	for(int i=1;i<n;i++)
	{
		res[i]=res[i-1]+v[i+1];
	}
	for(int i=0;i<n;i++)
		cout<<res[i]<<" ";



}