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
		int temp=1;
		vector<int>ans(n);
		ans[0]=1;
		set<int>ends_zero;
		set<int>ends_one;
		if(st[0]=='1')
			ends_one.insert(1);
		else
			ends_zero.insert(1);
		for(int i=1;i<n;i++)
		{
			if(st[i]!=st[i-1])
			{
				ans[i]=ans[i-1];
				//if the previous string was ending in zero now it will end in one
				if(st[i]=='1')
				{
					ends_zero.erase(ans[i]);
					ends_one.insert(ans[i]);
				}
				//else the previous string was ending in 1, now it will end with a 0
				else
				{
					ends_one.erase(ans[i]);
					ends_zero.insert(ans[i]);
				}
			}
			else
			{
				//if we have same char
				//if we have a 1 check the strings ending in 0 and add this char in that
				if(st[i]=='1')
				{
					///if we have a 1 and no string that ends in 0, then we have no option
					//but to create a new set
					if(ends_zero.empty())
					{
						ans[i]=temp+1;
						temp++;
						ends_one.insert(temp);
					}
					//else we have option to use one of the string that ends in 0
					else
					{
						ans[i]=*ends_zero.begin();
						ends_zero.erase(ans[i]);
						ends_one.insert(ans[i]);
					}
				}
				//do the same opetaions but in reverse
				else
				{
					if(ends_one.empty())
					{
						ans[i]=temp+1;
						temp++;
						ends_zero.insert(temp);
					}
					//else we have option to use one of the string that ends in 0
					else
					{
						ans[i]=*ends_one.begin();
						ends_one.erase(ans[i]);
						ends_zero.insert(ans[i]);
					}	
				}
			}
		}
		int res=0;
		for(int i=0;i<n;i++)
			res=max(res,ans[i]);
		cout<<res<<endl;
		for(auto x:ans)
			cout<<x<<" ";
		cout<<endl;

	}

}