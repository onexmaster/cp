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
const int MAXN=105;
char grid[MAXN][MAXN];
int row,col;
unordered_map<char,int>ranking;
void dfs(int x, int y, char alpha)
{
	grid[x][y]='1';
	for(int i=0;i<4;i++)
	{
		int new_x=x+moves[i][0];
		int new_y=y+moves[i][1];
		if(new_x>=0 && new_x<row && new_y>=0 && new_y<col && grid[new_x][new_y]==alpha)
			dfs(new_x,new_y,alpha);
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
	int x=1;
	while(t--)
	{
		cin>>row>>col;
		for(int i=0;i<row;i++)
		{
			string st;
			cin>>st;
			for(int j=0;j<col;j++)
				grid[i][j]=st[j];
		}
		for(int i=0;i<row;i++)
		{
			for(int j=0;j<col;j++)
			{
				if(grid[i][j]!='1')
				{
					ranking[grid[i][j]]++;
					dfs(i,j,grid[i][j]);

				}
			}
		}
		cout<<"World #"<<x<<endl;;
		vector<pair<int,char>>ans;
		for(auto it: ranking)
			ans.pb({(it.second*-1),it.first});
		sort(ans.begin(),ans.end());
		for(int i=0;i<ans.size();i++)
			cout<<ans[i].second<<": "<<(-1*ans[i].first)<<endl;
		x++;
		ans.clear();
		ranking.clear();


	}
	
}