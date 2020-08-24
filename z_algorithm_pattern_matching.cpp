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

	string text,pattern;
	cin>>text;
	cin>>pattern;
	int count=0;
	int p_size=pattern.size();
	string st=pattern+"$"+text;
	int z[st.size()+1];
	z[0]=0;
	int l=0;
	int r=0;
	for(int i=0;i<st.size();i++)
	{
		if(i>r)
		{
			l=r=i;
			while(r<st.size() && st[r-l]==st[r])
				r++;
			z[i]=r-l;
			r--;
		}
		else
		{
			int k=i-l;
			if(z[k]<r-i+1)
			{
				z[i]=z[k];
			}
			else
			{
				l=r;
				while(r<st.size() && st[r-l]==st[r])
					r++;
				z[i]=r-l;
				r--;
			}

		}
	}
	for(int i=0;i<st.size();i++)
	{
		if(z[i]==p_size)
		{
			count++;
		}
	}
	cout<<count;
}