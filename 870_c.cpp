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

void solve(int n)
{
	if(n%4==0)
	{
		cout<<n/4<<endl;
		return;
	}
	else if(n%4==1)
	{
		if(n<9)
		{
			cout<<-1<<endl;
			return;
		}
		else
		{
			cout<< 1+((n-9)/4)<<endl;
			return;
		}
		
	}
	else if(n%4==2)
	{
		if(n<6)
		{
			cout<<-1<<endl;
			return;
		}
		else
		{
		cout<<1+((n-6)/4)<<endl;
		return;
		}
		
	}
	else if(n%4==3)
	{
		if(n<15)
		{
			cout<<-1<<endl;
			return;
		}
		else
		{
			cout<<2+((n-15)/4)<<endl;
			return;
		}
		
	}
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
		int n;
		cin>>n;
		solve(n);
	}
	
}