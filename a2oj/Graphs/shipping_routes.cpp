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
unordered_map<string,vector<string>>ada;
vector<string>city;
unordered_map<string,int>dist;
void bfs(string source)
{
	queue<string>q;
	q.push(source);
	dist[source]=0;
	while(!q.empty())
	{
		string curr=q.front();
		q.pop();
		for(auto edges:ada[curr])
		{
			if(dist.count(edges)==0)
			{
				q.push(edges);
				dist[edges]=dist[curr]+100;
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
	int x=1;
	cout<<"SHIPPING ROUTES OUTPUT"<<endl;
	cout<<endl;
	while(t--)
	{
		int m,n,p;
		cin>>m>>n>>p;

	while(m--)
	{
		string st;
		cin>>st;
		city.pb(st);
	}
	while(n--)
	{
		string u,v;
		cin>>u>>v;
		ada[u].pb(v);
		ada[v].pb(u);
	}
	cout<<"DATA SET  "<<x<<endl;
	cout<<endl;
	while(p--)
	{
		int cost;
		string src,dest;
		cin>>cost>>src>>dest;
		dist.clear();
		bfs(src);
		if(dist.count(dest)==0)
			cout<<"NO SHIPMENT POSSIBLE"<<endl;
		else
			cout<<"$"<<cost*dist[dest]<<endl;

	}
	cout<<endl;
	ada.clear();
	city.clear();
	x++;
}
cout<<"END OF OUTPUT"<<endl;
	
}