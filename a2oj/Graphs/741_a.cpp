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
const int MAXN=1e2+5;
vector<int>ada[MAXN];
int count1;
bool vis[MAXN];
int in_degree[MAXN];
int gcd(int a,int b)
{
	if(b==0)
		return a;
	return gcd(b,a%b);
}
void dfs(int src)
{
	count1++;
	vis[src]=true;
	for(auto edges:ada[src])
		if(!vis[edges])
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
	for(int i=0;i<t;i++)
	{
		int u=i;
		int v;
		cin>>v;
		--v;
		ada[u].pb(v);
		//ada[v].pb(u);
		in_degree[v]++;
	}
	for(int i=0;i<t;i++)
	{
		if(in_degree[i]==0)
		{
			cout<<-1;
			return 0;
		}
	}
		
	vector<int>cycle;
	for(int i=0;i<t;i++)
	{
		//if not vis
		//do dfs and calculate the cycle length
		//if the cycle length is odd then we have take the whole legth to satisfy the
		//given condition i.e to be joon-joon 
		//eg(1->2->3)so to start at 1 and end at 1 we have to take 3 steps and same for others
		//but if cycle is(1->2->3->4)
		//Then if 1 starts and we take a length of 2 then it ends at 3 and if 3 start then it ends
		//at 1 so(for 1 ->3 becomes joon joon and for 3 ->1 becomes joon joon)and hence the condition is still satisfies
		if(!vis[i])
		{
			count1=0;
			dfs(i);
			if(count1%2==0)
				count1/=2;
			cycle.pb(count1);
		}
	}
	//in the end to find a common time t for all the differnt length cycles we need to take lcm

	ll ans=cycle[0];
	for(int i=1;i<cycle.size();i++)
	{
		ans=(cycle[i]*ans)/(gcd(cycle[i],ans));
	}
	cout<<ans;
}