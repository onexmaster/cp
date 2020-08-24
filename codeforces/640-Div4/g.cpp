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
		int x;
		cin>>x;
		bool ok=true;
		if(x<4)
		{
			cout<<-1<<endl;
			ok=false;
		}
		if(ok){
		vector<int>even,odd;
		for(int i=1;i<=x;i++)
			if(i&1==1)
				odd.pb(i);
			else
				even.pb(i);
		vector<int>ans;
		for(int i=0;i<even.size();i++)
			ans.pb(even[i]);
		if(x&1==1)
		{
			ans.pb(odd[odd.size()-3]);
			odd.erase(odd.end()-3);
			for(int i=odd.size()-1;i>=0;i--)
			{

				ans.pb(odd[i]);
			}
		}
		else
		{
		ans.pb(odd[odd.size()-2]);
		ans.pb(odd[odd.size()-1]);
		if(odd.size()>=3){
			for(int i=odd.size()-3;i>=0;i--)
			ans.pb(odd[i]);	
		}
		}
		for(int i=0;i<ans.size();i++)
			cout<<ans[i]<<" ";
		cout<<endl;
	}

	}
	
}