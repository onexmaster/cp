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
unordered_set<int>fac;
bool prime(int x)
{
	for(int i=2;i<=sqrt(x);i++)
		if(x%i==0)
			return false;
	return true;
}
void get_factors(int x)
{
	while(x%2==0)
	{
		fac.insert(2);
		x=x/2;
	}
	for(int i=3;i<=sqrt(x);i+=2)
	{
		while(x%i==0)
		{
			fac.insert(i);
			x/=i;

		}
	}
	if(x>2)
		fac.insert(x);
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
	while(t--)
	{
		int x;
		cin>>x;
		if(x==1)
		{
			cout<<"FastestFinger"<<endl;
			continue;
		}
		if(x==2)
		{
			cout<<"Ashishgup"<<endl;
			continue;
		}
		if(x%2!=0)
		{
			cout<<"Ashishgup"<<endl;
			continue;
		}
		fac.clear();
		get_factors(x);
		if(fac.size()==1 && fac.count(2)!=0)
		{
			cout<<"FastestFinger"<<endl;
			continue;
		}

		x=x/2;
		if(prime(x))
		{
			cout<<"FastestFinger"<<endl;
		}
		else
			cout<<"Ashishgup"<<endl;

	}
	
}