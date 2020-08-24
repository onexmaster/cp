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
char grid[35][85];
int line;
char color;
void dfs(int x,int y)
{
	grid[x][y]=color;
	for(int i=0;i<4;i++)
	{
		int new_x=x+moves[i][0];
		int new_y=y+moves[i][1];
		if(grid[new_x][new_y]!='X' && grid[new_x][new_y]!=color)
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

	while(gets(grid[0]))
	{
		line =1;
		while(gets(grid[line]))
		{
			if(grid[line][0]=='_')break;
			line++;
		}
	for(int i=0;i<line;i++)
	{
		for(int j=0;j<strlen(grid[i]);j++)
		{
			if(grid[i][j]!=' ' && grid[i][j]!='X')
			{
				color=grid[i][j];
				dfs(i,j);
			}
		}
	}
	for ( int i = 0; i <= line; i++ ) {
            printf ("%s\n", grid [i]);
        }
    }
	
}