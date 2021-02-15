// Created by Tanuj Jain
#include<bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;
#define pb push_back
#define mp make_pair
# define M_PI           3.14159265358979323846  /* pi */
#define OJ \
	freopen("input.txt", "r", stdin); \
	freopen("output.txt", "w", stdout);
#define FIO ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll,ll>pll;
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
bool poss(double r, double vol,double t)
{
	//if the vol required for the radius r is less than max val then we can make the igloo else not
	return (2.0/3.0*M_PI*(r*r*r-(r-t)*(r-t)*(r-t))<=vol);
}
int main()
{
	//OJ;
	FIO;

	int t;
	cin>>t;
	while(t--)
	{
		double vol,thi;
		cin>>vol>>thi;
		//cout<<vol<<thi<<endl;
		double low=thi;
		double high=vol;
		double ans;
		for(int i=0;i<100;i++)
		{
			//bs the radius
			auto mid=(low+high)/2;
			if(poss(mid,vol,thi))
			{
				ans=mid;
				low=mid+1;
			}
			else
				high=mid-1;
		}
		cout<<fixed<<setprecision(3)<<ans<<endl;
		//vector<int>v(10);
		//v[11]=100;

				
	}
getchar();

return 0;
}