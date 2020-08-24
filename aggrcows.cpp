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

bool poss(vector<int>&v,int dis,int cows)
{
	int prev=v[0];
	int c=1;
	for(int i=1;i<v.size();i++)
	{
		if(v[i]-prev>=dis)
		{
			c++;
			prev=v[i];
		}
		if(c==cows)
			return true;
		
	}
	return false;
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
		int n,cows;
		cin>>n>>cows;
		vector<int>v(n);
		for(int i=0;i<n;i++)
			cin>>v[i];
		sort(v.begin(),v.end());
		int l=0;
		int h=v[v.size()-1];
		int ans=-1;
		while(l<=h)
		{
			int mid=l+(h-l)/2;
			if(poss(v,mid,cows))
			{
				ans=mid;
				l=mid+1;
			}
			else
				h=mid-1;
		}
		cout<<ans<<endl;

	}
	
}