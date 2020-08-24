//Does Not Work
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
	string st;
	cin>>st;
	set<char>s(st.begin(),st.end());
	unordered_map<char,vector<int>>occ;
	for(int i=0;i<t;i++)
	{
		occ[st[i]].pb(i);
	}
	vector<int>len(t);
	bool flag=false;
	for(int i=0;i<t;i++)
	{
		s.erase(st[i]);
		int mx=-1;
		for(auto it:st)
		{
			vector<int>temp=occ[it];
			flag=false;
			for(int j=0;j<temp.size();j++)
			{
				if(temp[j]>i)
				{
					mx=max(mx,temp[j]);
					flag=true;
					break;
				}
			}
				if(!flag)
				{
					len[i]=1e5;
					break;
				}
			}
			if(flag)
			{
				len[i]=(mx-i+1);
			}
			s.insert(st[i]);

		}
		for(int i=0;i<t;i++)
			cout<<len[i]<<" ";
	}
