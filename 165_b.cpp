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

	int n,k;
	cin>>n>>k;
	int l=1;
	int h=n;
	int l_b=-1;
	while(l<=h)
	{
		int m=l+(h-l)/2;
		int count=m;
		int temp_k=k;
		//cout<<temp_k<<endl;
		while(m/temp_k>0)
		{
			//cout<<m/temp_k<<endl;
			count+=m/temp_k;
			temp_k*=k;
		}
		//cout<<m<<" "<<count<<endl;
		if(count>=n)
		{
			l_b=m;
			h=m-1;
		}
		else
		{
			l=m+1;
		}
	}
	cout<<l_b;
}