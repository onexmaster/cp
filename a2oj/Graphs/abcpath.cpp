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
const int MAXN=55;
int dist[MAXN][MAXN];
int main()
{
	ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

	#ifndef ONLINE_JUDGE
	freopen("inputf.in","r",stdin);
	freopen("outputf.in","w",stdout);
	#endif

	int row,col;
	int x=1;
	while(cin>>row>>col){
		if(row==0 && col==0)
			return 0;
	
	//cout<<row<<col;
	memset(dist,INF,sizeof(dist));
	vector<vector<char>>grid(row,vector<char>(col));
	queue<pair<char,pair<int,int>>>q;
	for(int i=0;i<row;i++)
	{
		string temp;
		cin>>temp;
		for(int j=0;j<col;j++)
		{
			grid[i][j]=temp[j];
			if(grid[i][j]=='A')
			{
				q.push({'A',{i,j}});
				dist[i][j]=1;
			}
		}
	}
	while(!q.empty())
	{
			char temp=q.front().first;
			//int curr_alpha=curr-'A';
			int curr_x=q.front().second.first;
			int curr_y=q.front().second.second;
			q.pop();
			for(int j=0;j<8;j++)
			{
				int new_x=curr_x+moves[j][0];
				int new_y=curr_y+moves[j][1];
				if(new_x>=0 && new_x<row && new_y>=0 && new_y<col)
				{
					if(dist[new_x][new_y]>dist[curr_x][curr_y]+1 && grid[new_x][new_y]-temp==1)
					{
						dist[new_x][new_y]=dist[curr_x][curr_y]+1;
						q.push({grid[new_x][new_y],{new_x,new_y}});
					}
				}
			}
	}
	int ans=0;
	for(int i=0;i<row;i++)
	{
		for(int j=0;j<col;j++)
			if(dist[i][j]!=INF)
				ans=max(ans,dist[i][j]);
	}
	if(ans!=0)
	{
		cout<<"Case "<<x<<": "<<ans<<endl;
	}
	else
	{
		cout<<"Case "<<x<<": "<<ans<<endl;
	}
	
	x++;


}
}