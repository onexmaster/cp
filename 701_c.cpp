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
bool poss(int sz,vector<int>&s, string st)
{
	//slding window of size sz and check if all the char are present or nor
	//cout<<sz<<endl;
	vector<int>freq(128,0);
	for(int i=0;i<sz;i++)
		freq[int(st[i])]++;
	int l=0;
	int r=sz;
	while(r<int(st.size()))
	{
		bool ok=true;
		for(int i=0;i<128;i++)
		{
			if(s[i]>0 && freq[i]==0)
			{
				ok=false;
				break;
			}
		}
		if(ok)
			return true;
		--freq[int(st[l])];
		l++;
		++freq[int(st[r])];
		r++;
	}
	bool ok=true;
	for(int i=0;i<128;i++)
		if(s[i]>0 && freq[i]==0)
			ok=false;
	if(!ok)
		return false;
	else
		return true;
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
	string st;
	cin>>st;
	//Binary search answer works Time :O(nlogn), but we can do better
	// vector<int>s(128,0);
	// for(int i=0;i<t;i++)
	// 	s[int(st[i])]++;
	// int l=0;
	// int h=t;
	// int ans=-1;
	// while(l<=h)
	// {
	// 	int mid=l+(h-l)/2;
	// 	if(poss(mid,s,st))
	// 	{
	// 		ans=mid;
	// 		h=mid-1;
	// 	}
	// 	else
	// 		l=mid+1;
	// }
	// cout<<ans;
	// return 0;
	set<char>freq;
	for(int i=0;i<t;i++)
		freq.insert(st[i]);
	int l=0;
	//map for runnig chars
	map<char,int>temp;
	set<char>comp;
	int ans=INT_MAX;
	for(int r=0;r<t;r++)
	{
		temp[st[r]]++;
		comp.insert(st[r]);
		
		//try to shirnk the size if we got all the chars 
		if(comp==freq)
		{
			//for(auto it:temp)
			//	cout<<it.first<<" "<<it.second<<endl;
			//cout<<st[l]<<" "<<temp[st[l]]<<endl;
			while(temp[st[l]]>1)
			{
				if(temp[st[l]]>1)
					--temp[st[l]];
				l++;
			}
			ans=min(ans,r-l+1);
		}

		
	}
	cout<<ans;
	return 0;
	}
