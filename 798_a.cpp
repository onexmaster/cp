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
	int l=0;
	int r=st.size()-1;
	bool ok=true;
	while(l<r)
	{
		if(st[l]!=st[r] && ok==true)
		{
			ok=false;
			l++;
			r--;
		}
		else if(st[l]!=st[r]&& ok==false)
		{
			cout<<"NO"; 
			return 0;
		}
		else{
			l++;
			r--;
		}
	}
	if((ok && st.size()%2!=0) || (!ok))
		cout<<"YES";
	else
		cout<<"NO";
	
}