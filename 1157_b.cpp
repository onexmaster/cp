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
	string s;
	cin>>s;
	vector<char>v(10);
	for(int i=0;i<9;i++)
		cin>>v[i];
	unordered_map<char,char>m;
	for(int i=0;i<9;i++)
		m.insert({('0'+i+1),v[i]});
	int l=t;
	//find the first smallest number from the right side that can be changed
	for(int i=0;i<t;i++)
		if(m[s[i]]>s[i])
		{
			l=i;
			break;
		}
	//find the right boundary of this segment and go on changing the numbers in between
		for(int i=l;i<t;i++)
		{
			if(m[s[i]]<s[i])
				break;
			s[i]=m[s[i]];
		}
		cout<<s;



	
}