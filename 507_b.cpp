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
	ll r,start_x,start_y,end_x,end_y;
  cin>>r>>start_x>>start_y>>end_x>>end_y;
  if(start_x==end_x && start_y==end_y)
  {
  	cout<<0;
  	return 0;
  }
  r*=2;
   ll x=(start_x-end_x)*(start_x-end_x);
   ll y=(start_y-end_y)*(start_y-end_y);
   // cout<<sqrt(x+y)<<endl;
   double distance=sqrt(x+y);
   distance-=1e-12;
  ll res=distance/r;
  cout<<res+1<<endl;
	
}
