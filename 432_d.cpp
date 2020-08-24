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
	vector<int>array(n);
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
	}vector<pii>res;
	vector<int>z_sort(n);
	for(int i=0;i<n;i++)
		z_sort[i]=array[i];
	sort(z_sort.begin(),z_sort.end());
	for(int i=1;i<n;i++)
	{
		if(array[i]==n-i)//ans found
		{
			int cnt=(z_sort.end()-(lower_bound(z_sort.begin(),z_sort.end(),array[i])))+1;
			res.pb(mp(n-i,cnt));
		}
		
	}
	res.pb(mp(n,1));
	sort(res.begin(),res.end(),[](auto a, auto b){
		if(a.second>b.second)
			return true;
		else
			return false;
	});
	cout<<res.size()<<endl;
	for(int i=0;i<res.size();i++)
		cout<<res[i].first<<" "<<res[i].second<<endl;


	
}