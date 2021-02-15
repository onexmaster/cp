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
	if(n>k)
	{
		set<char>st;
		for(char c:s)
			st.insert(c);
		string res;
		char largest=*st.rbegin();
		//if the largest char is present at the k'th pos in s then we need to change
		//the string
		//else 
		//replcae the k'th char in res with the next larger char from set
		if(s[k-1]==largest)
		{
			//replace the first elemnt with the next bigger element
			res=s.substr(0,k);
			//cout<<res<<endl;
			int j=res.size()-1;
			while(res[j]==largest)
				j--;
			res=s.substr(0,j);
			char curr=s[j];
			char smallest=*st.begin();
			for(curr++;curr<='z';curr++)
			{
				if(st.find(curr)!=st.end())
				{
					res+=curr;
					break;
				}
			}
			while(int(res.size())<k)
				res+=smallest;
		}
		else
		{

			int i=0;
			while(i<k-1)
			{
				res+=s[i];
				i++;
			}
			char curr=s[i];
			for(curr++;curr<='z';curr++)
			{
				if(st.find(curr)!=st.end())
				{
					res+=curr;
					break;
				}
			}
			
		}
		cout<<res<<endl;
		//replace the last char from 
	}
	//i need to make a larger string
	else if(n<k)
	{
		set<char>st;
		for(char c:s)
			st.insert(c);
		string res=s;
		char smallest=*st.begin();
		while(int(res.size())<k)
			res+=smallest;
		cout<<res;
	}
	//if equal size
	else
	{
		set<char>st;
		for(char c:s)
			st.insert(c);
		char largest=*st.rbegin();
		string res;
		//get the last index where the largest char is present
		int j=n-1;
		while(s[j]==largest)
		{
			j--;
		}
		// if(j==1)
		// {
		// 	char curr=s[0];
		// 	for(curr++;curr<'z';curr++)
		// 	{
		// 		if(st.find(curr)!=st.end())
		// 		{
		// 			res+=curr;
		// 			break;
		// 		}
		// 	}
		// 	char smallest=*st.begin();
		// 	while(int(res.size())<k)
		// 		res+=smallest;
		// }
		//else
		//{
			//bbbaccc
			res=s.substr(0,j);
			char curr=s[j];
			char smallest=*st.begin();
			for(curr++;curr<='z';curr++)
			{
				if(st.find(curr)!=st.end())
				{
					res+=curr;
					break;
				}
			}
			while(int(res.size())<k)
				res+=smallest;
		//}
		cout<<res<<endl;
	}

}