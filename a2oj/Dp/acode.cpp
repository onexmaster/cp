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



vector<ll> dp(5005);
vector<bool> vis(5005);
ll recursive(string &t, int pos)
{
	//cout<<pos<<endl;
	if(pos<=0)
		return 1;
	//get the answer from children
	if(vis[pos])
		return dp[pos];
	vis[pos]=true;
	ll temp1=0;
	ll temp2=0;
		//if(vis[pos-1])
		//	temp1=dp[pos-1];
	if(t[pos]!='0')
	{
			temp1 = recursive(t,pos-1);
	}
	if(t[pos-1]=='1' || (t[pos-1]=='2' && t[pos]<='6'))
	{
			temp2 = recursive(t,pos-2);
	}
	return dp[pos]=temp1+temp2;


}

/*
ll bottomup(string &t)
{
	ll dp1[t.size()+1]={};
	dp1[0]=1;
	dp1[1]=1;
	for(int i=2;i<=t.size();i++)
	{
		char c1=t[i-2], c2=t[i-1];
		if(c1=='1' || (c1=='2' && c2<='6'))
			dp1[i]+=dp1[i-2];
		if(c2!='0')
			dp1[i]+=dp1[i-1];
	}
	return dp1[t.size()];
}
*/
int main()
{
	ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

	#ifndef ONLINE_JUDGE
	freopen("inputf.in","r",stdin);
	freopen("outputf.in","w",stdout);
	#endif

	ll dp1[5001]={};
	string t;
	while(true)
	{
		
		cin>>t;
		if(t[0]=='0')
			break;
		else
		{
			//cout<<recursive(t,t.size()-1);	
			/*
			dp1[0]=1;
			dp1[1]=1;
		for(int i=2;i<=t.size();i++)
		{
			dp1[i]=0;
			char c1=t[i-2], c2=t[i-1];
			if(c1=='1' || (c1=='2' && c2<='6'))
				dp1[i]+=dp1[i-2];
			if(c2!='0')
				dp1[i]+=dp1[i-1];
		}
			cout<<dp1[t.size()]<<endl;
		*/
			alloc();
			cout<<recursive(t,t.size()-1)<<endl;
		}
			
	}
	
}