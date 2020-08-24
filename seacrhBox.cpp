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

int z(string final_text, string pattern, string full_word, int start_pos)
{
	string final=pattern+"$"+final_text;
	int n=final.length();
	int z_values[n];
	z_values[0]=0;
	int l=0;
	int r=0;
	for(int i=1;i<n;i++)
	{
		//case 1
		if(i>r)
		{
			l=r=i;
			while(r<n && final[r-l]==final[r])
				r++;
			z_values[i]=r-l;
			r--;
		}
		else
		{
			int k=i-l;
			if(z_values[k]<r-i+1)
				z_values[i]=z_values[k];
			else
			{
				l=i;
				while(r<n && final[l-i]==final[r])
					r++;
				z_values[i]=r-l;
				r--;
			}
		}
	}
	for(int i=pattern.length()+start_pos;i<n;i++)
	{
		if(z_values[i]==pattern.size() && full_word=="Y")
		{
			if(i-(pattern.length()+1)==0 || z_values[i]+i==final_text.length()-1 || final[i-1]=='@' || final[i+1]=='@')
			{
				return i-(pattern.length()+1);
			}
			else
				return -1;
		}
		else if((z_values[i]==pattern.size() && full_word=="N"))
		{
			cout<<i<<endl;
			return i-(pattern.length()+1     );
		}
	}
	return -1;
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

	string text,pattern;
	getline(cin,text);
	cin>>pattern;
	string full_word;
	cin>>full_word;
	int start_pos;
	cin>>start_pos;
	stringstream ss(text);
 	string word;
 	string final_text="";
 	//@ means space
 	while(ss>>word)
 	{
 		final_text.insert(final_text.length(),word);
 		final_text.insert(final_text.end(),1,'@');
 	}
 	cout<<z(final_text,pattern,full_word,start_pos);
	
}