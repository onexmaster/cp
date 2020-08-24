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
int dist[MAXN][MAXN];
char grid[MAXN][MAXN];
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
		memset(dist,INF,sizeof(dist));
		memset(grid,'N',sizeof(grid));
		int n;
		cin>>n;
		string in,out;
		cin>>in>>out;
		for(int i=0;i<n;i++)
		{
			for(int j=0;j<n;j++)
			{
				if(abs(i-j)==1)
				{
					if(out[i]=='Y' && in[j]=='Y')
						dist[i][j]=1;
				}
			}
		}
		for(int i=0;i<n;i++)
			dist[i][i]=0;
		//floyd warshall
		for(int k=0;k<n;k++)
		{
			for(int i=0;i<n;i++)
			{
				for(int j=0;j<n;j++)
					dist[i][j]=min(dist[i][j],dist[i][k]+dist[k][j]);
			}
		}
		for(int i=0;i<n;i++)
		{
			for(int j=0;j<n;j++)
			{
				if(dist[i][j]!=INF)
					grid[i][j]='Y';
			}
		}
		cout<<"Case #"<<x<<":"<<endl;
		for(int i=0;i<n;i++)
		{
			for(int j=0;j<n;j++)
				cout<<grid[i][j];
			cout<<endl;
		}
		x++;
	}
	
}