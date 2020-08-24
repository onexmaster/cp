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
double dist[MAXN];
double ada_f[MAXN][MAXN];
void dijkstras(map<int,vector<pair<int,double>>>&ada, int n)
{
	for(int i=1;i<=n;i++)
		dist[i]=-1.0;
	dist[1]=1.0;
	//using max heap here, since we want to find the path which maximizes my probabilty
	priority_queue<pair<double,int>>pq;
	pq.push({1.0,1});
	while(!pq.empty())
	{
		double curr_prob=pq.top().first;
		int curr=pq.top().second;
		pq.pop();
		//cout<<curr<<endl;
		for(auto edges : ada[curr])
		{
			if(dist[edges.first]<curr_prob*edges.second)
			{
				dist[edges.first]=curr_prob*edges.second;
				pq.push({dist[edges.first], edges.first});
			}
		}
	}
}
void floyd_warshall(int n)
{
	for(int k=1;k<=n;k++)
	{
		for(int i=1;i<=n;i++)
		{
			for(int j=1;j<=n;j++)
				ada_f[i][j]=max(ada_f[i][j], ada_f[i][k]*ada_f[j][k]);
		}
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

	int n;
	while(cin>>n)
	{
		if(n==0)
			return 0;
		else
		{
			int m;
			cin>>m;
			map<int,vector<pair<int,double>>>ada;
			for(int i=0;i<m;i++)
			{
				int x,y;
				double prob;
				cin>>x>>y>>prob;
				prob/=100.0;
				ada[x].pb({y,prob});
				ada[y].pb({x,prob});
				ada_f[x][y]=prob;
				ada_f[y][x]=prob;
			}
			dijkstras(ada, n);

			 //floyd_warshall(n);
			// for(int i=1;i<=n;i++)
			// 	cout<<dist[i]<<" ";
			// cout<<endl;
			// for(int i=1;i<=n;i++)
			// {
			// 	for(int j=1;j<=n;j++)
			// 		cout<<ada_f[i][j]<<" ";
			// 	cout<<endl;
			// }
			
			//cout<<fixed<<setprecision(6)<<dist[n]*100<<" "<<"percent"<<endl;
			 //cout<<fixed<<setprecision(6)<<ada_f[1][n]*100<<" "<<"percent"<<endl;
		}
	}

	
}