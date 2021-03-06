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
		int n,m;
		cin>>n>>m;
		int ctime=0,lo=m,hi=m;
		bool ok=true;
		for(int i=0;i<n;i++)
		{
			int t,l,h;
			cin>>t>>l>>h;
			int diff=t-ctime;
			lo-=diff;
			hi+=diff;
			ctime=t;
			lo=max(lo,l);
			hi=min(hi,h);
			if(lo>hi)
				ok=false;

		}
		if(ok)
			cout<<"YES"<<endl;
		else
			cout<<"NO"<<endl;
	}
	
}