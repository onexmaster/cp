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
const int MAXN=1e2+5;
map<int,int>vis;
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
	int temp=1;
	while(cin>>n)
	{
		if(n==0)
			return 0;
		map<int,vector<int>>ada;
		while(n--)
		{
			int x,y;
			cin>>x>>y;
			ada[x].pb(y);
			ada[y].pb(x);
		}
		int src,ttl;
		while(cin>>src>>ttl)
		{
			if(src==0 && ttl==0)
				break;
			//set<int>vis;
			vis.clear();
			queue<int>q;
			q.push(src);
			vis[src]=0;
			while(!q.empty())
			{
				int curr=q.front();
				q.pop();
				for(auto edges:ada[curr])
				{
					if(!vis.count(edges))
					{
						vis[edges]=vis[curr]+1;
						q.push(edges);
					}
				}
				
			}
			int ans=0;
			for(auto it :vis)
			{
				if(it.second>ttl)
					ans++;
			}
			 ans+=ada.size()-vis.size();
			cout<<"Case "<<temp<<": "<<ans<<" nodes not reachable from node "<<src<<" with TTL = "<<ttl<<"."<<endl;
			temp++;

		}

	}
	
}