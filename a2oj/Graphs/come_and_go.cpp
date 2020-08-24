// Created by Tanuj Jain
//First Tarjan Problem 
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
const int MAXN=2e4+5;
unordered_map<int,vector<int>>ada;
//also can be seen as vis
bool on_stack[MAXN];
int low_link[MAXN];
int disc_time[MAXN];
int first_time;
//This vector will store the strongly connected components in it 
vector<vector<int>>scc;
void tarjan(int u)
{
	static stack<int>st;
	low_link[u]=disc_time[u]=first_time++;
	on_stack[u]=true;
	st.push(u);
	for(auto v:ada[u])
	{
		//if not visitied 
		if(disc_time[v]==-1)
		{
			tarjan(v);
			low_link[u]=min(low_link[u],low_link[v]);
		}
		//if back edge
		if(on_stack[v])
			low_link[u]=min(low_link[u],disc_time[v]);
	}
	//an scc can be found if the discovery time and low-link time of all the vertex is same
	//scc found 
	if(low_link[u]==disc_time[u])
	{
		vector<int>temp;
		//all the elements in the current stack belong to same scc
		while(1)
		{
			int curr=st.top();
			st.pop();
			temp.pb(curr);
			on_stack[curr]=false;
			if(u==curr)
				break;
		}
		scc.pb(temp);
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

	int n,m;
	while(cin>>n>>m)
	{
		if(n==0 && m==0)
			return 0;
	while(m--)
	{
		int u,v,con;
		cin>>u>>v>>con;
		if(con==1)
			ada[u].pb(v);
		else
		{
			ada[u].pb(v);
			ada[v].pb(u);
		}
	}
	memset(disc_time,-1,sizeof(disc_time));
	memset(low_link,-1,sizeof(low_link));
	memset(on_stack,false,sizeof(on_stack));
	first_time=1;
	for(int i=1;i<=n;i++)
		if(disc_time[i]==-1)
			tarjan(i);
	//cout<<scc.size()<<endl;
	if(scc.size()>1)
		cout<<0<<endl;
	else
		cout<<1<<endl;
	ada.clear();
	scc.clear();
}

	
}