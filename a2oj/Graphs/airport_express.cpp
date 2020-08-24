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
unordered_map<int,vector<pii>>ada;
int dist_src[505];
int dist_end[505];
int par_src[505];
int par_end[505];
int n,s,e;
void dijktras_src()
{
	priority_queue<pii,vector<pii>, greater<pii>>pq;
	pq.push({0,s});
	dist_src[s]=0;
	par_src[s]=-1;
	while(!pq.empty())
	{
		int curr_cost=pq.top().first;
		int curr=pq.top().second;
		pq.pop();
		for(auto edges:ada[curr])
		{
			if(dist_src[edges.first]>edges.second+curr_cost)
			{
				dist_src[edges.first]=edges.second+curr_cost;
				pq.push({dist_src[edges.first],edges.first});
				par_src[edges.first]=curr;
			}
		}
	}

}
void dijktras_end()
{
	priority_queue<pii,vector<pii>, greater<pii>>pq;
	pq.push({0,e});
	dist_end[e]=0;
	par_end[e]=-1;
	while(!pq.empty())
	{
		int curr_cost=pq.top().first;
		int curr=pq.top().second;
		pq.pop();
		for(auto edges:ada[curr])
		{
			if(dist_end[edges.first]>edges.second+curr_cost)
			{
				dist_end[edges.first]=edges.second+curr_cost;
				pq.push({dist_end[edges.first],edges.first});
				par_end[edges.first]=curr;
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
	 bool line = false;
	while(cin>>n>>s>>e)
	{
		ada.clear();
		int m;
		cin>>m;
		while(m--)
		{
			int u,v,c;
			cin>>u>>v>>c;
			ada[u].pb({v,c});
			ada[v].pb({u,c});
		}
		memset(dist_src,INF,sizeof(dist_src));
		memset(dist_end,INF,sizeof(dist_end));
		memset(par_src,-1,sizeof(par_src));
		memset(par_end,-1,sizeof(par_end));
		dijktras_src();
		dijktras_end();
		
		// for(int i=1;i<=n;i++)
		// 	cout<<dist_src[i]<<" ";
		// cout<<endl;
		// for(int i=1;i<=n;i++)
		// 	cout<<dist_end[i]<<" ";
		int x;
		cin>>x;
		int ans=dist_src[e];
		int comm_start=-1;
		int comm_end=-1;
		while(x--)
		{
			int u,v,c;
			cin>>u>>v>>c;
			//since it is bi-directional
			int cost=(dist_src[u]+c+dist_end[v]);
			if(cost<ans)
			{
				ans=cost;
				comm_start=u;
				comm_end=v;
			}
			cost=(dist_src[v]+c+dist_end[u]);
			if(cost<ans)
			{
				ans=cost;
				comm_start=v;
				comm_end=u;
			}
		}
		if(line)
		{
			cout<<endl;
		}
		line=true;
		//if ticket not used;
		if(comm_start==-1)
		{
			//get the path;
			vector<int>temp;
			int curr=e;
			while(curr!=-1)
			{
				temp.pb(curr);
				curr=par_src[curr];
			}
			reverse(temp.begin(),temp.end());
			for(int i=0;i<temp.size();i++)
			{
				cout<<temp[i];
				if(i<temp.size()-1)
					cout<<" ";
			}
			cout<<endl;
			cout<<"Ticket Not Used"<<endl;
			cout<<ans<<endl;
		}
		else
		{
			//get the path to u from src
			vector<int>temp1;
			 int curr=comm_start;
			while(curr!=-1)
			{
				temp1.pb(curr);
				curr=par_src[curr];
			}
			reverse(temp1.begin(),temp1.end());
			 curr=comm_end;
			while(curr!=-1)
			{
				temp1.pb(curr);
				curr=par_end[curr];
			}
			for(int i=0;i<temp1.size();i++)
			{
				cout<<temp1[i];
				if(i<temp1.size()-1)
					cout<<" ";
			}
			cout<<endl;
			cout<<comm_start<<endl;
			cout<<ans<<endl;
		}
	}
	
}