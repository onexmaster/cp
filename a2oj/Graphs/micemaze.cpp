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
int dist[MAXN];
//for disjktars
map<int,vector<pii>>ada1;
//for flyod warshall i need a adjanecy matirx 
int ada[MAXN][MAXN];
//number of vertex( NEEDED FOR RELAXTION )
int n;

/*
void dijkstras(int source)
{
	
	for(int i=0;i<MAXN;i++)
		dist[i]=1e9;

	dist[source]=0;
	priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>> >pq;
	pq.push({0,source});
	while(!pq.empty())
	{
		int cost=pq.top().first;
		int curr=pq.top().second;
		pq.pop();
		for(auto edges: ada[curr])
		{
			if(dist[edges.first]>cost + edges.second)
			{
				dist[edges.first]=cost+edges.second;
				pq.push({dist[edges.first],edges.first});
			}
		}
	}
}
*/
//All pair shortest path so we do not need any source vertex
void floyd_warshall()
{
	//fill the diagonals values with 0 and rest all values with 1e9
	
	for(int i=1;i<=n;i++)
		for(int j=1;j<=n;j++)
			if(ada[i][j]==0)
				ada[i][j]=1e9;

	for(int i=1;i<=n;i++)
		ada[i][i]=0;

	//start floyd warshall
	for(int k=1;k<=n;k++)
	{
		for(int i=1;i<=n;i++)
		{
			for(int j=1;j<=n;j++)
				ada[i][j]=min(ada[i][j],ada[i][k] +ada[k][j]);
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

	cin>>n;
	int exit;
	cin>>exit;
	int time;
	cin>>time;
	int t;
	cin>>t;

	
	//Reversed the edges to run dijkstras from destination vertex;
	// for(int i=0;i<t;i++)
	// {
	// 	int x,y,cost;
	// 	cin>>x>>y>>cost;
	// 	ada1[y].pb({x,cost});
	// }
	// dijkstras(exit);

	// int ans=0;
	// for(int i=1;i<=n;i++)
	// 	if(dist[i]<=time)
	// 		ans++;
	//cout<<ans;


	for(int i=0;i<t;i++)
	{
		int x,y,cost;
		cin>>x>>y>>cost;
		ada[x][y]=cost;
	}
	
	
	floyd_warshall();
	// for(int i=1;i<=n;i++)
	// {
	// 	for(int j=1;j<=n;j++)
	// 		cout<<ada[i][j]<<" ";
	// 	cout<<endl;
	// }
	int ans=0;
	//iterate over the exit vertex and find out the answer 
	//thats is for column 2 which is the shortest time taken to all the other vextex ,
	//if the time is less than "Time", it means the mice can reach from that vertex to 2 
	for(int i=1;i<=n;i++)
		if(ada[i][exit]<=time)
			ans++;
	cout<<ans;

	return 0;

	
}