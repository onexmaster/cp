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

bool check(string temp_build, string b)
{
	int p1=0;
	int p2=0;
	while(p1<temp_build.size() && p2<b.size())
	{
		if(b[p2]==temp_build[p1])
		{
			p2++;
			p1++;
		}
		else
			p1++;
	}
	if(p1==temp_build.size() && p2!=b.size())
		return false;
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

	string a,b;
	cin>>a>>b;
	vector<int>v;
	int input;
	while(cin>>input)
		v.pb(input);
	int l=0;
	int h=v.size()-1;
	int u=-1;
	while(l<=h)
	{
		int m=l+(h-l)/2;
		string temp_a=a;
		for(int i=0;i<m;i++)
			temp_a.replace(v[i]-1,1,"1");
		//build a new string
	
		string temp_build;
		for(int i=0;i<a.size();i++)
			if(temp_a[i]!='1')
				temp_build+=temp_a[i];
		//cout<<m<<" "<<temp_build<<endl;
		if(check(temp_build,b)==false)
			h=m-1;
		else
		{
			u=m;
			l=m+1;
		}

	}
	cout<<u;
}