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
const int MAXN=1e7+5;
bool vis[MAXN];
int bfs(int s, int e)
{
	memset(vis,false,sizeof(vis));
	queue<int>q;
	q.push(s);
	int step=0;
	vis[s]=true;
	while(!q.empty())
	{
		int curr_size=q.size();
		for(int i=0;i<curr_size;i++)
		{
			int curr=q.front();
			//cout<<curr<<endl;
			q.pop();
			if(curr==e)
				return step;
			if(!vis[curr*2] && curr*2<=2*e)
			{
				q.push(curr*2);
				vis[2*curr]=true;
			}
			if(!vis[curr-1] && curr-1>0)
			{
				q.push(curr-1);
				vis[curr-1]=true;
			}
		}
		step++;
	}
	return -1;
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

	int n,m;
	cin>>n>>m;
	if(n>m)
			cout<<n-m;
	else
		cout<<bfs(n,m);
	
}