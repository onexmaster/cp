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
unordered_set<string>vis;
vector<string>suffix;
int n,m;
void go(string s, int i)
{
	if(i==n)
	{
		suffix.pb(s);
		return;
	}
	for(char j:{'a','b','c','d','e','f'})
		go(s+j,i+1);

}
bool bfs(string src)
{
	queue<string>q;
	q.push(src);
	vis.insert(src);
	while(!q.empty())
	{
		string curr=q.front();
		q.pop();
		//cout<<curr<<endl;
		if(curr=="a")
			return true;
		if(curr.size()>=2)
		{
			string temp=curr.substr(0,2);
			//cout<<temp<<" "<<temp.size();
			for(auto edges:ada[temp])
			{
				//cout<<edges<<endl;  
				string new_str=edges+curr.substr(2,curr.size());
				//cout<<new_str<<endl;
				if(vis.find(new_str)==vis.end())
				{
					q.push(new_str);
					vis.insert(new_str);
				}
			}
		}
	}
	return false;
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

	
	
	cin>>n>>m;
	go("",0);
	while(m--)
	{
		string u,v;
		cin>>u>>v;
		ada[u].pb(v);
	}
	int count=0;
	for(int i=0;i<suffix.size();i++)
		{
			vis.clear();
			if(bfs(suffix[i]))
				count++;
		}
		cout<<count;
	
}