//Does not work
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
		int n,s;
		cin>>n>>s;
		vector<int>v(n);
		int su=0;
		bool flag=false;
		for(int i=0;i<n;i++)
		{
			cin>>v[i];
			su+=v[i];
		}
		if(su<=s)
		{
			cout<<0;
			flag=true;
		}
		//cout<<su;
		int u=-1;
		if(!flag)
		{
			int l=0;
			int h=n;
			
			while(l<=h)
			{
				int m=l+(h-l)/2;
				int sum=0;
				for(int i=0;i<m;i++)
					sum+=v[i];
				if(sum>s)
					h=m-1;
				else
				{
					u=l;
					l=m+1;
				}

			}
			cout<<u<<endl;
			
		}
		
		
	}
	
}