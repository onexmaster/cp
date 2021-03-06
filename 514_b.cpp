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
double neg_infinity(-std::numeric_limits<double>::infinity());
int main()
{
	ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

	#ifndef ONLINE_JUDGE
	freopen("inputf.in","r",stdin);
	freopen("outputf.in","w",stdout);
	#endif

	double n,x1,y1,xi,yi,dy,dx,slope;
	cin>>n>>x1>>y1;
	set<double>temp;
	//memset(vis,true,sizeof(vis));
	for(int i=0;i<n;i++)
	{
		cin>>xi>>yi;
		dy=yi-y1;
		dx=xi-x1;
		slope=dy/dx;
		temp.insert(slope==neg_infinity?-slope:slope);
	}
	
	cout<<temp.size();

	
}