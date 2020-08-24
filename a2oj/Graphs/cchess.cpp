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
int dist[9][9];
//bool vis[9][9]
void dijsktras(int x, int y)
{
	memset(dist,INF,sizeof(dist));
	priority_queue<pair<int,pii>, vector<pair<int,pii>>, greater<pair<int,pii>>>pq;
	pq.push({0,{x,y}});
	dist[x][y]=0;
	while(!pq.empty())
	{
		int curr_cost=pq.top().first;
		int curr_x=pq.top().second.first;
		int curr_y=pq.top().second.second;
		pq.pop();
		for(int i=0;i<8;i++)
		{
			int new_x=curr_x+knight_moves[i][0];
			int new_y=curr_y+knight_moves[i][1];
			if(new_x>=0 && new_x<8 && new_y>=0 && new_y<8 && 
				dist[new_x][new_y]>curr_cost+(curr_x*new_x+curr_y*new_y))
			{
				dist[new_x][new_y]=curr_cost+(curr_x*new_x+curr_y*new_y);
				pq.push({dist[new_x][new_y],{new_x,new_y}});
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

	int x0,y0,x1,y1;
	while(cin>>x0>>y0>>x1>>y1)
	{
		dijsktras(x0,y0);
		cout<<dist[x1][y1]<<endl;
	}
	
}