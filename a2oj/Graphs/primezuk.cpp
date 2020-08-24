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
int largest_prime(int n)
{
	int max_prime=-1;
	while(n%2==0)
	{
		max_prime=2;
		n>>=1;
	}
	for(int i=3;i<=sqrt(n);i+=2)
	{
		while(n%i==0)
		{
			max_prime=i;
			n=n/i;
		}
	}
	if(n>2)
		max_prime=n;
	return max_prime;	
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

	int t;
	cin>>t;
	int x=1;
	while(t--)
	{
		int n;
		cin>>n;
		int mul=1;
		for(int i=0;i<n;i++)
		{
			int x;
			cin>>x;
			mul*=x;
		}
		mul++;
		cout<<"Case "<<"#"<<x<<": "<<largest_prime(mul)<<endl;
		x++;
	}
	
	
}