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

	string a_s;
	cin>>a_s;
	string st;
	cin>>st;
	sort(st.begin(),st.end(),[] (auto a, auto b)
		{
			if(a>b)
				return true;
			else
				return false;
		});
	int i=0;
	int j=0;
	
	while(i<a_s.size() && j<st.size())
	{
		if(a_s[i]<st[j])
		{
			a_s[i]=st[j];
			i++;
			j++;
		}
		else
			i++;

	}
	cout<<a_s;
}