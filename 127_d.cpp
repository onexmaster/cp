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

	string st;
	cin>>st;
	int n=st.size();
	int array[n];
	array[0]=0;
	int l=0;
	int r=0;

	for(int z=1;z<n;z++)
	{ 
		//case 1 z>r use brute force
		if(z>r)
		{
			l=r=z;
			while(r<n && st[r-l]==st[r])
				r++;
			array[z]=r-l;
			r--;
		}
		//case 2 z<r
		else
		{
			int k=z-l;
			//array[k] does not extend the right bound
			if(array[k]<r-z+1)
				//use the value directly
				array[z]=array[k];
			else
			{
				//if array[k] exceeds the right bound
				l=z;
				while(r<n && st[r-l]==st[r])
					r++;
				array[z]=r-l;
				r--;
			}

		}
	}
	int ans=0;
	int mx=-1;
	for(int i=0;i<n;i++)
	{
		if(array[i]==n-i && mx>=n-i) 
		{
			ans=n-i;
			break;
		}
		mx=max(mx,array[i]);
	}
	if(ans==0)
	{  
		cout<<"Just a legend";
		return 0;
	}
	else
	{
		cout<<st.substr(0,ans);
		return 0;
	}
}