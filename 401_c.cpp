// Created by Tanuj Jain
//TLE ON CODEFORCES
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
int main()
{
	ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

	#ifndef ONLINE_JUDGE
	freopen("inputf.in","r",stdin);
	freopen("outputf.in","w",stdout);
	#endif

	int zero,one;
	cin>>zero>>one;
	string ans="";
	while(zero>0 && one>=2)
	{
		ans+="101";
		zero-=1;
		one-=2;
	}
	cout<<zero<<" "<<one<<endl;
	if(one>2)
	{
		cout<<-1;
		return 0;
	}
	if(one==1)
		ans+="1";
	if(one==2)
	{
		ans+="1";
		ans="1"+ans;
	}
	for(int i=0;i<ans.size();i++)
	{
		if(zero==0)
			break;
		if(ans[i]=='1' && ans[i+1]=='1')
		{
			ans.insert(ans.begin()+i+1,1,'0');
			zero--;
		}

	}

	if(zero==1)
	{
		ans+="0";
		zero--;
	}
	if(zero==2)
	{
		ans+="0";
		ans="0"+ans;
		zero-=2;
	}
	if(zero>0)
	{
		cout<<-1;
		return 0;
	}
	// // int a=0;
	// // int b=0;
	// // for(int i=0;i<ans.size();i++)
	// // 	if(ans[i]=='0')
	// // 		a++;
	// // 	else
	// // 		b++;
	// // 	cout<<a<<" "<<b<<endl;

	cout<<ans;


}