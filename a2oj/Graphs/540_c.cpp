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
const int MAXN=505;
char grid[MAXN][MAXN];
int row,col;
bool vis[MAXN][MAXN];
int sx,sy,ex,ey;
bool checkPos(int x, int y)
{
	if (x <=0 || x > row || y <= 0 || y > col) return false;
	return grid[x][y] == '.';
}
bool check(int new_x, int new_y)
{
	if(new_x>0 && new_x<=row && new_y>0 && new_y<=col && !vis[new_x][new_y] && grid[new_x][new_y]=='.')
		return true;
	else
		return false;
}
bool check1(int new_x, int new_y)
{
	if(new_x>0 && new_x<=row && new_y>0 && new_y<=col && grid[new_x][new_y]=='.')
		return true;
	else
		return false;
}
void dfs(int x, int y)
{
	vis[x][y]=1;
	for(int i=0;i<4;i++)
	{
		int new_x=x+moves[i][0];
		int new_y=y+moves[i][1];
		if(check(new_x,new_y))
			dfs(new_x,new_y);
	}
}
void print()
{
	for(int i=1;i<=row;i++)
	{
		for(int j=1;j<=col;j++)
			cout<<vis[i][j]<<" ";
		cout<<endl;
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

	memset(vis,false,sizeof(vis));
	cin>>row>>col;
	for(int i=1;i<=row;i++)
	{
		for(int j=1;j<=col;j++)
		{
			cin>>grid[i][j];
		}
	}
	cin>>sx>>sy>>ex>>ey;
	//IF START AND END ARE ON SAME CELL
	if(sx==ex && sy==ey)
	{

		bool ok=false;
		for(int i=0;i<4;i++)
		{
			int new_x=ex+moves[i][0];
			int new_y=ey+moves[i][1];
			if(check1(new_x,new_y))
			{
				ok=true;
			}
		}
		if(ok)
			cout<<"YES";
		else
			cout<<"NO";
	return 0;
	}
	
	//IF START AND END ARE NEIGHBOURS
	if(abs(sx-ex)+abs(sy-ey)==1)
	{

		bool ok=false;
		//IF THE END CELL IS A "X", WE CAN FALL DIRECTLY
		if(grid[ex][ey]=='X')
			ok=true;
		else 
		{
			//IF THE END CELL IS '.' THEN WE NEED ATLEST ONE NEIGHTBOUR TO GO AND THEN COME BACK 
			for(int i=0;i<4;i++)
			{
				int new_x=ex+moves[i][0];
				int new_y=ey+moves[i][1];
				if(check1(new_x,new_y))
				{
					ok=true;
					break;
				}
			}
		}
		if(ok)
			cout<<"YES";
		else
			cout<<"NO";
		return 0;
	}
	//GENERAL CASE
	//IF THERE IS A PATH FROM START TO ANY NEIGHBOUR DEST AND IF THE DEST IS X THEN YES ELSE AGAIN CHECK THE NEIGHBOUR
	dfs(sx,sy);
	//print();
	bool ok = false;
	for (int i = 0; i < 4; i++)
	{
		int x = ex + moves[i][0], y = ey + moves[i][1];
		if (!checkPos(x, y)) continue;
		if (vis[x][y]) ok = true;
	}
	if (!ok)
	{
		printf("NO\n");	
		return 0;
	}
	if (grid[ex][ey] == 'X')
	{
		printf("YES\n");
		return 0;
	}
	int cnt = 0;
	for (int i = 0; i < 4; i++)
	{
		int x = ex + moves[i][0], y = ey + moves[i][1];
		if (checkPos(x, y)) cnt++;
	}
	if (cnt >= 2)
		printf("YES\n");
	else
		printf("NO\n");
 
	
}