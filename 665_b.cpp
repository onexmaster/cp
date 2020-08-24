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
	list<int>items;
	int res=0;
	for(int i=0;i<k;i++)
	{
		int x;
		cin>>x;
		items.push_back(x);
	}
	while(n--)
	{
		int ans=0;
		for(int i=0;i<m;i++)
		{
			int x;
			cin>>x;
			auto it=items.begin();
			auto it_temp=items.begin();
			auto it_find=find(items.begin(),items.end(),x);
			int index=1;
			while(it_temp!=it_find)
			{
				index++;
				advance(it_temp,1);
			}
			//cout<<x<<" "<<index<<endl;
			items.erase(it_temp);
			ans+=index;
			items.push_front(x);


		}
		res+=ans;
	}
	cout<<res;


}