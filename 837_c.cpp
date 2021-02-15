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
int n,a,b;
vector<pii>v;
int solve()
{
	//return the max area
	int ans=0;
	for(int i=0;i<n;i++)
	{
		int x1=v[i].first;
		int y1=v[i].second;
		for(int j=i+1;j<n;j++)
		{
			int x2=v[j].first;
			int y2=v[j].second;
			//orientation 1->both the blocks are one beside each other [][]
			//for this oreintation the x coridnates get added and max of the y should in bounds
			if(x1+x2<=a && max(y1,y2)<=b || x1+x2<=b && max(y1,y2)<=a)
				ans=max(ans,x1*y1+x2*y2);
			//orientation 2->one is standing one is sleeping
			//for this x1 and y1 gets added and the max(y1,x2) should be in bounds
			if(x1+y2<=a && max(y1,x2)<=b || x1+y2<=b && max(y1,x2)<=a)
				ans=max(ans,x1*y1+x2*y2);
			//orientation 3->one above each other
			//for this y gets added and max of x1 and x2 should be in bound
			if(y1+y2<=b && max(x1,x2)<=a || y1+y2<=a && max(x1,x2)<=b)
				ans=max(ans,x1*y1+x2*y2);
			//orientation 4 ->one is standing and another is on top of first but sleeping
			//for this y1 and x2 gets added and max(x1,y2) should be in bound
			if(y1+x2<=b && max(x1,y2)<=a || y1+x2<=a && max(x1,y2)<=b)
				ans=max(ans,x1*y1+x2*y2);
		}
		
	}
	return ans;
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

	cin>>n>>a>>b;
	v.resize(n);
	for(int i=0;i<n;i++)
		cin>>v[i].first>>v[i].second;
	int ans1=solve();
	//swap the x and y co-ordinate of the each letter and then try again
	for(int i=0;i<n;i++)
		swap(v[i].first,v[i].second);
	int ans2=solve();
	//cout<<ans1<<" "<<ans2<<endl;
	cout<<max(ans1,ans2);

	
	return 0;
}