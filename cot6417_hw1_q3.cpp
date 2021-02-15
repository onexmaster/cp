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
vector<int>z_algo(string f, string p)
{
	int n=f.size();
	std::vector<int> z_values(n);
	z_values[0]=0;
	int l,r=0;
	for(int i=1;i<n;i++)
	{
		if(f[i]=='*' && i<p.size())
			z_values[i]=0;
		if(i>r)
		{
			l=r=i;
			while(r<n && f[r-l]==f[r] || f[r-l]=='*')
				r++;
			z_values[i]=r-l;
			r--;
		}
		else
		{
			int k=i-l;
			if(z_values[k]<r-i+1)
				z_values[i]=z_values[k];
			else
			{
				l=i;
				while(r<n && f[r-l]==f[r] || f[r-l]=='*')
					r++;
				z_values[i]=r-l;
				r--;
			}
		}
	}
	return z_values;
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

	string p="abc**bca**baa";
	string t="abcdebcaaabaa";
	string f=p+"$"+t;
	vector<int>z_values=z_algo(f,p);
	for(int i=0;i<z_values.size();i++)
		cout<<z_values[i]<<" ";

}