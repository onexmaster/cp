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
void solve(string s1, string t, string p)
{
	//we should have all the chars in s + p to make t 
		int freq[26]={};
		for(int i=0;i<s1.size();i++)
			freq[s1[i]-'a']++;
		for(int i=0;i<p.size();i++)
			freq[p[i]-'a']++;
		for(int i=0;i<t.size();i++)
			freq[t[i]-'a']--;
		for(int i=0;i<26;i++)
			if(freq[i]<0)
			{
				cout<<"No"<<endl;
				return;
			}
		int ind=0;
		//bool falg=false;

		//s should be a subsequnce of t
		for(int i=0;i<t.size();i++)
		{
			if(s1[ind]==t[i])
				ind++;
			if(ind==s1.size())
				{
					cout<<"yes"<<endl;
					return;
				}
		}
		cout<<"No"<<endl;
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
		string s1,t,p;
		cin>>s1>>t>>p;
		solve(s1,t,p);
		
	}
	
}