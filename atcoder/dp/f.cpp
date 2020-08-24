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
void generate(string S, int index, vector<string>&v,string curr)
{
	if(index==S.size())
		return;

	

	for(int i=index+1;i<S.size();i++)
	{	
	//choose
		curr+=S[i];
		v.push_back(curr);
	//explore
		generate(S,i,v,curr);
	//backtrack
		curr.pop_back();
	}
	return;
}
string bottomup(string &S, string &T)
{
	int dp[S.size()+1][T.size()+1];
	for(int i=0;i<=S.size();i++)
	{
		for(int j=0;j<=T.size();j++)
		{
			if(i==0 || j==0)
				dp[i][j]=0;
			else if(S[i-1]==T[j-1])
				//take the diagonal value and add one 
				dp[i][j]=dp[i-1][j-1]+1;
			else
				//take the max of upper and left
				dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
		}
	}
	//cout<<dp[S.size()][T.size()]<<endl;
	//generate the susbsequence 
	//This will generate the string in reverse
	string ans="";
	int i=S.size();
	int j=T.size();
	while(i>0 && j>0)
	{
		if(S[i-1]==T[j-1])
		{
			ans+=S[i-1];
			i--;
			j--;
		}
		else if(dp[i-1][j]>dp[i][j-1])
			i--;
		else 
			j--;
	}
	//Reverse the string to get the answer
	reverse(ans.begin(),ans.end());
	return ans;
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

	string S,T;
	cin>>S>>T;
	vector<string>v;
	string ans="";
	// Recursion Program

	/*
	generate(S,-1,v,ans);
	sort(v.begin(),v.end(),[](auto a ,auto b)
	{
		return a.size()>b.size();
	});
	ans="";
	vector<string>v2;
	generate(T,-1,v2,ans);
	unordered_set<string>st;
	for(string x:v2)
		st.insert(x);
	bool ok=false;
	for(int i=0;i<v.size();i++)
	{
		if(st.find(v[i])!=st.end())
		{
			cout<<v[i];
			ok=true;
			break;
		}
	}
	if(!ok)
		cout<<"";
	*/

	//Bottom up dp
	cout<<bottomup(S,T);
}