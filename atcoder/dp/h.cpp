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

//Use these for recursive solution
const int mod=1e9+7;
//int dp[1005][1005];
//bool vis[1005][1005];

/*
int recursive(int row, int col, vector<vector<char>>&matrix)
{
	//cout<<row<<col<<endl;
	if(row<0 || col<0)
		return 0;
	if(matrix[row][col]=='#')
		return 0;
	if(row==0 && col==0)
		return dp[row][col]=1;

	//i do my work
	int left=0;
	int up=0;
	//if i already visited this cell return the ans from the dp table
	if(vis[row][col])
		return dp[row][col];
	//else find the answer form the children and mark the cell as visisted 
	else
	{
		vis[row][col]=true;
		//get the answers from childern and do the work;
		 left=recursive(row,col-1,matrix);
		 up=recursive(row-1,col,matrix);
	}
	return dp[row][col]=(left+up)%mod;
}
*/
int bottomup(vector<vector<char>>&matrix)
{
	int row=matrix.size();
	int col=matrix[0].size();
	int dp1[row][col];

	//fill the first col
	dp1[0][0]=1;
	for(int i=1;i<row;i++)
	{
		if(matrix[i][0]=='#')
			dp1[i][0]=0;
		else
			dp1[i][0]=dp1[i-1][0];
	}
	//fill the first row
	for(int i=1;i<col;i++)
	{
		if(matrix[0][i]=='#')
			dp1[0][i]=0;
		else
			dp1[0][i]=dp1[0][i-1];
	}
	for(int i=1;i<row;i++)
	{
		for(int j=1;j<col;j++)
		{
			if(matrix[i][j]=='#')
				dp1[i][j]=0;
			else
				dp1[i][j]=(dp1[i-1][j]+dp1[i][j-1])%mod;
		}
	}
	//for(int i=0;i<row;i++)
	//{
	//	for(int j=0;j<col;j++)
	//		cout<<dp1[i][j]<<" ";
	//		cout<<endl;
	//}
	return dp1[row-1][col-1];
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

	int row,col;
	cin>>row>>col;
	vector<vector<char>>matrix(row,vector<char>(col));
	for(int i=0;i<row;i++)
		for(int j=0;j<col;j++)
			cin>>matrix[i][j];

	//cout<<recursive(row-1,col-1,matrix)<<endl;
	//for(int i=0;i<row;i++)
	//{
	//	for(int j=0;j<col;j++)
	//		cout<<dp[i][j]<<" ";
	//	cout<<endl;
	//}
	cout<<bottomup(matrix);
	
}