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
	string st=to_string(t);
	if(st[st.size()-1]=='2'||st[st.size()-1]=='4'||st[st.size()-1]=='5'||st[st.size()-1]=='7'||st[st.size()-1]=='9')
			{
				cout<<"hon";
				return 0;
			}
	else if(st[st.size()-1]=='0'||st[st.size()-1]=='1'||st[st.size()-1]=='6'||st[st.size()-1]=='8')
	{
		cout<<"pon";
		return 0;
	}
	else
	{
		cout<<"bon";
		return 0;
	}
	
}