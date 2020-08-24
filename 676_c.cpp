
/*https://www.geeksforgeeks.org/maximum-length-substring-having-all-same-characters-after-k-changes/
I'll explain C using the example: "abbaa" , k = 1

First, find out how many consecutive a's are possible in "abbaa" if we can swap no more than one 'b':

We're going to have "pointerLeft" and "pointerRight" describing the substring we're looking at during the execution. Both pointers start from -1.

pointerRight++ 
-> "a" possible
pointerRight++;
-> "ab" possible by swapping 1 b
pointerRight++;
-> "abb" not possible, we cant swap 2 b's
pointerLeft++;
-> "bb" not possible
pointerLeft++;
-> "b" possible by swapping 1 b
pointerRight++;
-> "ba" possible by swapping 1 b
pointerRight++;
-> "baa" possible by swapping 1b, also the longest possible substring so far
We have now looked into all relevant substrings of consecutive a's. Next we would do the same thing for consecutive b's.
*/
#include<bits/stdc++.h>
using namespace std;
#define pb push_back
#define mp make_pair
typedef long long ll;
typedef pair<int,int> pii;


int main()
{
	ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

	#ifndef ONLINE_JUDGE
	freopen("inputf.in","r",stdin);
	freopen("outputf.in","w",stdout);
	#endif

	int n,k;
	cin>>n>>k;
	string s;
	cin>>s;
	int mx_a=1;
	int mx_b=1;
	int cnt=0;
	int l=0;
	int r=0;
	//for a
	while(r<n)
	{
		if(s[r]!='a')
			cnt++;
		while(cnt>k)
		{
			if(s[l]!='a')
				--cnt;
			l++;
		}
		mx_a=max(mx_a,r-l+1);
		r++;
	}
	//for b
	cnt=0;
	l=0;
	r=0;
	while(r<n)
	{
		if(s[r]!='b')
			cnt++;
		while(cnt>k)
		{
			if(s[l]!='b')
				--cnt;
			l++;
		}
		mx_b=max(mx_b,r-l+1);
		r++;
	}
	cout<<max(mx_a,mx_b);

	
}