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
const int MAXN=2505;
vector<int>ada[MAXN];
bool vis[MAXN];
void bfs(int src)
{
	if(ada[src].empty())
		{
			cout<<0<<endl;
			return;
		}
	memset(vis,false,sizeof(vis));
	queue<int>q;
	q.push(src);
	vis[src]=true;;
	int max_no=-1;
	int max_day=-1;
	int day=0;
	while(!q.empty())
	{
		int curr_size=q.size();
		if(max_no<curr_size)
		{
			max_no=curr_size;
			max_day=day;
		}
		for(int i=0;i<curr_size;i++)
		{
			int curr=q.front();
			q.pop();
			for(auto edges:ada[curr])
			{
				if(!vis[edges])
				{
					vis[edges]=true;
					q.push(edges);
				}
			}
		}
		day++;
		
	}
	if(max_day==0)
		cout<<max_no<<" "<<++max_day<<endl;
	else
		cout<<max_no<<" "<<max_day<<endl; 

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
	int x=0;
	while(t--)
	{
		int n;
		cin>>n;
		while(n--)
		{
			int temp;
			cin>>temp;
			ada[x].pb(temp);
			//ada[temp].pb(x);
		}
		x++;
	}
	int test_cases;
	cin>>test_cases;
	while(test_cases--)
	{
		int src;
		cin>>src;
		bfs(src);
	}
	return 0;
}