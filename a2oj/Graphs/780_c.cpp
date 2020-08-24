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
int degree[MAXN];
int parent[MAXN];
int vis[MAXN];
int color[MAXN];
int max_color;
void bfs()
{
	queue<int>q;
	q.push(1);
	color[1]=1;
	vis[1]=true;
	parent[1]=0;
	color[0]=0;
	while(!q.empty())
	{
		

			
			int curr=q.front();
			q.pop();
			int col1=color[curr];
			int col2=color[parent[curr]];
			int curr_color=1;
			for(auto edges:ada[curr])
			{
				if(!vis[edges])
				{
					while(curr_color== col1 || curr_color==col2)
					{
						curr_color++;
						if(curr_color>max_color)
							curr_color=1;
					}
					color[edges]=curr_color;
					parent[edges]=curr;
					vis[edges]=true;
					q.push(edges);
					curr_color++;
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
	max_color=0;
	for(int i=0;i<t-1;i++)
	{
		int u,v;
		cin>>u>>v;
		ada[u].pb(v);
		ada[v].pb(u);
		degree[u]++;
		degree[v]++;
		max_color=max(max_color,max(degree[u],degree[v]));
	}
	 
	// for(int i=1;i<=t;i++)
	// 	max_color=max(max_color,degree[i]);
	max_color++;
	cout<<max_color<<endl;
	bfs();
	for(int i=1;i<=t;i++)
		cout<<color[i]<<" ";
	
}