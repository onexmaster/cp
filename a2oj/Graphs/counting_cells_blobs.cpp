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
int moves[8][2]={{0,1},{0,-1},{1,0},{-1,0},{1,1},{-1,-1},{1,-1},{-1,1}};
const int MAXN=25;
char grid[MAXN][MAXN];
int blob;
int row,col;
void dfs(int x, int y)
{
	blob++;
	grid[x][y]='0';
	for(int i=0;i<8;i++)
	{
		int new_x=x+moves[i][0];
		int new_y=y+moves[i][1];
		if(new_x>=0 && new_x<row && new_y>=0 & new_y<col && grid[new_x][new_y]=='1')
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

	int t;
	for (scanf("%d\n", &t); t--;) {
		memset(grid, 0, sizeof grid);
		row=0;
		while (gets(grid[row])) {
			if (!strlen(grid[row]))
				break;
			col=strlen(grid[row]);
			++row;
		}
		//cout<<row<<" "<<col<<endl;
		int ans=0;
		//Print grid
		// for(int x=0;x<row;x++)
		// {
		// 	//blob=0;
		// 	for(int y=0;y<grid[x][y];y++)
		// 	{
		// 		cout<<grid[x][y]<<" ";
		// 	}
		// 	cout<<endl;
		// }
		for(int x=0;x<row;++x)
		{
			for(int y=0;y<col;++y)
			{
				blob=0;
				if(grid[x][y]=='1')
				{
					dfs(x,y);
					ans=max(ans,blob);
				}

			}
		}
		cout<<ans<<endl;
		if(t)
			cout<<endl;
	}
	
}