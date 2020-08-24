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

	int t;
	cin>>t;
	while(t--)
	{
		double n;
		cin>>n;
		if(n*n-4*n<0)
			cout<<"N"<<endl;
		else
		{
			cout<<"Y"<<" ";
			double val=n*n-4*n;
			cout<<fixed<<setprecision(9)<<(n+sqrt(val))/2.0<<" "<<(n-sqrt(val))/2.0<<endl;

		}
	}
	
}