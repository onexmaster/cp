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
const int MAXN=405;
int gridt[MAXN][MAXN];
int gridb[MAXN][MAXN];
int main()
{
	ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

	#ifndef ONLINE_JUDGE
	freopen("inputf.in","r",stdin);
	freopen("outputf.in","w",stdout);
	#endif

	int n,m;
	cin>>n>>m;
	memset(gridt,INF,sizeof(gridt));
	memset(gridb,INF,sizeof(gridb));
	while(m--)
	{
		int u,v;
		cin>>u>>v;
		u--;
		v--;
		gridt[u][v]=1;
		gridt[v][u]=1;
	}
	//if there is a path from 1-2 in railway then there cannot be a road path
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<n;j++)
		{
			if(i==j)
				continue;
			if(gridt[i][j]==INF)
				gridb[i][j]=1;

		}
			
	}
	// for(int i=0;i<n;i++)
	// {
	// 	for(int j=0;j<n;j++)
	// 		cout<<gridt[i][j]<<" ";
	// 	cout<<endl;
	// }
	// cout<<endl;
	// 	for(int i=0;i<n;i++)
	// {
	// 	for(int j=0;j<n;j++)
	// 		cout<<gridb[i][j]<<" ";
	// 	cout<<endl;
	// }
	//run floyd warhsall in gridt
	for(int k=0;k<n;k++)
	{
		for(int i=0;i<n;i++)
		{
			for(int j=0;j<n;j++)
			{
				gridt[i][j]=min(gridt[i][j],gridt[i][k]+gridt[j][k]);
			}
		}
	}
	//run floyd warhsall in gridb
		for(int k=0;k<n;k++)
	{
		for(int i=0;i<n;i++)
		{
			for(int j=0;j<n;j++)
			{
				gridb[i][j]=min(gridb[i][j],gridb[i][k]+gridb[j][k]);
			}
		}
	}

	if(gridb[0][n-1]==INF || gridt[0][n-1]==INF)
		cout<<-1;
	else
		cout<<max(gridb[0][n-1],gridt[0][n-1]);
	
	
	
}