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
		int n;
		cin>>n;
		if(n/2&1==1)
			cout<<"NO"<<endl;
		else
		{
			vector<int>temp;
			int sum=0;
			for(int i=2;i<=n;i+=2)
			{
				sum+=i;
				temp.pb(i);
			}
			for(int i=1;i<n-1;i+=2)
			{
				sum-=i;
				temp.pb(i);
			}
			temp.pb(sum);
			cout<<"YES"<<endl;
			for(int i=0;i<n;i++)
				cout<<temp[i]<<" ";
			cout<<endl;
		}
	}
	
}