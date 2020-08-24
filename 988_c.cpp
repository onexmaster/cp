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
	int x=1;
	//sum,sequ_no,ele_no;
	vector<pair<int,pair<int,int>>>tri;
	while(t--)
	{
		int n;
		cin>>n;
		vector<int>v(n);
		int sum=0;
		for(int i=0;i<n;i++)
		{
			cin>>v[i];
			sum+=v[i];
		}
		for(int i=0;i<n;i++)
		{
			tri.pb({sum-v[i],{x,i+1}});
		}
		x++;
	}
	sort(tri.begin(),tri.end());
	bool ok=false;
	for(int i=0;i<tri.size()-1;i++)
	{
		if(tri[i].first==tri[i+1].first && tri[i].second.first!=tri[i+1].second.first)
		{
			cout<<"YES"<<endl;
			cout<<tri[i].second.first<<" "<<tri[i].second.second<<endl;
			cout<<tri[i+1].second.first<<" "<<tri[i+1].second.second;
			ok=true;
		}
		if(ok)
			break;
	}
	if(!ok)
		cout<<"NO";

}