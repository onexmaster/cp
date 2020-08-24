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
const int MAXN=1e3+5;
int grid[MAXN][MAXN];
int main()
{
	ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

	#ifndef ONLINE_JUDGE
	freopen("inputf.in","r",stdin);
	freopen("outputf.in","w",stdout);
	#endif

	int n;
	while(cin>>n)
	{
		memset(grid,0,sizeof(grid));
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<i;j++)
		{
			string x;
			cin>>x;
			if(x!="x")
			{
				grid[i][j]=stoi(x);
				grid[j][i]=stoi(x);
			}
			else
			{
				grid[i][j]=INF;
				grid[j][i]=INF;
			}
		}
	}
	for(int k=0;k<n;k++)
	{
		for(int i=0;i<n;i++)
		{
			for(int j=0;j<n;j++)
				grid[i][j]=min(grid[i][j],grid[i][k]+grid[k][j]);
		}
	}
	int ans=0;
	for(int i=0;i<n;i++)
		ans=max(ans,grid[0][i]);
	cout<<ans<<endl;
	}

	
}