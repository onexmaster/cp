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
int main()
{
	ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
 
	#ifndef ONLINE_JUDGE
	freopen("inputf.in","r",stdin);
	freopen("outputf.in","w",stdout);
	#endif
 
	ll row,col,k;
	cin>>row>>col>>k;
	ll x,y,x1,y1;
	cin>>x>>y>>x1>>y1;
	vector<vector<char>>grid(row,vector<char>(col));
	vector<vector<ll>>dist(row,std::vector<ll>(col,1e3));
	for(ll i=0;i<row;i++)
		for(ll j=0;j<col;j++)
			cin>>grid[i][j];
		
 
	queue<pair<ll,ll>>q;
	x--;
	y--;
	q.push({x,y});
	dist[x][y]=0LL;
	//vis[x][y]=true;
	while(!q.empty())
	{
		ll curr_x=q.front().first;
		ll curr_y=q.front().second;
		q.pop();
		for(ll i=0;i<4;i++)
		{
			for(ll j=1;j<=k;j++)
		{
			ll new_x=curr_x+j*moves[i][0];
			ll new_y=curr_y+j*moves[i][1];
			 if(new_x>=0 && new_x<row && new_y>=0 && new_y<col && grid[new_x][new_y]=='.' && (dist[new_x][new_y]==1e3 || dist[new_x][new_y]==dist[curr_x][curr_y]+1))
			{
					dist[new_x][new_y]=dist[curr_x][curr_y]+1LL;
					q.push({new_x,new_y});
					//vis[new_x][new_y]=true
			}
			else
				break;
		}
 
		}
	}
	// for(ll i=0;i<row;i++)
	// {
	// 	for(ll j=0;j<col;j++)
	// 		cout<<dist[i][j]<<" ";
	// 	cout<<endl;
	// }
	ll ans=dist[--x1][--y1];
	if(ans==0)
		cout<<-1;
	else
	{
		cout<<ans;
	}
}