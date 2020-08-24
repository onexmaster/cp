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
		int n;
		cin>>n;
		int dist[n][n];
		memset(dist,INF,sizeof(dist));
		int m;
		cin>>m;
		while(m--)
		{
			int u,v;
			cin>>u>>v;
			dist[u][v]=1;
			dist[v][u]=1;
		}
		//fill diagonals as 0
		for(int i=0;i<n;i++)
			dist[i][i]=0;
		//run floyd warshall
		for(int k=0;k<n;k++)
		{
			for(int i=0;i<n;i++)
			{
				for(int j=0;j<n;j++)
					dist[i][j]=min(dist[i][j],dist[i][k]+dist[k][j]);
			}
		}

		int start,end;
		cin>>start>>end;
		int ans=0;
		for(int i=0;i<n;i++)
		{
			if(dist[start][i]!=INF && dist[i][end]!=INF)
				ans=max(ans,dist[start][i]+dist[i][end]);

		}
		cout<<"Case "<<x<<": "<<ans<<endl;
		x++;
	}
	
}