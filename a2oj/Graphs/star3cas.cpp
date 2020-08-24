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
unordered_map<int,vector<int>>ada;
//int vis[MAXN];
int stairs[MAXN];
int dist[MAXN];
int n;
void bfs()
{
	memset(dist,INF,sizeof(dist));
	queue<int>q;
	q.push(0);
	dist[0]=0;
	while(!q.empty())
	{
		int curr=q.front();
		q.pop();
		for(auto edges:ada[curr])
		{
			if(dist[edges]>dist[curr]+1)
			{
				q.push(edges);
				dist[edges]=dist[curr]+1;
			}
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

	int t;
	cin>>t;
	while(t--)
	{	
		memset(stairs,INF,sizeof(INF));
		cin>>n;
		for(int i=0;i<n;i++)
			cin>>stairs[i];
		for(int i=0;i<n;i++)
		{
			if(stairs[i]>=0)
			{
				if(i+1<=n)
					ada[i].pb(i+1);
				if(i+stairs[i]<=n)
					ada[i].pb(i+stairs[i]);
			}
			else if(stairs[i]<0)
			{
				if(i+1<=n)
					ada[i].pb(i+1);
				if(i+stairs[i]>=0)
					ada[i].pb(i+stairs[i]);
			}
		}
		bfs();
		cout<<dist[n]<<endl;
		ada.clear();
		
	}
	
	
}