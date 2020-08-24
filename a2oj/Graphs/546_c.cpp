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

	int t;
	cin>>t;
	int n;
	cin>>n;
	vector<int>a;
	for(int i=0;i<n;i++)
		{
			int x;
			cin>>x;
			a.pb(x);
		}
	int m;
	cin>>m;
	vector<int>b;
	for(int i=0;i<m;i++)
		{
			int x;
			cin>>x;
			b.pb(x);
		}
	set<vector<int>>a_set;
	set<vector<int>>b_set;
	a_set.insert(a);
	b_set.insert(b);
	bool ok=true;
	int count=0;
	while(!a.empty() && !b.empty())
	{
		if(a[0]>b[0])
		{
			int top=a[0];
			a.erase(a.begin());
			a.insert(a.end(),b[0]);
			a.insert(a.end(),top);
			b.erase(b.begin());
		}
		else
		{
			int top=b[0];
			b.erase(b.begin());
			b.insert(b.end(),a[0]);
			b.insert(b.end(),top);
			a.erase(a.begin());
		}
		if(a_set.find(a)!=a_set.end() && b_set.find(b)!=b_set.end())
		{
			ok=false;
			break;
		}
		else
		{
			a_set.insert(a);
			b_set.insert(b);
			count++;
		}
	}
	if(!ok)
		cout<<-1;
	else
	{
		cout<<count<<" ";
		if(a.size()>b.size())
			cout<<1;
		else
			cout<<2;
	}
	
}