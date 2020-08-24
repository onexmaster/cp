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
unordered_map<int,vector<int>>ada;
bool vis[MAXN];
bool ap[MAXN];
int disc[MAXN];
int low[MAXN];
int parent[MAXN];
int time1;
void low_link_dfs(int from)
{
	//cout<<src<<endl;
	vis[from]=true;
	int child=0;
	low[from]=disc[from]=time1++;
	for(auto to:ada[from])
	{
		//edge is parent of the current vertex
		if(to==parent[from])
			continue;
		//if back edge then update the low using the discovery time of to
		if(vis[to])
		{
			low[from]=min(low[from],disc[to]);
		}
		else
		{
			parent[to]=from;
			low_link_dfs(to);
			//use the low-link time from the children
			low[from]=min(low[from],low[to]);
			//if not root and of the lowlink time is greater than discovery time  of from
			if(low[to]>=disc[from] && parent[from]!=-1)
				ap[from]=true;
			++child;
		}
		
	}
	//if root and child is greater than 1 then it is an ap
	if(parent[from]==-1 && child>1)
		ap[from]=true;
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
	while(cin>>n, n!=0)
	{
		ada.clear();
		memset(parent,-1,sizeof(parent));
		memset(ap,false,sizeof(ap));
		memset(vis,false,sizeof(vis));
		memset(low,-1,sizeof(low));
		memset(disc,-1,sizeof(disc));
		time1=0;

		string s;
		while(getline(cin,s),s !="0")
		{
			stringstream ss(s);
			int u,v;
			ss>>u;
			while(ss>>v)
			{
				ada[u].pb(v);
				ada[v].pb(u);
			}

		}
		
		int count=0;
		for(int i=1;i<=n;i++)
		{
			if(!vis[i])
				low_link_dfs(i);
		}
		// for(int i=1;i<=n;i++)
		// 	cout<<ap[i]<<" ";
		// cout<<endl;
		// for(int i=1;i<=n;i++)
		// 	cout<<disc[i]<<" ";
		// cout<<endl;
		// for(int i=1;i<=n;i++)
		// 	cout<<low[i]<<" ";
		// cout<<endl;
		// for(int i=1;i<=n;i++)
		// 	cout<<parent[i]<<" ";
		// cout<<endl;
		for(int i=1;i<=n;i++)
			if(ap[i])
				count++;
		cout<<count<<endl;
		
		
		
	}
	
}