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

const int  MAXN=5e4+5;
vector<int> dis(MAXN);
map<int,vector<pair<int,int>>>edges;



//Return the index of the vertex which is the farthest from the random root intially
//IN the second bst the fartheset node from the node of first bfs is the diameter of the tree
int bfs(int source)
{

	bool visited[MAXN]={false};
	for(int i=0;i<MAXN;i++)
		dis[i]=0;
	queue<int>q;
	q.push(source);
	visited[source]=true;
	while(!q.empty())
	{
		int curr=q.front();
		q.pop();
		//cout<<curr<<endl;
		for(auto children : edges[curr])
		{
			if(!visited[children.first])
			{
				q.push(children.first);
				visited[children.first]=true;
				dis[children.first]=dis[curr]+children.second;
			}
		}
	}
	return (max_element(dis.begin(),dis.end())-dis.begin());
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
		int n;
		cin>>n;
		//map<int,vector<pair<int,int>>>edges;
		for(int i=0;i<n-1;i++)
			{
				int source,dest,weight;
				cin>>source>>dest>>weight;
				//cout<<source<<" "<<dest<<" "<<weight<<endl;
				edges[source].pb({dest,weight});
				edges[dest].pb({source,weight});
			}
		//for(auto it :edges)
		//{
		//		cout<<it.first<<" ";
		//	for(auto children:edges[it.first])
		//		cout<<children.first<<" ";
		//	cout<<endl;
		//}
		//cout<<endl;

		//run dfs from a random node, lets take '1'
			int temp=bfs(1);
		//run dfs from temp node
			int temp2=bfs(temp);
		//Now temp 2 has the node which is the end of the diameter and the value
		//in distance vector of this temp2 is the diameter aka longest path
			cout<<dis[temp2]<<endl;
			edges.clear();

	}

	
}