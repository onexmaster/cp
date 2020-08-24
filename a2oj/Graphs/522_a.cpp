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
unordered_map<string,int>dp;
int bfs(string src)
{
	queue<string>q;
	q.push(src);
	int ans=0;
	while(!q.empty())
	{
		int curr_size=q.size();
		for(int i=0;i<curr_size;i++)
		{
			string curr=q.front();
			q.pop();
			for(auto edges:ada[curr])
			{
				q.push(edges);
			}
		}
		ans++;

	}
	return ans;
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
		string u,x,v;
		cin>>u>>x>>v;
		transform(u.begin(),u.end(),u.begin(),::tolower);
		transform(v.begin(),v.end(),v.begin(),::tolower);
		
		ada[v].pb(u);
	}
	cout<<bfs("polycarp");
	
}