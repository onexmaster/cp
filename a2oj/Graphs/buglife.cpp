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
const int MAXN= 2005;
int color[MAXN];
unordered_map<int,vector<int>>ada;
bool bipartite(int source)
{
	queue<int>q;
	q.push(source);
	color[source]=1;
	while(!q.empty())
	{
		int parent=q.front();
		q.pop();
		for(auto children:ada[parent])
		{
			if(color[children]==-1)
			{
				q.push(children);
				color[children]=1-color[parent];
			}
			else if(color[children]==color[parent])
				return false;
		}
	}
	return true;
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
	int temp=1;
	while(t--)
	{
		//vector<int>ada[MAXN];
		int n,m;
		cin>>n>>m;
		bool ok=true;
		while(m--)
		{
			int a,b;
			cin>>a>>b;
			ada[a].pb(b);
			ada[b].pb(a);

		}
		memset(color,-1,sizeof(color));
		for(int i=1;i<n;i++)
		{
			if(color[i]==-1 && ok)
			{
				if(!bipartite(i))
				{
					ok=false;
				}
			}
		}
		if(ok)
		{
			cout<<"Scenario #"<<temp<<":"<<endl;
			cout<<"No suspicious bugs found!"<<endl;
		}
		else
		{
			cout<<"Scenario #"<<temp<<":"<<endl;
			cout<<"Suspicious bugs found!"<<endl;
		}
		temp++;
		ada.clear();
	}
	
}