//Need more working than 3 bfs. Need to think about it 
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

const int MAXN=105;
int grid[MAXN][MAXN];
int moves[4][4]={{-1,0},{1,0},{0,-1},{0,1}};
int total_row;
int total_col;
void bfs_mouse(int row, int col)
{
	//BFS FOR MOUSE
	
	bool vis[MAXN][MAXN]={false};
	queue<pair<int,int>>q;
	q.push({row,col});
	grid[row][col]=0;
	vis[row][col]=true;
	int step=1;
	while(!q.empty())
	{
		//BFS is level order traversal 
		int curr_size=q.size();
		for(int i=0;i<curr_size;i++)
		{
			int curr_row=q.front().first;
			int curr_col=q.front().second;
			q.pop();
			for(int i=0;i<4;i++)
			{
				int new_row=curr_row+moves[i][0];
				int new_col=curr_col+moves[i][1];
				if(new_row>=0 && new_row<total_row && new_col>=0 && new_col<total_col && !vis[new_row][new_col])
				{
					grid[new_row][new_col]=step;
					vis[new_row][new_col]=true;
					q.push({new_row,new_col});
				}
			}

		}
		step++;

	}
	for(int i=0;i<total_row;i++)
		{
			for(int j=0;j<total_col;j++)
				cout<<grid[i][j]<<" ";
			cout<<endl;
		}
}
bool bfs_cat(int row, int col)
{
	int grid1[MAXN][MAXN]={0};
	bool vis[MAXN][MAXN]={false};
	queue<pair<int,int>>q;
	q.push({row,col});
	vis[row][col]=true;
	int step=1;
	while(!q.empty())
	{
		//BFS is level order traversal 
		int curr_size=q.size();
		for(int i=0;i<curr_size;i++)
		{

			int curr_row=q.front().first;
			int curr_col=q.front().second;
			//cout<<curr_row<<" "<<curr_col<<" "<<step<<endl;
			q.pop();
			for(int i=0;i<4;i++)
			{
				int new_row=curr_row+moves[i][0];
				int new_col=curr_col+moves[i][1];
				if(new_row>=0 && new_row<total_row && new_col>=0 && new_col<total_col && !vis[new_row][new_col])
				{
					grid1[new_row][new_col]=step;
					vis[new_row][new_col]=true;
					q.push({new_row,new_col});
				}
			}

		}
		step++;

	}
	for(int i=0;i<total_row;i++)
		{
			for(int j=0;j<total_col;j++)
				cout<<grid1[i][j]<<" ";
			cout<<endl;
		}
	return true;
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

	
	cin>>total_row>>total_col;
	int t;
	cin>>t;
	while(t--)
	{
		int m_r,m_c,c1_r,c1_c,c2_r,c2_c;
		cin>>m_r>>m_c>>c1_r>>c1_c>>c2_r>>c2_c;
		bfs_mouse(m_r-1,m_c-1);
		cout<<"CAT 1"<<endl;
		bfs_cat(c1_r-1,c1_c-1);
		cout<<"CAT 2"<<endl;
		bfs_cat(c2_r-1,c2_c-1);
	
		//if(!bfs_cat(c1_r-1,c1_c-1) || !bfs_cat(c2_r-1,c2_c-1))
		//	cout<<"NO"<<endl;
		//else
		//	cout<<"YES"<<endl;
	}
	
}