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
	while(t--)
	{	
		int n;
		cin>>n;
		vector<int>v(n);
		for(int i=0;i<n;i++)
			cin>>v[i];
		int colors[n+1]={0};
	map<int,int>col;
	set<int>primes{2,3,5,7,11,13,17,19,23,29,31};
	set<int>used_col;
	int max_col=-1;
	int curr_col=1;
	for(int i=0;i<n;i++)
	{
		for(auto it:primes)
		{
			if(v[i]%it==0)
			{
				//cout<<curr_col<<endl;
				if(col.count(it)==0)
				{
					col[it]=curr_col  ;
					colors[i]=curr_col;
					curr_col++;
					max_col=max(max_col,colors[i]);
					used_col.insert(colors[i]);
					break;
				}
				else
				{
					colors[i]=col[it];
					break;
				}
			}
			
		}
	}
	// for(int i=0;i<n;i++)
	// {
	// 	if(colors[i]==0)
	// 	{
	// 		for(int j=1;j<=11;j++)
	// 		{
	// 			if(used_col.find(j)==used_col.end())
	// 			{
	// 				colors[i]=j;
	// 				used_col.insert(j);
	// 				max_col=max(max_col,colors[i]);
	// 			}
	// 		}
	// 	}
	// }
	cout<<max_col<<endl;
	for(int i=0;i<n;i++)
		cout<<colors[i]<<" ";
	cout<<endl;

	
}
}