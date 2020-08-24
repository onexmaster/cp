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
int dx[] = {-2, -1, 1, 2, -2, -1, 1, 2}; 
int dy[] = {-1, -2, -2, -1, 1, 2, 2, 1}; 
bool vis[8][8];
int dist[8][8];
void bfs(int x, int y)
{
	memset(vis,false,sizeof(vis));
	memset(dist,1e6,sizeof(dist));
	vis[x][y]=true;
	queue<pair<int,int>>q;
	q.push({x,y});
	dist[x][y]=0;
	while(!q.empty())
	{
		int curr_x=q.front().first;
		int curr_y=q.front().second;
		q.pop();
		//cout<<curr_x<<" "<<curr_y<<endl;
		for(int i=0;i<8;i++)
		{
			int new_x=curr_x+dx[i];
			int new_y=curr_y+dy[i];
			if(new_x>=0 && new_x<8 && new_y>=0 && new_y<8 && !vis[new_x][new_y])
			{
				dist[new_x][new_y]=dist[curr_x][curr_y]+1;
				vis[new_x][new_y]=true;
				q.push({new_x,new_y});
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

	// int t;
	// cin>>t;
	string start,end;
	while(cin>>start>>end)
	{
		// string start,end;
		// cin>>start>>end;
		int x=start[0]-'a';
		int y=start[1]-'0';
		//cout<<x<<" "<<y<<endl;
		bfs(x,--y);
		int end_x=end[0]-'a';
 		int end_y=end[1]-'0';
 		//cout<<end_x<<" "<<end_y<<endl;
 		int ans=dist[end_x][--end_y];
 		//cout<<ans<<endl;
 		cout<<"To get from "<<start<<" to "<<end<<" takes "<<ans<<" knight moves."<<endl;
 		// for(int i=0;i<8;i++)
 		// {
 		// 	for(int j=0;j<8;j++)
 		// 		cout<<dist[i][j]<<" ";
 		// 	cout<<endl;
 		// }
	}
	
}