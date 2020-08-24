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
const int MAXN=255;
char grid[MAXN][MAXN];
int row,col;
int wolf;
int sheep;
void dfs(int x, int y)
{
	if(grid[x][y]=='k')
	{
		sheep++;
		grid[x][y]='#';
	}
	else if(grid[x][y]=='v')
	{
		wolf++;
		grid[x][y]='#';
	}
	else
		grid[x][y]='#';
	for(int i=0;i<4;i++)
	{
		int new_x=x+moves[i][0];
		int new_y=y+moves[i][1];
		if(new_x>=0 && new_x<row && new_y>=0 && new_y<col && grid[new_x][new_y]!='#')
			dfs(new_x,new_y);
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
	cin>>row>>col;
	for(int i=0;i<row;i++)
	{
		string st;
		cin>>st;
		for(int j=0;j<col;j++)
			grid[i][j]=st[j];

	}
	int total_sheep=0;
	int total_wolf=0;

	//for escape fromm backyard
	wolf=0;
	sheep=0;
	//for top row
	for(int j=0;j<col;j++)
	{
		if(grid[0][j]!='#')
		{
			dfs(0,j);
			total_wolf+=wolf;
			total_sheep+=sheep;
		}
	}
	//for bottom row
	wolf=0;
	sheep=0;
	int last_row=row-1;
	for(int j=0;j<col;j++)
	{
		if(grid[last_row][j]!='#')
		{
			dfs(last_row,j);
			total_wolf+=wolf;
			total_sheep+=sheep;
		}
	}
	wolf=0;
	sheep=0;
	//for first col;
	for(int i=0;i<row;i++)
	{
		if(grid[i][0]!='#')
		{
			dfs(i,0);
			total_wolf+=wolf;
			total_sheep+=sheep;
		}
	}
	//for last col
	wolf=0;
	sheep=0;
	int last_col=col-1;
	for(int i=0;i<row;i++)
	{
		if(grid[i][last_col]!='#')
			{
				dfs(i,last_col);
				total_wolf+=wolf;
				total_sheep+=sheep;
			}
	}

	//for the grid
	for(int i=1;i<row;i++)
	{
		for(int j=1;j<col;j++)
		{
			wolf=0;
			sheep=0;

			 if(grid[i][j]!='#')
			{
				dfs(i,j);
				if(sheep>wolf)
					total_sheep+=sheep;
				else
					total_wolf+=wolf;
			}
		}
	}
	cout<<total_sheep<<" "<<total_wolf;
	
	
}