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

	string start,end;
	 cin>>start>>end;
		int x1=start[0];
		int y1=start[1];
		//cout<<x<<" "<<y<<endl;
		int x2=end[0];
 		int y2=end[1];
 		vector<string> ans;
 		while(x1<x2 && y1<y2)
 		{
 			ans.pb("RU");
        	x1++;
        	y1++;
 		}
 		while (x1 < x2 && y1 > y2)
    {
        ans.pb("RD");
        x1++;
        y1--;
    }
    while (x1 > x2 && y1 < y2)
    {
        ans.pb("LU");
        x1--;
        y1++;
    }
    while (x1 > x2 && y1 > y2)
    {
        ans.pb("LD");
        x1--;
        y1--;
    }
    while (x1 < x2)
    {
        ans.pb("R");
        x1++;
    }
    while (x1 > x2)
    {
        ans.pb("L");
        x1--;
    }
    while (y1 < y2)
    {
        ans.pb("U");       
        y1++;
    }
    while (y1 > y2)
    {
        ans.pb("D");       
        y1--;
    }
 
    cout << ans.size() << endl;
    for(int i=0;i<ans.size();i++)
    	cout<<ans[i]<<endl;
 
}