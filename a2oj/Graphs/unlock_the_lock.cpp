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
string start,target,nos;
const int MAXN=1e5+10;
bool vis[MAXN];
int dist[MAXN];
vector<int>moves1;
void bfs(int begin, int final)
{
	queue<int>q;
	q.push(begin);
	dist[begin]=0;
	vis[begin]=true;
	while(!q.empty())
	{
		int curr=q.front();
		q.pop();
		//cout<<curr<<endl;
		for(int i=0;i<moves1.size();i++)
		{
			int new_val=(curr+moves1[i])%10000;
			if(!vis[new_val])
			{
				q.push(new_val);
				vis[new_val]=true;
				dist[new_val]=dist[curr]+1;
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

	int x=1;
	while(cin>>start>>target>>nos)
	{
		if(start=="0" && target=="0" && nos=="0")
			return 0;
		int n=stoi(nos);
		while(n--)
		{
			string st;
			cin>>st;
			moves1.pb(stoi(st));
		}
		memset(vis,false,sizeof(vis));
		memset(dist,INF,sizeof(dist));
		int begin=stoi(start);
		int final=stoi(target);
		bfs(begin,final);
		if(!vis[final])
			cout<<"Case "<<x<<": "<<"Permanently Locked"<<endl;
		else
			cout<<"Case "<<x<<": "<<dist[final]<<endl;
		moves1.clear();
		x++;

	}
}