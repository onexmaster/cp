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
//Try using 0-1 bfs
int bfs(int n, int m)
{
	
	char grid[n][m];
	//make grid
	int sx,sy,ex,ey;
	for(int i=0;i<n;i++)
	{
		string st;
		cin>>st;
		for(int j=0;j<st.size();j++)
			grid[i][j]=st[j];
	}
	//make the tele port map
	map<pii,pii>tele;
	map<char,vector<pii>>mapping;
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<m;j++)
		{
			if(grid[i][j]=='B')
			{
				sx=i;
				sy=j;
			}
			else if(grid[i][j]=='X')
			{
				ex=i;
				ey=j;
			}
			else if(grid[i][j]=='W' || grid[i][j]=='.')
				continue;
			else
				mapping[grid[i][j]].pb({i,j});
		}
	}
	//for(auto it:mapping)
	//	cout<<it.first<<endl;
	//cout<<sx<<" "<<sy<<" "<<ex<<" "<<ey<<endl;
	//build the teleportation mapping
	for(auto it:mapping)
	{
			tele[it.second[0]]=(it.second[1]);
			tele[it.second[1]]=(it.second[0]);
	}
		
	//run bfs
	// map<pii,int>vis;
	// queue<pii>q;
	// q.push({sx,sy});
	// vis[{sx,sy}]=0;
	// while(!q.empty())
	// {
	// 	int curr_x=q.front().first;
	// 	int curr_y=q.front().second;
	// 	q.pop();
	// 	if(curr_x==ex && curr_y==ey)
	// 	{
	// 		return vis[{curr_x,curr_y}];
	// 		//break;
	// 	}
	// 	//check for teleport
	// 	if(tele.count({curr_x,curr_y})>0 && vis.find({tele[{curr_x,curr_y}]})==vis.end())
	// 	{
	// 		q.push(tele[{curr_x,curr_y}]);
	// 		vis[tele[{curr_x,curr_y}]]=vis[{curr_x,curr_y}];
	// 	}
	// 	//move in the 4 other directions 
	// 	for(int i=0;i<4;i++)
	// 	{
	// 		int new_x=curr_x+moves[i][0];
	// 		int new_y=curr_y+moves[i][1];
	// 		if(new_x>=0 && new_x<n && new_y>=0 && new_y<m && grid[new_x][new_y]!='W' && vis.find({new_x,new_y})==vis.end())
	// 		{
	// 			q.push({new_x,new_y});
	// 			vis[{new_x,new_y}]=vis[{curr_x,curr_y}]+1;
	// 		}
	// 	}

	//}

	//RUN 0-1 bfs
	deque<pii>q;
	map<pii,int>vis;
	q.push_front({sx,sy});
	vis[{sx,sy}]=0;
	while(!q.empty())
	{
		int curr_x=q.front().first;
		int curr_y=q.front().second;
		q.pop_front();
		if(curr_x==ex && curr_y==ey)
			return vis[{curr_x,curr_y}];
		if(tele.count({curr_x,curr_y})>0 && vis.find({tele[{curr_x,curr_y}]})==vis.end())
		{
			q.push_front(tele[{curr_x,curr_y}]);
			vis[tele[{curr_x,curr_y}]]=vis[{curr_x,curr_y}];
		}
		//move in the 4 other directions 
		for(int i=0;i<4;i++)
		{
			int new_x=curr_x+moves[i][0];
			int new_y=curr_y+moves[i][1];
			if(new_x>=0 && new_x<n && new_y>=0 && new_y<m && grid[new_x][new_y]!='W' && vis.find({new_x,new_y})==vis.end())
			{
				q.push_back({new_x,new_y});
				vis[{new_x,new_y}]=vis[{curr_x,curr_y}]+1;
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

	#ifndef ONLINE_JUDGE
	freopen("inputf.in","r",stdin);
	freopen("outputf.in","w",stdout);
	#endif

	int n,m;
	while(cin>>n>>m){
	if(n==0 || m==0)
		return 0;
	else{

		int ans=bfs(n,m);
		cout<<"He got the Box in "<<ans<<" steps!"<<endl;
	}
}

}