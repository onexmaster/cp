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
const int MAXN=55;
char grid[MAXN][MAXN];
vector<pair<char,int>>ans;
int row,col;
void bfs()
{
	for(int i=0;i<row;i++)
	{
		for(int j=0;j<col;j++)
		{
			if(grid[i][j]!='x' && grid[i][j]!='.')
			{
				int size=0;
				char temp=grid[i][j];
				queue<pair<int,int>>q;
				q.push({i,j});
				grid[i][j]='.';
				while(!q.empty())
				{
					int curr_size=q.size();
					for(int j=0;j<curr_size;j++)
					{
						int curr_x=q.front().first;
						int curr_y=q.front().second;
						q.pop();
						size++;
						for(int k=0;k<4;k++)
						{
							int new_x=curr_x+moves[k][0];
							int new_y=curr_y+moves[k][1];
							if(new_x>=0 && new_x<row && new_y>=0 && new_y<col && grid[new_x][new_y]==temp)
							{
								q.push({new_x,new_y});
								grid[new_x][new_y]='.';
							}
						}
					}
				}
				ans.pb({temp,size});
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
	int x=1;
	while(cin>>row>>col)
	{
		if(row==0 && col==0)
			return 0;

		memset(grid,'x',sizeof(grid));
		for(int i=0;i<row;i++)
			for(int j=0;j<col;j++)
				cin>>grid[i][j];
		bfs();
		sort(ans.begin(),ans.end(),[](pair<char,int>&a, pair<char,int>&b)
		{
			if(a.second>b.second)
				return true;
			else if(a.second==b.second)
				{
					if(a.first<b.first)
						return true;
					else
						return false;
				}
			else
				return false;
		});
		cout<<"Problem "<<x<<":"<<endl;
		for(int i=0;i<ans.size();i++)
			cout<<ans[i].first<<" "<<ans[i].second<<endl;
		ans.clear();
		x++;

	}
	
}