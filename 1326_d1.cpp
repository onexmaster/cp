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
const int INF = 0x3f3f3f3f;
int knight_moves[8][2]={{-2,-1},{-1,-2},{1,-2},{2,-1},{-2,1},{-1,2},{1,2},{2,1}};
int moves[4][2]={{0,1},{0,-1},{1,0},{-1,0}};
struct custom_hash {
    static uint64_t splitmix64(uint64_t x) {
        // http://xorshift.di.unimi.it/splitmix64.c
        x += 0x9e3779b97f4a7c15;
        x = (x ^ (x >> 30)) * 0xbf58476d1ce4e5b9;
        x = (x ^ (x >> 27)) * 0x94d049bb133111eb;
        return x ^ (x >> 31);
    }

    size_t operator()(uint64_t x) const {
        static const uint64_t FIXED_RANDOM = chrono::steady_clock::now().time_since_epoch().count();
        return splitmix64(x + FIXED_RANDOM);
    }
};
vector<ll>z_algo(string t,string p)
{
	string f=t+"$"+p;
	//cout<<f<<endl;
	ll n=f.size();
	vector<ll>z(n);
	z[0]=0;
	ll l,r;
	l=r=0;
	for(ll i=1;i<n;i++)
	{
		if(i>r)
		{
			l=r=i;
			while(r<n && f[r-l]==f[r])
				r++;
			z[i]=r-l;
			r--;
		}
		else
		{
			ll k=i-l;
			if(z[k]<r-i+1)
				z[i]=z[k];
			else
			{
				l=i;
				while(r<n && f[r-l]==f[r])
					r++;
				z[i]=r-l;
				r--;
			}
		}
	}
	return z;

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
		string st;
		cin>>st;
		int l=0;
		int r=st.size()-1;
		int max_len=0;
		//find the longest prefix and sufficx in the string that are same
		while(l<r)
		{
			if(st[l]==st[r])
			{
				l++;
				r--;
				max_len++;
			}
			else
				break;
		}
		//remove the matched string from the og string as it belongs in the answer
		//i.e first half + "lps" + second
		//find lps using z array;
		string s1=st.substr(l,r-l+1);
		//cout<<s1<<endl;
		//find the largest suffix which is also a prefix in s1+rev(s1)
		string s1r=s1;
		reverse(s1r.begin(),s1r.end());
		vector<ll>z1=z_algo(s1,s1r);
		int len1=0;
		string temp1=s1+"$"+s1r;
		//cout<<temp1<<endl;
		int idx1=0;
		//check the z array
		//for(int i=0;i<z1.size();i++)
		//	cout<<z1[i]<<" ";
		//cout<<endl;
		for(int i=0;i<z1.size();i++)
		{
			//tells suffix is equals to the prefix
			if(i+z1[i]==2*s1.length()+1)
			{
				if(z1[i]>len1)
				{
					idx1=i;
					len1=z1[i];
				}
			}
		}
		//find the largest suffix which is also a prefix in rev(s1)+s1
		string temp2=s1r+"$"+s1;
		vector<ll>z2=z_algo(s1r,s1);
		int len2=0;
		int idx2=0;
		//check the z array
		//for(int i=0;i<z2.size();i++)
		//	cout<<z2[i]<<" ";
		//cout<<endl;
		
		for(int i=0;i<z2.size();i++)
		{
			//tells suffix is equals to the prefix
			if(i+z2[i]==2*s1.length()+1)
			{
				if(z2[i]>len2)
				{
					idx2=i;
					len2=z2[i];
				}
			}
		}
		//cout<<len1<<" "<<len2<<endl;
		//build the answer
		string ans="";
		//insert the suffix we got first
		for(int i=0;i<max_len;i++)
			ans+=st[i];
		//now insert the lps we got 
		if(len1>=len2)
		{
			for(int i=idx1;i<idx1+len1;i++)
				ans+=temp1[i];
		}
		else
		{
			for(int i=idx2;i<idx2+len2;i++)
				ans+=temp2[i];
		}
		//now insert the prefix which is rev(suffix);
		for(int i=max_len-1;i>=0;i--)
			ans+=st[i];
		cout<<ans<<endl;
//method - 2
// Summary

// Find the longest matching prefix and suffix, where suffix = palindrome(prefix)
// Find the longest inner substring that is a palindrome and touches the prefix or suffix (or both)
// Combine these as final answer
// Steps

// From both ends of the string, find a prefix and suffix that are mutual palindromes. Store that for the final answer
// Strip off these matching prefix and suffix (if any) so you're left with just the inner string
// Run Manacher's algorithm on the inner string
// Using the output from step 3, find the max value (i.e. max palindrome length in inner string) that touches the prefix or the suffix (or both).
// Return [prefix] + [longest internal palindrome that touches either prefix or suffix] + [suffix]
// Manacher's Algorithm

}

}