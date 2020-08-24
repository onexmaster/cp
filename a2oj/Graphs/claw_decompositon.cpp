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
unordered_map<int,vector<int>>ada;
int t;
set<pii>vis;
int main()
{
	ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

	#ifndef ONLINE_JUDGE
	freopen("inputf.in","r",stdin);
	freopen("outputf.in","w",stdout);
	#endif

	while(cin>>t)
	{
		if(t==0)
			return 0;

		int u,v;
		while(cin>>u>>v)
		{
			if(u==0 && v==0)
				break;
			ada[u].pb(v);
			ada[v].pb(u);
		}
		bool ok=true;
		for(int u=1;u<=t/2;u++)
		{
			int c=0;
			for(auto v:ada[u])
			{
				c++;
				//cout<<u<<" "<<v<<endl;
				if((vis.find({v,u})!=vis.end()))
				{
					ok=false;
					break;
				}
				else
					vis.insert({u,v});
			}
			// if(c!=3)
			// {
			// 	ok=false;
			// 	break;
			// }
		}
		if(!ok)
			cout<<"NO"<<endl;
		else
			cout<<"YES"<<endl;
		ada.clear();
		vis.clear();
	}
	
}