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

int fact(int x)
{
	int i,j=1;
	for(i=1;i<=x;i++)
		j*=i;
	return j;
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

	string s1,s2;
	cin>>s1>>s2;
	//int final_pos=0;
	int p_c=0;
	int n_c=0;
	int m_c=0;
	for(int i=0;i<s1.size();i++)
	{
		if(s1[i]=='+')
			p_c++;
		else
			n_c++;
	}
	int final_pos=p_c-n_c;
	for(int i=0;i<s2.size();i++)
	{
		if(s2[i]=='+')
			p_c--;
		else if(s2[i]=='-')
			n_c--;
		else
			m_c++;
	}
	double ans=0.0;
	if(p_c<0 || n_c<0)
		ans=0.0;
	else if(p_c+n_c>m_c)
		ans=0.0;
	else
	{
		double num=(fact(p_c+n_c))/(fact(p_c)*fact(n_c));
		double den=pow(2.0,m_c);
		ans=num/den;
	}
	cout<<fixed<<setprecision(12)<<ans;

}