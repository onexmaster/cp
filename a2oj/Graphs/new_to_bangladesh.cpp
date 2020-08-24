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
ll time1[MAXN][MAXN];
ll dist[MAXN][MAXN];
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
	while(t--)
	{
		
		int n,m;
		cin>>n>>m;
		for(int i = 1; i <=n; i++)
            for(int j = 1; j <=n; j++)
                if(i == j) dist[i][j] = 0;
                else dist[i][j] = 1LL<<60, time1[i][j] = 1LL<<60;
		while(m--)
		{
			ll u,v,t,l;
			cin>>u>>v>>t>>l;
			if(t<time1[u][v] || t==time1[u][v] && dist[u][v]>l)
			{
				time1[u][v]=t;
				time1[v][u]=t;
				dist[u][v]=l;
				dist[v][u]=l;
			}


		}
		//run floyd warshal on time and while updating the time find the corresponding dist as well
		for(int k=1;k<=n;k++)
		{
			for(int i=1;i<=n;i++)
			{
				for(int j=1;j<=n;j++)
				{
					if(time1[i][j]>time1[i][k]+time1[j][k])
					{
						time1[i][j]=time1[i][k]+time1[j][k];
						dist[i][j]=dist[i][k]+dist[j][k];
					}
					else if(time1[i][j]==time1[i][k]+time1[j][k] && dist[i][j]>dist[i][k]+dist[j][k])
						dist[i][j]=dist[i][k]+dist[j][k];
				}
			}
		}
		int q;
		cin>>q;
		while(q--)
		{
			int src,dest;
			cin>>src>>dest;
			if(dist[src][dest]==(1LL<<60))
			{
				cout<<"No Path."<<endl;
			}
			else
			{
				cout<<"Distance and time to reach destination is "<<dist[src][dest]<<" & "<<time1[src][dest]<<"."<<endl;

			}
		}
	if(t)
		cout<<endl;
	
	}
	
}