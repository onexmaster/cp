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
const int MAXN=505;
char grid[MAXN][MAXN];
int r,c;
int hor[MAXN][MAXN];
int ver[MAXN][MAXN];
void solve()
{
	//build the horizontal table
	for(int i=0;i<r;i++)
	{
		for(int j=1;j<c;j++)
		{
			if(grid[i][j]=='.' && grid[i][j-1]=='.')
					hor[i][j]=hor[i][j-1]+1;
			else
				hor[i][j]=hor[i][j-1];
		}
	}
	//build the vertical table
	for(int i=1;i<r;i++)
	{
		for(int j=0;j<c;j++)
		{
			if(grid[i][j]=='.' && grid[i-1][j]=='.')
				ver[i][j]=ver[i-1][j]+1;
			else
				ver[i][j]=ver[i-1][j];

		}
	}
	// for(int i=0;i<r;i++)
	// {
	// 	for(int j=0;j<c;j++)
	// 		cout<<hor[i][j]<<" ";
	// 	cout<<endl;
	// }
	// cout<<endl;
	// for(int i=0;i<r;i++)
	// {
	// 	for(int j=0;j<c;j++)
	// 		cout<<ver[i][j]<<" ";
	// 	cout<<endl;
	// }
	// cout<<endl;
}
void query()
{
		int sx,sy,ex,ey;
		cin>>sx>>sy>>ex>>ey;
		--sx;
		--ex;
		--sy;
		--ey;
		int ans=0;
		//for horizontal dominos
		for(int i=sx;i<=ex;i++)
		{
			ans+=hor[i][ey];
			ans-=hor[i][sy];
		}
		//for vertical dominos
		//iterate over columns
		for(int i=sy;i<=ey;i++)
		{
			ans+=ver[ex][i];
			ans-=ver[sx][i];
		}
		cout<<ans<<endl;

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

	cin>>r>>c;
	for(int i=0;i<r;i++)
	{
		string st;
		cin>>st;
		for(int j=0;j<c;j++)
			grid[i][j]=st[j];
	}
	solve();
	int q;
	cin>>q;
	while(q--)
	{
		query();
	}

}