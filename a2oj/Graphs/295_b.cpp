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
const int MAXN=505;
ll dist[MAXN][MAXN];
ll rows[MAXN];
ll ans[MAXN];
int n;
void print()
{
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=n;j++)
			cout<<dist[i][j]<<" ";
		cout<<endl;
	}
	cout<<endl;
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

	cin>>n;
	for(int i=1;i<=n;i++)
		for(int j=1;j<=n;j++)
			cin>>dist[i][j];
	for(int i=1;i<=n;i++)
		cin>>rows[i];
	for(int i=n;i>0;i--)
	{
		for(int j=1;j<=n;j++)
		{
			for(int k=1;k<=n;k++)
				dist[j][k]=min(dist[j][k],dist[j][rows[i]]+dist[rows[i]][k]);
		}
		print();
		 ans[i]=0;
	for(int j=i;j<=n;j++)
	{
		for(int k=i;k<=n;k++)
			ans[i]+=dist[rows[j]][rows[k]];
	}
	
	}
	for(int i=1;i<=n;i++)
		cout<<ans[i]<<" ";
	
}