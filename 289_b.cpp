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

int main()
{
	ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

	#ifndef ONLINE_JUDGE
	freopen("inputf.in","r",stdin);
	freopen("outputf.in","w",stdout);
	#endif

	int n,m,d;
	cin>>n>>m>>d;
	//int matrix[n][m];
	vector<int>v(n*m);
	for(int i=0;i<n*m;i++)
		cin>>v[i];
	sort(v.begin(),v.end());
	int middle=(n*m-1)/2;
	int count=0;
	for(int i=0;i<n*m;i++)
	{
		int diff=abs(v[middle]-v[i]);
		if(diff%d!=0)
		{
			cout<<-1;
			return 0;
		}
		else
		{
			count+=diff/d;
		}
	}
	cout<<count;
}