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
const int MAXN=1e6+5;
vector<int>ada[MAXN];
int col[MAXN];
bool bipart(int src)
{
	queue<int>q;
	q.push(src);
	col[src]=1;
	while(!q.empty())
	{
		int curr=q.front();
		q.pop();
		for(auto edges:ada[curr])
		{
			if(edges==curr)
				continue;
			if(col[edges]==-1)
			{
				col[edges]=1-col[curr];
				q.push(edges);
			}
			else if(col[edges]==col[curr])
				return false;
		}
	}
	return true;
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

	int n,m;
	cin>>n>>m;
	for(int i=0;i<m;i++)
	{
		int u,v;
		cin>>u>>v;
		ada[u].pb(v);
		ada[v].pb(u);
	}
	memset(col,-1,sizeof(col));
	for(int i=1;i<=n;i++)
	{
		if(col[i]==-1)
		{
			if(!bipart(i))
			{
				cout<<-1;
				return 0;
			}
		}
	}
	vector<int>x,y;
	for(int i=1;i<=n;i++)
	{
		if(col[i]==0)
			x.pb(i);
		else
			y.pb(i);	
	}
	cout<<int(x.size())<<endl;
	for(int i=0;i<x.size();i++)
		cout<<x[i]<<" ";
	cout<<endl;
	cout<<int(y.size())<<endl;
	for(int i=0;i<y.size();i++)
		cout<<y[i]<<" ";

}