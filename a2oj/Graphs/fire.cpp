// Created by Tanuj Jain
//Does not work- NEED TO CONVERT MAPS TO GRID 
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
const int MAXN=1e3+5;
int row,col;
//vis holds cells which has a barricade
set<pair<int,int>>vis;
map<pair<int,int>,int>distJ;
map<pair<int,int>,int>distF;
void bfsj(int x, int y)
{
	distJ[{x,y}]=0;
	queue<pair<int,int>>q;
	q.push({x,y});
	while(!q.empty())
	{
		int curr_x=q.front().first;
		int curr_y=q.front().second;
		q.pop();
		for(int i=0;i<4;i++)
		{
			int new_x=curr_x+moves[i][0];
			int new_y=curr_y+moves[i][1];
			if(new_x>=0 && new_x<row && new_y>=0 && new_y<col && vis.find({new_x,new_y})==vis.end())
			{
				if(distJ.count({new_x,new_y})==0)
				{
					q.push({new_x,new_y});
					distJ[{new_x,new_y}]=distJ[{curr_x,curr_y}]+1;
				}
			}
		}
	}
}
void bfsf(int x, int y)
{
	distF[{x,y}]=0;
	queue<pair<int,int>>q;
	q.push({x,y});
	while(!q.empty())
	{
		int curr_x=q.front().first;
		int curr_y=q.front().second;
		q.pop();
		for(int i=0;i<4;i++)
		{
			int new_x=curr_x+moves[i][0];
			int new_y=curr_y+moves[i][1];
			if(new_x>=0 && new_x<row && new_y>=0 && new_y<col && vis.find({new_x,new_y})==vis.end())
			{
				if(distF.count({new_x,new_y})==0)
				{
					q.push({new_x,new_y});
					distF[{new_x,new_y}]=distF[{curr_x,curr_y}]+1;
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
	
	while(t--)
	{
		int jx,jy,fx,fy;
		cin>>row>>col;
		for(int i=0;i<row;i++)
		{
			string st1;
			cin>>st1;
			for(int j=0;j<st1.size();j++)
			{
				if(st1[j]=='#')
					vis.insert({i,j});
				else if(st1[j]=='J')
				{
					jx=i;
					jy=j;
				}
				else if(st1[j]=='F')
				{
					fx=i;
					fy=j;
				}
			}
		}
		bfsj(jx,jy);
		bfsf(fx,fy);
		int ans=INT_MAX;
		//for first row
		for(int i=0;i<col;i++)
		{
			if(vis.find({0,i})==vis.end() &&)
			{
				int j_time=distJ[{0,i}];
				int f_time=distF[{0,i}];
				//cout<<j_time<<" "<<f_time<<endl;
				if(f_time>j_time || f_time==0)
					ans=min(ans,j_time);
			}
		}
		//for last row
		for(int i=0;i<col;i++)
		{
			if(vis.find({row-1,i})==vis.end() && distJ.count({row-1,i})>0)
			{
				int j_time=distJ[{row-1,i}];
				int f_time=distF[{row-1,i}];
				if(f_time>j_time || f_time==0)
					ans=min(ans,j_time);
			}
		}
		//for first col
		for(int i=0;i<row;i++)
		{
			if(vis.find({i,0})==vis.end() && distJ.count({i,0})>0)
			{
				int j_time=distJ[{i,0}];
				int f_time=distF[{i,0}];
				if(f_time>j_time ||f_time==0)
					ans=min(ans,j_time);
			}
		}
		//for last col
		for(int i=0;i<row;i++)
		{
			if(vis.find({i,col-1})==vis.end() && distJ.count({i,col-1})>0)
			{
				int j_time=distJ[{i,col-1}];
				int f_time=distF[{i,col-1}];
				if(f_time>j_time || f_time==0)
					ans=min(ans,j_time);
			}
		}
		if(ans==INT_MAX)
			cout<<"IMPOSSIBLE"<<endl;
		else
			cout<<ans+1<<endl;
		distJ.clear();
		distF.clear();
		vis.clear();


	}
}