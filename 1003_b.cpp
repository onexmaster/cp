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
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	#endif

	int a,b,x;
	cin>>a>>b>>x;
	string s="01";
	x--;
	a--;
	b--;
	while(x)
	{
		if(s[int(s.size()-1)]=='1')
			s+="10";
		else
			s+="01";
		x--;
		a--;
		b--;
	}
	if(x==0 && a==0 && b==0)
	{
		cout<<s;
		return 0;
	}
	string temp;
	string ans;
	if(a>0)
		temp.append(a,'0');
	temp+=s;
	//cout<<temp<<endl;
	if(b>0)
	{
		bool ok=false;
		if(temp[int(temp.size())-1]=='1')
			temp.append(b,'1'),ok=true;
		else
		{
			string temp1;
			temp1.append(b,'1');
			for(int i=0;i<temp.size()-1;i++)
			{
				if(s[i]=='1' && s[i+1]=='1')
				 ans=temp.substr(0,i)+temp1+temp.substr(i+1);
			}
		}
		if(ok)
			cout<<temp;
		else
			cout<<ans;		
	}
	return 0;
}