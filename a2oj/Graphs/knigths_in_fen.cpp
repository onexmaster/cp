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
vector<vector<int>>grid(5,vector<int>(5,0));
map<vector<vector<int>>,int>vis;
void bfs()
{
	vis[grid]=0;
	queue<pair<int,pair<int,vector<vector<int>>>>>q;
	q.push({2,{2,grid}});
	while(!q.empty())
	{
			int curr_x=q.front().first;
			int curr_y=q.front().second.first;
			auto curr_grid=q.front().second.second;
			q.pop();
			if(vis[curr_grid]>=11)
				return;
			for(int j=0;j<8;j++)
			{
				int new_x=curr_x+knight_moves[j][0];
				int new_y=curr_y+knight_moves[j][1];
				auto new_grid=curr_grid;
				if(new_x>=0 && new_x<5 && new_y>=0 && new_y<5)
				{
					//swap the postion 
					swap(new_grid[curr_x][curr_y],new_grid[new_x][new_y]);
					if(vis.count(new_grid)==0)
					{
						q.push({new_x,{new_y,new_grid}});
						vis[new_grid]=vis[curr_grid]+1;
					}
				}
			}
		}
		


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

	int t;
	cin>>t;
	//make the inital grid nd do a bfs to preprocess all the states
	for(int j=0;j<5;j++)
		grid[0][j]=1;
	for(int j=1;j<5;j++)
		grid[1][j]=1;
	for(int j=3;j<5;j++)
		grid[2][j]=1;
	grid[3][4]=1;
	grid[2][2]=-1;
	bfs();
	string st1;
	getline(cin,st1);
	while(t--)
	{
		vector<vector<int>>grid1(5,vector<int>(5,-1));
		for(int i=0;i<5;i++)
		{
			getline(cin,st1);
			for(int j=0;j<st1.size();j++)
			{
				grid1[i][j]=(st1[j]-'0');
			}
		}
	 for(int i=0;i<5;i++)
	{
	 	for(int j=0;j<5;j++)
	 		if(grid1[i][j]<0)
	 			grid1[i][j]=-1;

	}
	
		if(vis.count(grid1) && vis[grid1]<=10)
			cout<<"Solvable in "<<vis[grid1]<<" move(s)."<<endl;
		else
			cout<<"Unsolvable in less than 11 move(s)."<<endl;
		

	}
	
}