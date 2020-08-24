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
const int MAXN=25;
set<pii>vis;
int row, col;
string st1,st2;
pair<int,int>get(int x, int y, char direction)
{
	//cout<<x<<" "<<y<<" "<<direction<<endl;
	if(direction=='<')
		return {x,y-1};
	if(direction=='>')
		return {x,y+1};
	if(direction=='^')
		return {x-1,y};
	else
		return {x+1,y};
}
void dfs(int x, int y)
{
	//cout<<x<<" "<<y<<endl;
	vis.insert({x,y});
	char dir1=st1[x];
	char dir2=st2[y];
	//for first direction
	pair<int,int>new_cor=get(x,y,dir1);
	int tox=new_cor.first;
	int toy=new_cor.second;
	if(tox>=0 && tox<row && toy>=0 && toy<col && vis.find({tox,toy})==vis.end())
		dfs(tox,toy);
	new_cor=get(x,y,dir2);
	tox=new_cor.first;
	toy=new_cor.second;
	if(tox>=0 && tox<row && toy>=0 && toy<col && vis.find({tox,toy})==vis.end())
		dfs(tox,toy);
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

	cin>>row>>col;
	cin>>st1>>st2;
	int total=row*col;
	//memset(vis,false,sizeof(vis));
	for(int i=0;i<row;i++)
	{
		for(int j=0;j<col;j++)
		{
			dfs(i,j);
			if(vis.size()!=total)
			{
				cout<<"NO";
				return 0;
			}
		}
		vis.clear();
	}
	cout<<"YES";


	
}