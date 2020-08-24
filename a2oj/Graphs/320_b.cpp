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
map<pair<int,int>,vector<pair<int,int>>>ada;
set<pair<int,int>>vis;
unordered_map<int,pair<int,int>>pairs;
void dfs(pair<int,int>curr)
{
	vis.insert(curr);
	for(auto edges:ada[curr])
		if(vis.find(edges)==vis.end())
			dfs(edges);
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
	while(t--)
	{
		int type,c,d;
		cin>>type>>c>>d;
		if(type==1)
		{
			bool ok=false;
			
				for(auto it:ada)
				{
					int a=it.first.first;
					int b=it.first.second;
					if((c<a && a<d)||(c<b && b<d))
					{
						ada[{a,b}].pb({c,d});
					}
					if((a<c && c<b) || (a<d && d<b))
					{
						ada[{c,d}].pb({a,b});
						ok=true;
					}
 
				}
				if(!ok)
					ada[{c,d}].pb({INF,INF});
				pairs[x]={c,d};
				x++;
			}
			
		else
		{
			//cout<<t<<" "<<"HERE"<<endl;
			vis.clear();
			pii start=pairs[c];
			pii end=pairs[d];
			dfs(start);
			if(vis.find(end)!=vis.end())
				cout<<"YES"<<endl;
			else
				cout<<"NO"<<endl;
		}
	}
	
}