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

	//int t;
	//cin>>t;
	vector<int>v;
	for(int i=1;i<=10;i+=2)
		v.pb(i);
	for(int i=0;i<v.size();i++)
		cout<<v[i]<<" ";
	cout<<endl;
	int index=lower_bound(v.begin(),v.end(),5)-v.begin();
	cout<<v[index]<<endl;
	int index2=upper_bound(v.begin(),v.end(),5)-v.begin();
	cout<<v[index2]<<endl;
	int l=0;
	int h=v.size()-1;
	int index3=-1;
	while(l<=h)
	{
		int mid=l+(h-l)/2;
		if(v[mid]<=5)
		{
			index3=mid;
			l=mid+1;
		}
		else
			h=mid-1;
	}
	cout<<v[index3]<<endl;
	l=0;
	h=v.size()-1;
	int index4=-1;
	while(l<=h)
	{
		int mid=l+(h-l)/2;
		if(v[mid]>=5)
		{
			index4=mid;
			h=mid-1;
		}
		else
			l=mid+1;
	}
	
	cout<<v[index4];
	
}