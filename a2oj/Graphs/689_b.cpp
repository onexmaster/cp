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
const int MAXN=2e5+5;
vector<int>ada[MAXN];
int dist[MAXN];
void bfs()
{
	memset(dist,INF,sizeof(dist));
	queue<int>q;
	q.push(1);
	dist[1]=0;
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

	int n;
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		//there is no point of adding edges from i to i+2,i+3 etc
		ada[i].pb(i+1);
		ada[i].pb(i-1);
		int x;
		cin>>x;
		ada[i].pb(x);
	}
	bfs();
	for(int i=1;i<=n;i++)
		cout<<dist[i]<<" ";
}