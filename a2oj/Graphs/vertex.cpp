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
int vis[MAXN];

void dfs(int src, int orig)
{
	vis[src]++;
	for(auto edges:ada[src])
	{
		if((edges==orig && vis[orig]<2) || !vis[edges] )
			dfs(edges,orig);
	}
}
int main {
	ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

	#ifndef ONLINE_JUDGE
	freopen("inputf.in","r",stdin);
	freopen("outputf.in","w",stdout);
	#endif

	int t;
	while(cin>>t)
	{
		if(t==0)
			return 0;
		int source;
		while(cin>>source)
		{
			if(source==0)
				break;
			int edges;
			while(cin>>edges)
			{
				if(edges==0)
					break;
				ada[source].pb(edges);
			}
		}
		int test_case;
		cin>>test_case;
		while(test_case--)
		{
			memset(vis,0,sizeof(vis));
			int src;
			cin>>src;
			dfs(src,src);
			//find the unvisisted vertex
			//if self loop not preset then the src itself is not reachable
			vector<int>temp;
			vector<int>temp1=ada[src];
			if(vis[src]==1)
				temp.pb(src);


			for(int i=1;i<=t;i++)
				if(!vis[i])
					temp.pb(i);
			int ans=temp.size();
			if(ans==0)
				cout<<0<<endl;
			else
			{
				sort(temp.begin(),temp.end());
				cout<<ans;
				for(int i=0;i<temp.size();i++)
					cout<<" "<<temp[i];
				cout<<endl;
			}

		}
		ada.clear();

	}
	
}