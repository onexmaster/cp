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
	int n[5]={0};
	while(t--)
	{
		string st1;
		cin>>st1;
		if(st1=="AC")
			n[0]++;
		else if(st1=="WA")
			n[1]++;
		else if(st1=="TLE")
			n[2]++;
		else if(st1=="RE")
			n[3]++;

	}
	cout<<"AC x "<<n[0]<<endl;
	cout<<"WA x "<<n[1]<<endl;
	cout<<"TLE x "<<n[2]<<endl;
	cout<<"RE x "<<n[3]<<endl;
	
}	