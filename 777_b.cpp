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
	//cin>>t;
	t=1;
	while(t--)
	{
		int n;
		cin>>n;
		string s1,s2;
		cin>>s1>>s2;
		sort(s1.begin(),s1.end());
		sort(s2.begin(),s2.end());
		int m_f=n;
		int s_f=0;
		int pos1=0;
		int pos2=0;
		//int n=s1.size();
		while(pos1<n && pos2<n)
		{
			if(s1[pos1]<=s2[pos2])
			{
				m_f--;
				pos1++;
				pos2++;
			}
			else
				pos2++;
		}
		pos1=0;
		pos2=0;
		while(pos1<n && pos2<n)
		{
			if(s1[pos1]<s2[pos2])
			{
				s_f++;
				pos1++;
				pos2++;

			}
			else
				pos2++;
		}
		cout<<m_f<<"\n"<<s_f<<"\n";
	}
	
}