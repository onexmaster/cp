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

	int n;
	cin>>n;
	vector<int>v(n);
	for(int i=0;i<n;i++)
		cin>>v[i];
	multiset<int>m;
	m.insert(v[0]);
	int ans=1;
	int l=0;
	int h=0;
	while(h<n-1)
	{
		h++;
		m.insert(v[h]);
		if(*m.rbegin() - *m.begin()<=1)
		{
			ans=max(ans,h-l+1);
		}
		else
		{
			while(*m.rbegin()-*m.begin()>1)
			{
				m.erase(m.find(v[l]));
				l++;
			}
			ans=max(ans,h-l+1);
		}
	}
	cout<<ans;
	
}