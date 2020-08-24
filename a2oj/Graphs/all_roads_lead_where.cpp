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
unordered_map<string,int>dist;
unordered_map<string,string>par;
void bfs(string source)
{
	dist.clear();
	par.clear();
	queue<string>q;
	q.push(source);
	dist[source]=0;
	par[source]="";
	while(!q.empty())
	{
		string curr=q.front();
		q.pop();
		for(auto edges:ada[curr])
		{
			if(dist.count(edges)==0)
			{
				q.push(edges);
				dist[edges]=dist[curr]+1;
				par[edges]=curr;
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
	bool last=false;
	while(t--)
	{
		ada.clear();
		int roads,test;
		cin>>roads>>test;
		while(roads--)
		{
			string a ,b;
			cin>>a>>b;
			ada[a].pb(b);
			ada[b].pb(a);
		}
		while(test--)
		{
			string source,dest;
			cin>>source>>dest;
			bfs(source);
			vector<string>temp;
			temp.pb(dest);
			string parent=par[dest];
			while(parent!="")
			{
				temp.pb(parent);
				parent=par[parent];
			}
			reverse(temp.begin(),temp.end());
			for(int i=0;i<temp.size();i++)
				cout<<temp[i][0];
			cout<<endl;

		}
		if(t>0)
			cout<<endl;
	}
	
}