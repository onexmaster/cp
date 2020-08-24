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
unordered_map<string,vector<pair<string,string>>>ada;
//here vertex are not used for vis data, but edges are used since to go from one vertex to another we can
//have more than 1 path and we need to explore all of them.
set<pair<string,pair<string,string>>>vis;
int dijktras(string src,string dest)
{
	//priority_queue holds total distance,current char(first char of each edge)and langugage
	priority_queue<pair<int,pair<char,string>>, vector<pair<int,pair<char,string>>>, greater<pair<int,pair<char,string>>>>pq;
	pq.push({0,{'A',src}});
	while(!pq.empty())
	{
		int curr_dist=pq.top().first;
		char curr_char=pq.top().second.first;
		string curr_lan=pq.top().second.second;
		pq.pop();
		if(curr_lan==dest)
			return curr_dist;
		//for all the outgoing edges from the curr language check if we can relax the edges or not
		for(auto edges:ada[curr_lan])
		{
			char outgoing_char=edges.second[0];
			int outgoing_dist=int(edges.second.size());
			string outgoing_language=edges.first;
			string outgoing_word=edges.second;
			//if the current char and the outgoing char are not same then i can use it to 
			//relax the edges
			//also check if the current edges is used or not if not add it in vis and use it
			//if it is not checked then pq will never become empty
			if(curr_char!=outgoing_char && vis.find({curr_lan,{outgoing_language,outgoing_word}})==vis.end())
			{
				pq.push({curr_dist+outgoing_dist,{outgoing_char,edges.first}});
				vis.insert({curr_lan,{outgoing_language,outgoing_word}});
			}
		}
	}
	return INF;	
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
	while(cin>>n)
	{
		if(n==0)
			 break;
		string src,dest;
		cin>>src>>dest;
		while(n--)
		{
			string u,v,c;
			cin>>u>>v>>c;
			//int cost=int(c,size());
			ada[u].pb({v,c});
			ada[v].pb({u,c});
		}
		int ans=dijktras(src,dest);
		if(ans==INF|| ans==0)
			cout<<"impossivel"<<endl;
		else
			cout<<ans<<endl;
		ada.clear();
		vis.clear();

	}

	
}