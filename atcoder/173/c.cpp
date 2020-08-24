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
int main()
{
	ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

	#ifndef ONLINE_JUDGE
	freopen("inputf.in","r",stdin);
	freopen("outputf.in","w",stdout);
	#endif

	int row,col,k;
	cin>>row>>col>>k;
	char grid[row][col];
	for(int i=0;i<row;i++)
	{
		for(int j=0;j<col;j++)
			cin>>grid[i][j];
	}
	int res=0;
	for(int mask=0; mask<(1<<(row+col));mask++)
	{
		int count=0;
		for(int i=0;i<row;i++)
		{
			for(int j=0;j<col;j++)
			{
				if(grid[i][j]!='#')
					continue;
				//if the current row or the current col is set dont consider it
				//this will give ==0 when the ith row is not set and the ith col is also not set
				if((mask&(1<<i) | mask&(1<<row+j))!=0)
					continue;
				count++;
			}
		}
		if(count==k)
			res++;
	}
	cout<<res;
	
}	