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
int n,k,sx,sy,ex,ey;
int solve()
{
	map<pair<int,int>,int>grid;
	queue<pair<int,int>>q;
	sx--;
	sy--;
	ex--;
	ey--;
	q.push({sx,sy});
	grid[{sx,sy}]=0;
	while(!q.empty())
	{
		int curr_x=q.front().first;
		int curr_y=q.front().second;
		q.pop();

		//if reached end 
		if(curr_x==ex && curr_y==ey)
			return grid[{curr_x,curr_y}];
		//move like a knight
		for(int i=0;i<8;i++)
		{	
			int new_x=curr_x+knight_moves[i][0];
			int new_y=curr_y+knight_moves[i][1];
			if(new_x>=0 && new_x<n && new_y>=0 & new_y<n && grid.count({new_x,new_y})==0)
			{
				q.push({new_x,new_y});
				grid[{new_x,new_y}]=grid[{curr_x,curr_y}]+1;
			}
		}
		//move horiozontally k times right  
		for(int i=1;i<=k;i++)
		{
			int new_x=curr_x;
			int new_y=curr_y+i;
			if(new_x>=0 && new_x<n && new_y>=0 & new_y<n && grid.count({new_x,new_y})==0)
			{
				q.push({new_x,new_y});
				grid[{new_x,new_y}]=grid[{curr_x,curr_y}]+1;
			}

		}
		//move horiozontally k times left  
		for(int i=1;i<=k;i++)
		{
			int new_x=curr_x;
			int new_y=curr_y-i;
			if(new_x>=0 && new_x<n && new_y>=0 & new_y<n && grid.count({new_x,new_y})==0)
			{
				q.push({new_x,new_y});
				grid[{new_x,new_y}]=grid[{curr_x,curr_y}]+1;
			}

		}
		//move vertically k times down
		for(int i=1;i<=k;i++)
		{
			int new_x=curr_x+i;
			int new_y=curr_y;
			if(new_x>=0 && new_x<n && new_y>=0 & new_y<n && grid.count({new_x,new_y})==0)
			{
				q.push({new_x,new_y});
				grid[{new_x,new_y}]=grid[{curr_x,curr_y}]+1;
			}

		}
		//move vertically k times up
		for(int i=1;i<=k;i++)
		{
			int new_x=curr_x-i;
			int new_y=curr_y;
			if(new_x>=0 && new_x<n && new_y>=0 & new_y<n && grid.count({new_x,new_y})==0)
			{
				q.push({new_x,new_y});
				grid[{new_x,new_y}]=grid[{curr_x,curr_y}]+1;
			}

		}

	}
	return 0;
}
int main()
{
	ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

	//#ifndef ONLINE_JUDGE
	//freopen("inputf.in","r",stdin);
	//freopen("outputf.in","w",stdout);
	//#endif

	int t;
	cin>>t;
	while(t--)
	{
		cin>>n>>k>>sx>>sy>>ex>>ey;
		cout<<solve();
		if(t)
			cout<<endl;
	}

}